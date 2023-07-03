#include "minishell.h"

void	free_child(t_param *param)
{
	if (param->child && param->child->pid)
		free(param->child->pid);
	if (param->child && param->child->w_status)
		free(param->child->w_status);
	param->child->pid = NULL;
	param->child->w_status = NULL;
}

void	free_plots(t_param *param)
{
	if (param->plots)
		plotlink_clear(&param->plots);
}

void	free_param(t_param *param)
{
	if (param && param->child)
		free(param->child);
	if (param && param->paths)
		ft_free_strs(param->paths);
	if (param && param->env)
		envlink_clear(&param->env);
	if (param && param->prompt)
		free(param->prompt);
	if (param && param->input)
		free(param->input);
	if (param)
		free(param);
}

void	exit_program(t_param *param)
{
	free_child(param);
	free_plots(param);
	free_param(param);
	close_common_fd();
	exit(g_return);
}
