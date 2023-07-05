#include "minishell.h"

static void	init_redir_out(char *redir)
{
	int	fd;

	if (redir[1] == '1')
	{
		fd = open(redir + 3, O_WRONLY | O_TRUNC);
		if (fd != -1)
		{
			dup2(fd, 1);
			close(fd);
		}
	}
	else
	{
		fd = open(redir + 3, O_WRONLY | O_APPEND);
		if (fd != -1)
		{
			dup2(fd, 1);
			close(fd);
		}
	}
}

static void	init_redir_in(char *redir, t_child *child)
{
	int	fd;

	if (redir[1] == '1')
	{
		fd = open(redir + 3, O_RDONLY);
		if (fd != -1)
		{
			dup2(fd, 0);
			close(fd);
		}
	}
	else
		return ;
	(void)child;
}

void	init_redir(char **redir, t_child *child)
{
	int	i;

	i = 0;
	while (redir[i])
	{
		if (redir[i][0] == '0')
			init_redir_in(redir[i], child);
		else
			init_redir_out(redir[i]);
		i++;
	}
}
