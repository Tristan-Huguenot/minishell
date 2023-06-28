#include "minishell.h"

void	init_child(t_param *param)
{
	param->child->pid = NULL;
	param->child->w_status = NULL;
}
