#include "minishell.h"

static void	init_check(int	*i, int *n, int stat[2])
{
	*i = 0;
	*n = 0;
	stat[0] = 0;
	stat[1] = 0;
}

int	check_redir(t_plot *plot, t_param *param)
{
	int	i;
	int	n;
	int	stat[2];

	init_check(&i, &n, stat);
	i = jump_next_redir(plot->cmd, i);
	while (plot->cmd[i])
	{
		n++;
		if (plot->cmd[i] == plot->cmd[i + 1])
			i++;
		i++;
		while (ft_char_in_set(plot->cmd[i], CS_WSPACE))
			i++;
		if (ft_char_in_set(plot->cmd[i], CS_REDIR) || !plot->cmd[i])
		{
			error_redir(i, plot, param);
			n = -1;
			break;
		}
		i = jump_next_redir(plot->cmd, i);
	}
	return (n);
}

int	parsing_redir(t_plot *plot, t_param *param)
{
	int	size;

	size = check_redir(plot, param);
	if (size == -1)
	{
		g_return = ENOENT;
		return (1);
	}
	ft_printf("redir = %d\n", size);
	return (0);
}
