#include "minishell.h"

void	do_execve_even(t_plot *tmp_head, t_param *param, int i)
{
	char	*path;
	char	**tmp;


	path = file_is_exe(tmp_head->cmd_arg[0], param->paths);
	if (path)
	{
		param->child->pid[i] = fork();
		if (param->child->pid[i] == 0)
		{
			// if ()
			// if(pipe(param->child->even) == -1)
		// {
			// perror("error pipe");
			// g_return = 2;
			// return ;
		// }
			// dup2(param->child->even[1], 1);
			close(param->child->even[0]);
			close(param->child->even[1]);
			tmp = convert_env_strs(param->env);
			execve(path, tmp_head->cmd_arg, tmp);
		}
		else
		{
			free(path);
		}
	}
}
/*
void	do_execve_odd(t_plot *tmp_head, t_param *param)
{

}*/
