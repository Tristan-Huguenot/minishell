/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:31:38 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 10:31:39 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dup_heredoc_pipe(t_child *child, int state)
{
	if (state % 2 == 0)
		dup2(child->odd[0], 0);
	else
		dup2(child->even[0], 0);
}

void	dup_pipe_even(t_plot *plot, t_child *child)
{
	if (child->odd[0] != -1)
	{
		dup2(child->odd[0], 0);
		close(child->odd[0]);
	}
	if (child->even[1] != -1 && plot->next)
	{
		dup2(child->even[1], 1);
		close(child->even[1]);
	}
	if (!plot->next)
	{
		close(child->even[1]);
		child->even[1] = -1;
	}
}

void	dup_pipe_odd(t_plot *plot, t_child *child)
{
	if (child->even[0] != -1)
	{
		dup2(child->even[0], 0);
		close(child->even[0]);
	}
	if (child->odd[1] != -1 && plot->next)
	{
		dup2(child->odd[1], 1);
		close(child->odd[1]);
	}
	if (!plot->next)
	{
		close(child->odd[1]);
		child->odd[1] = -1;
	}
}
