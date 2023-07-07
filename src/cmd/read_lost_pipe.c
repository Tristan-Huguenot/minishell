#include "minishell.h"

void	read_lost_pipe(t_child *child, int state)
{
	char	**tmp;

	if (state % 2 == 0)
		tmp = get_all_line(child->odd[0]);
	else
		tmp = get_all_line(child->even[0]);
	ft_free_strs(tmp);
}
