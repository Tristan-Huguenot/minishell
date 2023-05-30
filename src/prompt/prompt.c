#include "minishell.h"

void	prompt_in(t_param *param)
{
	char	*input;

	input = readline(param->prompt);
	if (ft_strlen(input) != 0)
	{
		add_history(input);
		if (ft_strncmp(input, "exit", 5) == 0)
		{
			rl_clear_history();
			free(input);
			g_return = 0;
			exit_program(param);
		}
		if (!parsing(param, input))
		{		
			//execut();
			//free_chained_link();
		}
		free(input);
	}
}
