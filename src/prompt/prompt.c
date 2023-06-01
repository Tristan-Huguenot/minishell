#include "minishell.h"

void	exit_tmp(t_param *param, char **input_ptr)
{
	/* exit avec bash peut avoir un argument (0-133 inclut) et fonctionne avec les pipes du genre exit 1 | sleep 5
		j ai mis en temporaire psk faudra le gerer une fois le parsing fait
		au moment d executer la cmd > si param->plot->cmd_arg[0] == keyword alors on appel built in
	*/
	free(*input_ptr);
	rl_clear_history();
	g_return = 0;
	exit_program(param);
}

void	prompt_in(t_param *param)
{
	char	*input;
	// char	quote;

	input = readline(param->prompt);
	if (ft_strlen(input) != 0)
	{
		add_history(input);
		if (ft_strncmp(input, "exit", 5) == 0)
			exit_tmp(param, &input);
		parsing(param, input);
		/*if (!parsing(param, input))
		{		
			execut();
			free_chained_link();
		}*/
		plotlink_clear(&param->plots);
		free(input);
	}
	else
		free(input);
}
