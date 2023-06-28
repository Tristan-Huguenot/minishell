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
		g_return = echo(plot->argc, plot->cmd_arg);
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

void	need_execution(t_param *param)
{
	int		builtin;
	int		i;
	t_plot	*tmp_head;

	i = 0;
	tmp_head = param->plots;
	param->child->pid = ft_calloc(plotlink_size(param->plots), sizeof(int *));
	param->child->w_status = ft_calloc(plotlink_size(param->plots), sizeof(int));
	while (tmp_head)
	{
		
		builtin = is_builtin(tmp_head->cmd_arg[0]);
		if (builtin)
			do_builtin(tmp_head, param, builtin);
		// else if (builtin && !(i % 2))
			// do_builtin(tmp_head, param, builtin);

		// else if(i % 2)
			// do_execve_odd(tmp_head, param);
		else
			do_execve_even(tmp_head, param, i);
		i++;
		tmp_head = tmp_head->next;
	}
	i = 0;
		// printf("\n\n --------------------------------pid[i] %d , %p----------------------------------------- \n ", param->child->pid[i], &param->child->w_status[i] );
	while (i < plotlink_size(param->plots))
	{
		// printf("\n\n --------------------------------pid[i] %d , %p----------------------------------------- \n ", param->child->pid[i], &param->child->w_status[i] );
		waitpid(param->child->pid[i], &param->child->w_status[i] , 0);
		i++;
	}
	free_child(param);
	free(tmp_head);
}
