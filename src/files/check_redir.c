#include "minishell.h"

static int	check_open_redir_out(char *redir)
{
	int	fd;
	int	ret;

	ret = 0;
	if (access(redir + 3, F_OK))
	{
		fd = open(redir + 3, O_CREAT, 00644);
		if (fd != -1)
			close(fd);
	}
	if (access(redir + 3, W_OK))
	{
		ft_fprintf(2, "%s: %s\n", redir + 3, strerror(13));
		ret = 1;
	}
	return (ret);
}

static int	check_open_redir_in(char *redir)
{
	int	ret;

	ret = 0;
	if (access(redir + 3, F_OK))
	{
		ft_fprintf(2, "%s: %s\n", redir + 3, strerror(2));
		ret = 1;
	}
	else if (access(redir + 3, R_OK))
	{
		ft_fprintf(2, "%s: %s\n", redir + 3, strerror(13));
		ret = 1;
	}
	return (ret);
}

int	check_open_redir(char **redir)
{
	int	i;

	i = 0;
	while (redir[i])
	{
		if (redir[i][0] == '0')
		{
			if (redir[i][1] != '2')
				if (check_open_redir_in(redir[i]))
					return (1);
		}
		else
		{
			if (check_open_redir_out(redir[i]))
				return (1);
		}
		i++;
	}
	return (0);
}
