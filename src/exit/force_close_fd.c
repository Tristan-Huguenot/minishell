#include "minishell.h"

void	force_close_fd(void)
{
	int	i;

	i = 3;
	while (i < 21)
	{
		close(i);
		i++;
	}
}
