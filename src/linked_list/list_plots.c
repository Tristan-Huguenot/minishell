/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_plots.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:33:24 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 10:33:26 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_plot	*plotlink_last(t_plot *plot)
{
	if (!plot)
		return (NULL);
	while (plot->next)
		plot = plot->next;
	return (plot);
}

t_plot	*plotlink_new(char *cmd)
{
	t_plot	*plot;

	plot = ft_calloc(1, sizeof(*plot));
	if (!plot)
		return (plot);
	plot->cmd = cmd;
	plot->next = NULL;
	plot->fd_heredoc[0] = -1;
	plot->fd_heredoc[1] = -1;
	return (plot);
}

void	plotlink_addback(t_plot **plots, t_plot *new)
{
	t_plot	*last;

	if (!new || !plots)
		return ;
	if (!*plots)
	{
		*plots = new;
		return ;
	}
	last = plotlink_last(*plots);
	last->next = new;
	if (new->next)
		new->next = NULL;
}

void	delete_plot(t_plot *plot)
{
	if (!plot)
		return ;
	if (plot->cmd)
		free(plot->cmd);
	if (plot->cmd_arg)
		ft_free_strs(plot->cmd_arg);
	if (plot->redir)
		ft_free_strs(plot->redir);
	close_heredoc_fd(plot);
	free(plot);
}

void	plotlink_clear(t_plot **plots)
{
	t_plot	*tmp;

	if (!plots)
		return ;
	while (*plots)
	{
		tmp = *plots;
		*plots = (*plots)->next;
		delete_plot(tmp);
	}
}
