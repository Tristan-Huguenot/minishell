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
		g_return = ft_export(plot->argc, plot->cmd_arg, &param->env);
	else if (builtin == UNSET)
		g_return = unset(plot->argc, plot->cmd_arg, &param->env);
	else if (builtin == ENV)
		g_return = env(plot->argc, plot->cmd_arg, tmp);
	ft_free_strs(tmp);
	if (builtin == EXIT)
		ft_exit(plot->argc, plot->cmd_arg, param, isfork);
	if (isfork)
		exit_program(param);
}

void	preparation_fork(t_param *param, int builtin)
{
	int		i;
	char	*path;
	t_plot	*tmp_head;

	tmp_head = param->plots;
	i = 0;
	while (tmp_head)
	{
		builtin = is_builtin(tmp_head->cmd_arg[0]);
		if (init_pipe(i, param->child))
			return ;
		signal(SIGINT, sig_child);
		signal(SIGQUIT, sig_child);
		path = file_is_exe(tmp_head->cmd_arg[0], param->paths);
		// redir
		if (path || builtin)
		{
			param->child->pid[i] = fork();
			if (param->child->pid[i] == 0)
			{
				dup_pipe(tmp_head, param->child, i);
				close_pipe(param->child, i);
				if (builtin)
				{
					free(path);
					do_builtin(tmp_head, param, builtin, 1);
				}
				else
					do_execve_odd(tmp_head, param, i, path);
			}
			free(path);
		}
		else
		{
			param->child->pid[i] = -1;
			printf("%s : %s\n", tmp_head->cmd_arg[0], strerror(errno));
			// verif vide ou dossier ou not found
		}
		i++;
		close_pipe(param->child, i);
		tmp_head = tmp_head->next;
	}
	close_pipe(param->child, i + 1);
	free(tmp_head);
}

void	need_execution(t_param *param)
{
	int		builtin;
	int		i;
	t_plot	*tmp_head;

	tmp_head = param->plots;
	if (init_child(plotlink_size(param->plots), param->child))
		return (error_handler(E_CHILD, param->progname, NULL));
	builtin = is_builtin(tmp_head->cmd_arg[0]);
	if (plotlink_size(param->plots) == 1
		&& builtin != ECHO && builtin != 0)
	{
		do_builtin(tmp_head, param, builtin, 0);
	}
	else
	{
		preparation_fork(param, builtin);
	}
	i = 0;
	while (i < plotlink_size(param->plots))
	{
		if (param->child->pid[i] != -1)
			waitpid(param->child->pid[i], &param->child->w_status[i], 0);
		i++;
	}
	free_child(param);
}
