/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:25:25 by thugueno          #+#    #+#             */
/*   Updated: 2023/05/25 00:44:40 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	error_argc(char *prog, char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		ft_fprintf(2, "%s: %s: %s\n", file, file, strerror(EISDIR));
		g_return = ENOKEY;
		return ;
	}
	g_return = EKEYEXPIRED;
	if (access(file, F_OK))
	{
		ft_fprintf("%s: %s: %s", prog, file, strerror(ENOENT));
		return ;
	}
}

void	error_handler(int err, char *prog, char *name)
{
	if (err == E_ARGC)
		return (error_argc(prog, name));
}
