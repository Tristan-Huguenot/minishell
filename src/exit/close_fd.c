#include "minishell.h"

void	close_all_heredoc(t_plot *plots)
{
	t_plot	*tmp;

	tmp = plots;
	while (tmp)
	{
		if (tmp->fd_heredoc[0] != -1)
		{
			close(tmp->fd_heredoc[0]);
			tmp->fd_heredoc[0] = -1;
		}
		if (tmp->fd_heredoc[1] != -1)
		{
			close(tmp->fd_heredoc[1]);
			tmp->fd_heredoc[1] = -1;
		}
		tmp = tmp->next;	
	}
}

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
