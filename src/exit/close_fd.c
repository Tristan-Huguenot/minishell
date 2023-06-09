/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:31:53 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 10:31:54 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipe_builtin(t_child *child, int state)
{
	if (state % 2 == 0)
	{
		if (child->odd[0] != -1)
		{
			close(child->odd[0]);
			child->odd[0] = -1;
		}
		if (child->even[1] != -1)
		{
			close(child->even[1]);
			child->even[1] = -1;
		}
		return ;
	}
	if (child->even[0] != -1)
	{
		close(child->even[0]);
		child->even[0] = -1;
	}
	if (child->odd[1] != -1)
	{
		close(child->odd[1]);
		child->odd[1] = -1;
	}
}

void	close_pipe(t_child *child, int state)
{
	if (state % 2 == 0)
	{
		if (child->odd[1] != -1)
		{
			close(child->odd[1]);
			child->odd[1] = -1;
		}
		if (child->even[0] != -1)
		{
			close(child->even[0]);
			child->even[0] = -1;
		}
		return ;
	}
	if (child->even[1] != -1)
	{
		close(child->even[1]);
		child->even[1] = -1;
	}
	if (child->odd[0] != -1)
	{
		close(child->odd[0]);
		child->odd[0] = -1;
	}
}

void	close_heredoc_fd(t_plot *plot)
{
	if (plot->fd_heredoc[0] != -1)
		close(plot->fd_heredoc[0]);
	plot->fd_heredoc[0] = -1;
}

void	close_common_fd(void)
{
	close(0);
	close(1);
	close(2);
}
