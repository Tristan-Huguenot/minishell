#include "minishell.h"

void	handle_bad_command(t_plot *plot, t_child *child, int state)
{
	child->pid[state] = -1;
	g_return = 127;
	if (!plot->cmd_arg || !plot->cmd_arg[0])
	{
		g_return = 0;
		return ;
	}
	if (plot->cmd_arg[0][0] == '/')
	{
		if (!file_is_dir(plot->cmd_arg[0]))
			ft_fprintf(2, "%s: %s\n", plot->cmd_arg[0], strerror(2));
		else
		{
			g_return = 126;
			ft_fprintf(2, "%s: %s\n", plot->cmd_arg[0], strerror(21));
		}
	}
	else if (ft_strchr(plot->cmd_arg[0], '/'))
	{
		if (file_is_dir(plot->cmd_arg[0]))
		{
			g_return = 126;
			ft_fprintf(2, "%s: %s\n", plot->cmd_arg[0], strerror(21));
		}
		else
			ft_fprintf(2, "%s: %s\n", plot->cmd_arg[0], strerror(2));
	}
	else
		ft_fprintf(2, "%s: command not found\n", plot->cmd_arg[0]);
}
