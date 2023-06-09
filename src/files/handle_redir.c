/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:33:05 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 10:33:06 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_redir_out(char *redir)
{
	int	fd;

	if (redir[1] == '1')
		fd = open(redir + 3, O_WRONLY | O_TRUNC);
	else
		fd = open(redir + 3, O_WRONLY | O_APPEND);
	if (fd != -1)
	{
		dup2(fd, 1);
		close(fd);
	}
}

static void	init_redir_in(t_plot *plot, int i)
{
	int	fd;

	if (plot->redir[i][1] == '1')
	{
		fd = open(plot->redir[i] + 3, O_RDONLY);
		if (fd != -1)
		{
			dup2(fd, 0);
			close(fd);
		}
	}
	else
	{
		if (i == plot->index_hd && plot->fd_heredoc[0] != -1)
		{
			dup2(plot->fd_heredoc[0], 0);
			if (close(plot->fd_heredoc[0]) == -1)
				printf("fd is not close\n");
			plot->fd_heredoc[0] = -1;
		}
	}
}

void	init_redir(t_plot *plot)
{
	int	i;

	i = 0;
	while (plot->redir[i])
	{
		if (plot->redir[i][0] == '0')
			init_redir_in(plot, i);
		else
			init_redir_out(plot->redir[i]);
		i++;
	}
}
