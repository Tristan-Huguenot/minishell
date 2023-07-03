#include "minishell.h"

void	dup_pipe(t_plot *plot, t_child *child, int state)
{
	if (state % 2 == 0)
		dup_pipe_even(plot, child);
	else if (state % 2)
		dup_pipe_odd(plot, child);
}

void	do_execve_even(t_plot *tmp_head, t_param *param, int i, char *path)
{
	char	**tmp;

	(void)i;
	tmp = convert_env_strs(param->env);
	execve(path, tmp_head->cmd_arg, tmp);
}

void	do_execve_odd(t_plot *tmp_head, t_param *param, int i, char *path)
{
	char	**tmp;

	(void)i;
	tmp = convert_env_strs(param->env);
	execve(path, tmp_head->cmd_arg, tmp);
}
