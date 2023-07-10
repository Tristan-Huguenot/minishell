/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:18:30 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 10:33:03 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_ctrl_c(int new_stdin, char *redir, char *input)
{
	if (isatty(0) && !input)
		error_handler(E_HEREDOC, NULL, redir);
	else if (!isatty(0) && !input)
	{
		dup2(new_stdin, 0);
		close(new_stdin);
		return (1);
	}
	return (0);
}

static void	close_previous_heredoc(t_plot *plot)
{
	if (plot->fd_heredoc[0] != -1)
	{
		close(plot->fd_heredoc[0]);
		plot->fd_heredoc[0] = -1;
	}
}

static int	handle_here_doc(t_plot *plot, char *redir, t_env *env)
{
	char	*input;
	int		new_stdin;

	new_stdin = dup(0);
	close_previous_heredoc(plot);
	if (pipe(plot->fd_heredoc) == -1)
		return (1);
	set_handler_sig_hered();
	input = readline("> ");
	while (ft_strncmp(redir, input, ft_strlen(input) + 1))
	{
		if (!input)
			break ;
		input = parsing_variable(input, env, 1);
		ft_fprintf(plot->fd_heredoc[1], "%s\n", input);
		free(input);
		input = readline("> ");
	}
	if (check_ctrl_c(new_stdin, redir, input))
		return (2);
	close(new_stdin);
	free(input);
	close(plot->fd_heredoc[1]);
	plot->fd_heredoc[1] = -1;
	return (0);
}

static int	handle_state_return(t_plot *head, t_plot *actual, int i, int state)
{
	if (state == 0)
		actual->index_hd = i;
	else if (state == 1)
		ft_fprintf(2, "%s\n", strerror(errno));
	else if (state == 2)
	{
		close_all_plot_hd(head);
		if (actual->fd_heredoc[1] != -1)
		{
			close(actual->fd_heredoc[1]);
			actual->fd_heredoc[1] = -1;
		}
		return (1);
	}
	return (0);
}

int	init_heredoc_plots(t_plot *plots, t_env *env)
{
	t_plot	*tmp;
	int		state;
	int		i;

	tmp = plots;
	while (tmp)
	{
		i = 0;
		while (tmp->redir[i])
		{
			if (tmp->redir[i][0] == '0' && tmp->redir[i][1] == '2')
			{
				state = handle_here_doc(tmp, tmp->redir[i] + 3, env);
				if (handle_state_return(plots, tmp, i, state))
					return (1);
			}
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}
