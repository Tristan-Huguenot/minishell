#include "minishell.h"

static void	print_argc_error(char *first, char *second, char *last, int err)
{
	ft_fprintf(2, "%s: %s: %s\n", first, second, last);
	g_return = err;
}

static void	error_argc(t_param *param, char *file)
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
		return (print_argc_error(param->progname, file, strerror(ENOENT), EKEYEXPIRED));
	if (access(file, R_OK) == -1)
		return (print_argc_error(param->progname, file, strerror(EACCES), ENOKEY));
	g_return = 0;
	return ;
}

void	error_handler(int err, t_param *param, char *name)
{
	if (err == E_ARGC)
		return (error_argc(param, name));
	else if (err == E_WQUOTE)
		ft_fprintf(2, "%s: %c: Quote not closed\n", param->progname, *name);
	else if (err == E_TOKEN)
	{
		ft_fprintf(2, "%s: syntax error near unexpected token '%s'\n", \
		param->progname, name);
	}
}
