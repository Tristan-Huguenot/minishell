#include "minishell.h"

static int	handle_here_doc(t_plot *plot, char *redir, t_env *env)
{
	char	*input;
	int		new_stdin;

	new_stdin = dup(0);
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
	if (isatty(0) && !input)
		error_handler(E_HEREDOC, NULL, redir);
	else if (!isatty(0) && !input)
	{
		dup2(new_stdin, 0);
		close(new_stdin);
		return (2);
	}
	close(new_stdin);
	free(input);
	close(plot->fd_heredoc[1]);
	plot->fd_heredoc[1] = -1;
	return (0);
}

void	init_heredoc_plots(t_plot *plots, t_env *env)
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
				if (state == 0)
					tmp->index_hd = i;
				else if (state == 1)
					ft_fprintf(2, "%s\n", strerror(errno));
				else if (state == 2)
				{
					close_all_heredoc(plots);
					break;
				}
			}
			i++;
		}
		tmp = tmp->next;
	}
}
