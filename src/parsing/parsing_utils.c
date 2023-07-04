#include "minishell.h"

void	clear_cmd_arg(t_plot *plot, int i)
{
	free(plot->cmd_arg[i]);
	plot->cmd_arg[i] = NULL;
}
