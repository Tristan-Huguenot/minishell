#include "minishell.h"

void	free_plots(t_param *param)
{
	if (param->plots)
		plotlink_clear(&param->plots);
}

void	free_param(t_param *param)
{
	if (param && param->paths)
		ft_free_strs(param->paths);
	if (param && param->env)
		envlink_clear(&param->env);
	if (param && param->prompt)
		free(param->prompt);
	if (param)
		free(param);
}

void	exit_program(t_param *param)
{
	free_plots(param);
	free_param(param);
	exit(g_return);
}
