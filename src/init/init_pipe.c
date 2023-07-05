#include "minishell.h"

int	init_even_pipe(t_child *child)
{
	if (pipe(child->even) == -1)
	{
		child->even[0] = -1;
		child->even[1] = -1;
		ft_fprintf(2, "%s\n", strerror(errno));
		return (1);
	}
	return (0);
}

int	init_odd_pipe(t_child *child)
{
	if (pipe(child->odd) == -1)
	{
		child->odd[0] = -1;
		child->odd[1] = -1;
		ft_fprintf(2, "%s\n", strerror(errno));
		return (1);
	}
	return (0);
}

int	init_pipe(int state, t_child *child)
{
	int	ret;

	ret = 0;
	if (state % 2 == 0)
		ret = init_even_pipe(child);
	else
		ret = init_odd_pipe(child);
	return (ret);
}
