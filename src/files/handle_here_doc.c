#include "minishell.h"

// static void	init_pipe_here_doc(t_child *child, int state)
// {
	// if (state % 2 == 0)
	// {
		// if (child->odd[0] != -1)
		// {
			// close(child->odd[0]);
			// child->odd[0] = -1;
		// }
		// init_odd_pipe(child);
	// }
	// else
	// {
		// if (child->even[0] != -1)
		// {
			// close(child->even[0]);
			// child->even[0] = -1;
		// }
		// init_even_pipe(child);
	// }
// }
// 
// int	ft_strcmp_str(char *s1, char *s2)
// {
	// int	i;
// 
	// i = 0;
	// if (!s1 || !s2 || (ft_strlen(s1) != ft_strlen(s2)))
		// return (0);
	// while ((s1[i] == s2[i]) && (s1[i] != '\0'))
		// i++;
	// if (s1[i] == '\0' && s2[i] == '\0')
		// return (1);
	// return (0);
// }

static int	handle_here_doc(t_plot *plot, char *redir)
{
	char	*input;
	int		fd[2];

	if (pipe(fd) == -1)
		return (1);
	signal(SIGINT, signal_handler_hd);
	input = readline("> ");
	while (ft_strncmp(redir, input, ft_strlen(input) + 1))
	{
		if (!input)
		{
			error_handler(E_HEREDOC, NULL, redir);
			break ;
		}
		ft_fprintf(fd[1], "%s\n", input);
		free(input);
		input = readline("> ");
	}
	free(input);
	close(fd[1]);
	if (plot->fd_heredoc != -1)
		close(plot->fd_heredoc);
	plot->fd_heredoc = fd[0];
	return (0);
}

void	init_heredoc_plots(t_plot *plots)
{
	t_plot	*tmp;
	int		i;

	tmp = plots;
	while (tmp)
	{
		i = 0;
		while (tmp->redir[i])
		{
			if (tmp->redir[i][0] == '0' && tmp->redir[i][1] == '2')
			{
				if (!handle_here_doc(tmp, tmp->redir[i] + 3))
					tmp->index_hd = i;
				else
					ft_fprintf(2, "%s\n", strerror(errno));
			}
			i++;
		}
		tmp = tmp->next;
	}
}

// init_here_doc(plot)
// {
// while sur plot
// 		size = nb heredoc dans plot\
// 		while sur redir
// 			si heredoc -> handle_heredoc et on recupere lecture pipe
//
// }
