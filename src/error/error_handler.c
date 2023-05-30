/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:25:25 by thugueno          #+#    #+#             */
/*   Updated: 2023/05/30 11:22:58 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}
