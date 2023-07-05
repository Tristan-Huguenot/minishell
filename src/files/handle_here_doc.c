#include "minishell.h"

static void	write_in_heredoc_pipe(t_child *child, int state, char *input)
{
	if (state % 2 == 0)
		ft_fprintf(child->odd[1], "%s\n", input);
	else
		ft_fprintf(child->even[1], "%s\n", input);
}

static void	init_pipe_here_doc(t_child *child, int state)
{
	if (state % 2 == 0)
	{
		if (child->odd[0] != -1)
		{
			close(child->odd[0]);
			child->odd[0] = -1;
		}
		init_odd_pipe(child);
	}
	else
	{
		if (child->even[0] != -1)
		{
			close(child->even[0]);
			child->even[0] = -1;
		}
		init_even_pipe(child);
	}
}

void	handle_here_doc(char *redir, t_child *child, int state)
{
	char	*input;

	// init_pipe_here_doc(child, state);
	// faire le pipe
	input = readline("> ");
	while (ft_strncmp(redir, input, ft_strlen(input)))
	{
		if (!input)
		{
			error_handler(E_HEREDOC, NULL, redir + 3);
			free(input);
			break ;
		}
		printf("input : %s-----------\n", input);
		write_in_heredoc_pipe(child, state, input);
		free(input);
		input = readline("> ");
	}
//	close les ecritures;  
	// dup_heredoc_pipe(child, state);
	// close_heredoc_pipe(child, state);
}

// init_here_doc(plot)
// {
// while sur plot
// 		size = nb heredoc dans plot\
// 		initialise tableau int
// 		while sur redir
// 			si heredoc -> handle_heredoc et on recupere lecture pipe
//
// }
