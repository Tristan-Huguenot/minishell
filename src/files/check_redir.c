#include "minishell.h"

static int	check_open_redir_out(char *redir)
{
	int	fd;
	int	ret;

	fd = -1;
	ret = 0;
	if (access(redir + 3, F_OK))
		fd = open(redir + 3, O_CREAT, 00644);
	else if (!access(redir + 3, W_OK))
	{
		if (redir[1] == '1')
			fd = open(redir + 3, O_WRONLY | O_TRUNC);
		else
			fd = open(redir + 3, O_WRONLY | O_APPEND);
	}
	if (fd != -1)
		close(fd);
	if (file_is_dir(redir + 3))
	{
		ft_fprintf(2, "%s: %s\n", redir + 3, strerror(21));
		ret = 1;
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
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (redir[i] && ret == 0)
	{
		if (redir[i][0] == '0')
		{
			if (redir[i][1] != '2')
				if (check_open_redir_in(redir[i]))
					ret = 1;
		}
		else
		{
			if (check_open_redir_out(redir[i]))
				ret = 1;
		}
		i++;
	}
	g_return = ret;
	return (ret);
}
