#include "minishell.h"

static char *pass_white_space(char *input)
{
	if (!*input)
		return (input);
	while (*input == 32 || (*input >= 8 && *input <= 13))
		input++;
	return (input);
}

static char	*jump_next_pipe(char *input)
{
	while (*input && *input != '|')
	{
		if (*input == '\'' || *input == '\"')
			input = ft_strchr(input + 1, *input);
		if (*input && *input != '|')
			input++;
	}
	return (input);	
}

static void	init_plot(t_param *param, char *input)
{
	char	*pipe;
	int		i;

	pipe = jump_next_pipe(input);
	while (*pipe == 32 || (*pipe >= 8 && *pipe <= 13))
		pipe--;
	i = 0;
	while (input != pipe)
	{
		pipe--;
		i++;
	}
	plotlink_addback(&param->plots, plotlink_new(ft_substr(input, 0, i)));
}

void	init_plots(t_param *param, char *input)
{
	char	*tmp;

	if (!input)
		return ;
	tmp = input;
	while (*input)
	{
		input = pass_white_space(input);
		if (!*input || *input == '|')
		{
			if ((*input && *(input + 1) == '|')
				|| (input != tmp && *(input - 1) == '|'))
				error_handler(E_TOKEN, param, "||");
			else if (!input || (*input && *(input + 1) != '|'))
				error_handler(E_TOKEN, param, "|");
			if (param->plots && *input)
				plotlink_clear(&param->plots);
			return ;
		}
		init_plot(param, input);
		input = jump_next_pipe(input);
		if (*input && pass_white_space(input + 1)[0] != '\0')
			input++;
	}
}
