#include "minishell.h"

static int	is_builtin(char *str)
{
	int	size;

	size = ft_strlen(str) + 1;
	if (!ft_strncmp(str, "echo", size))
		return (ECHO);
	if (!ft_strncmp(str, "cd", size))
		return (CD);
	if (!ft_strncmp(str, "pwd", size))
		return (PWD);
	if (!ft_strncmp(str, "export", size))
		return (EXPORT);
	if (!ft_strncmp(str, "unset", size))
		return (UNSET);
	if (!ft_strncmp(str, "env", size))
		return (ENV);
	if (!ft_strncmp(str, "exit", size))
		return (EXIT);
	return (0);
}

static void	do_builtin(t_plot *plot, t_param *param, int builtin, int isfork)
{
	char	**tmp;

	tmp = convert_env_strs(param->env);
	if (builtin == ECHO)
		g_return = echo(plot->argc, plot->cmd_arg);
	else if (builtin == CD)
		g_return = cd(plot->argc, plot->cmd_arg, param);
	else if (builtin == PWD)
		g_return = pwd();
	else if (builtin == EXPORT)
		g_return = ft_export(plot->argc, plot->cmd_arg, param);
	else if (builtin == UNSET)
		g_return = unset(plot->argc, plot->cmd_arg, param);
	else if (builtin == ENV)
		g_return = env(plot->argc, plot->cmd_arg, tmp);
	ft_free_strs(tmp);
	if (builtin == EXIT)
		ft_exit(plot->argc, plot->cmd_arg, param, isfork);
	if (isfork)
		exit_program(param);
}

static void	close_other_plot(t_plot *actual, t_plot *start)
{
	while (start != NULL)
	{
		if (start != actual && start->fd_heredoc[0] != -1)
		{
			close(start->fd_heredoc[0]);
			start->fd_heredoc[0] = -1;
		}
		start = start->next;
	}
}

int	preparation_fork(t_param *param, int builtin)
{
	int		i;
	int		stateredir;
	char	*path;
	t_plot	*tmp_head;

	tmp_head = param->plots;
	i = 0;
	while (tmp_head)
	{
		builtin = is_builtin(tmp_head->cmd_arg[0]);
		if (init_pipe(i, param->child))
			return (1);
		signal(SIGINT, sig_child);
		signal(SIGQUIT, sig_child);
		path = file_is_exe(tmp_head->cmd_arg[0], param->paths);
		stateredir = check_open_redir(tmp_head->redir);
		if (!stateredir && (path || builtin))
		{
			param->child->pid[i] = fork();
			if (param->child->pid[i] == 0)
			{
				dup_pipe(tmp_head, param->child, i);
				close_pipe(param->child, i);
				init_redir(tmp_head);
				close_other_plot(tmp_head, param->plots);
				if (builtin)
				{
					free(path);
					do_builtin(tmp_head, param, builtin, 1);
				}
				else
				{
					// force_close_fd();
					do_execve(tmp_head, param, i, path);
				}
			}
			else if (tmp_head->fd_heredoc[0] != -1)
				close_heredoc_fd(tmp_head);
			free(path);
		}
		else
		{
			if (!stateredir && tmp_head->cmd_arg[0])
				handle_bad_command(tmp_head, param->child, i);
			else
			{
				if (!stateredir)
				{
					param->child->pid[i] = fork();
					if (param->child->pid[i] == 0)
					{
						dup_pipe(tmp_head, param->child, i);
						close_pipe(param->child, i);
						init_redir(tmp_head);
						force_close_fd();
						exit_program(param);
					}
					// else if (tmp_head->fd_heredoc[0] != -1)
					// {
						// close_heredoc_fd(tmp_head);
						// force_close_fd();
					// }
				}
				else
					param->child->pid[i] = -1;
				if (path)
					free(path);
			}
			read_lost_pipe(param->child, i);
		}
		i++;
		close_pipe(param->child, i);
		tmp_head = tmp_head->next;
	}
	close_pipe(param->child, i + 1);
	free(tmp_head);
	return (stateredir);
}

void	need_execution(t_param *param)
{
	int		builtin;
	int		i;
	int		stateredir;
	t_plot	*tmp_head;

	stateredir = 0;
	tmp_head = param->plots;
	if (init_child(plotlink_size(param->plots), param->child))
		return (error_handler(E_CHILD, param->progname, NULL));
	builtin = is_builtin(tmp_head->cmd_arg[0]);
	if (init_heredoc_plots(tmp_head, param->env))
	{
		free_child(param);
		return ;
	}
	set_handler_sig_parent();
	if (plotlink_size(param->plots) == 1
		&& builtin != ECHO && builtin != 0)
	{
		close_heredoc_fd(tmp_head);
		do_builtin(tmp_head, param, builtin, 0);
	}
	else
	{
		stateredir = preparation_fork(param, builtin);
	}
	i = 0;
	tmp_head = param->plots;
	while (i < plotlink_size(param->plots))
	{
		if (param->child->pid[i] != -1)
		{
			waitpid(param->child->pid[i], &param->child->w_status[i], 0);
			if (!is_builtin(tmp_head->cmd_arg[0]))
			{
				if (WIFEXITED(param->child->w_status[i]) && !stateredir)
				{
					g_return = WEXITSTATUS(param->child->w_status[i]);
				}
			}
		}
		i++;
		tmp_head = tmp_head->next;
	}
	free_child(param);
}
