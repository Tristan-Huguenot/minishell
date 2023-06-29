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

static void	do_builtin(t_plot *plot, t_param *param, int builtin)
{
	char	**tmp;

	tmp = convert_env_strs(param->env);
	if (builtin == ECHO)
	{
		// faire dup;
		ft_free_strs(tmp);
		g_return = echo(plot->argc, plot->cmd_arg);
		exit_program(param);
	}
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
		ft_exit(plot->argc, plot->cmd_arg, param);
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
		path = file_is_exe(tmp_head->cmd_arg[0], param->paths);
		if (path)
		{
			param->child->pid[i] = fork();
			if (param->child->pid[i] == 0)
			{
				if (builtin)
				{
					free(path);
					do_builtin(tmp_head, param, builtin);
				}
				// else if (builtin && !(i % 2))
					// do_builtin(tmp_head, param, builtin);

				// else if(i % 2)
					// do_execve_odd(tmp_head, param);
				else
				{
					do_execve_even(tmp_head, param, i, path);
				}
			}
			free(path);
		}
		i++;
		tmp_head = tmp_head->next;
	}
	free(tmp_head);
}

void	need_execution(t_param *param)
{
	int		builtin;
	int		i;
	t_plot	*tmp_head;

	tmp_head = param->plots;
	param->child->pid = ft_calloc(plotlink_size(param->plots), sizeof(int *));
	param->child->w_status = ft_calloc(plotlink_size(param->plots), \
			sizeof(int));
	builtin = is_builtin(tmp_head->cmd_arg[0]);
	if (plotlink_size(param->plots) == 1
		&& builtin != ECHO && builtin != 0)
	{
		do_builtin(tmp_head, param, builtin);
	}
	else
		preparation_fork(param, builtin);
	i = 0;
	while (i < plotlink_size(param->plots))
	{
		waitpid(param->child->pid[i], &param->child->w_status[i], 0);
		i++;
	}
	free_child(param);
	// free(tmp_head);
}
