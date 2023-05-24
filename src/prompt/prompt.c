#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/others/libft.h"
#include "prompt.h"

void	prompt_in(void)
{
	char	*input;

	input = readline("\033[35mminishell > \033[0m"); // on rajoutera le chemin?
	// printf("%s", input);
	if (ft_strlen(input) != 0)
	{
		add_history(input);
		parsing_redirection(input, 0);
		if (ft_strncmp(input, "exit", 5) == 0)
		{
			rl_clear_history();
			// free_end();
			free(input);
			exit(0);
		}
		free(input);
	}
}
