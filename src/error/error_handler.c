#include "minishell.h"

static void	print_argc_error(char *first, char *second, char *last, int err)
{
	ft_fprintf(2, "%s: %s: %s\n", first, second, last);
	g_return = err;
}

void	error_argc(t_param *param, char *file)
{
	char	*tmp;
	int		fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (print_argc_error(file, file, strerror(EISDIR), ENOKEY));
	}
	tmp = file_is_exe(file, param->paths);
	if (tmp && !(!access(file, F_OK) && access(file, R_OK) == -1))
	{	
		print_argc_error(tmp, tmp, "cannot execute binary file", ENOKEY);
		free(tmp);
		return ;
	}
	else
		free(tmp);
	if (access(file, F_OK) == -1)
		return (print_argc_error(param->progname, \
		file, strerror(ENOENT), EKEYEXPIRED));
	if (access(file, R_OK) == -1)
		return (print_argc_error(param->progname, \
		file, strerror(EACCES), ENOKEY));
	g_return = 0;
}

void	error_handler(int err, char	*progname, char *name)
{
	if (err == E_WQUOTE)
		ft_fprintf(2, "%s: %c: Quote not closed\n", progname, *name);
	else if (err == E_TOKEN)
	{
		ft_fprintf(2, "%s: syntax error near unexpected token '%s'\n", \
		progname, name);
	}
	else if (err == E_IDENTIFIER)
		ft_fprintf(2, "%s: 'name': not a valid identifier\n", progname, *name);
}

void	error_redir(int i, t_plot *plot, t_param *param)
{
	char	c[3];

	if (!plot->cmd[i])
	{
		if (plot->next)
			error_handler(E_TOKEN, param->progname, "|");
		else
			error_handler(E_TOKEN, param->progname, "newline");
	}
	else
	{
		c[0] = plot->cmd[i];
		if (plot->cmd[i] == plot->cmd[i + 1])
			c[1] = c[0];
		else
			c[1] = '\0';
		c[2] = '\0';
		error_handler(E_TOKEN, param->progname, c);
	}
}
