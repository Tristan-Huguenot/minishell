/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_heredoc_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:37:08 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 10:31:57 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_other_plot_hd(t_plot *actual, t_plot *start)
{
	while (start != NULL)
	{
		if (start != actual && start->fd_heredoc[0] != -1)
		{
			close(start->fd_heredoc[0]);
			start->fd_heredoc[0] = -1;
		}
		start = start->next;
	}
}

void	close_all_plot_hd(t_plot *plot)
{
	while (plot != NULL)
	{
		if (plot->fd_heredoc[0] != -1)
		{
			close(plot->fd_heredoc[0]);
			plot->fd_heredoc[0] = -1;
		}
		plot = plot->next;
	}
}
