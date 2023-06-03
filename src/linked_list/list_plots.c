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
