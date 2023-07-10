/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plots.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:33:17 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 10:33:18 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*pass_white_space(char *input)
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
	t_plot	*plot;
	char	*tmp;
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
	plot = NULL;
	tmp = ft_substr(input, 0, i);
	if (tmp)
		plot = plotlink_new(tmp);
	if (plot)
		plotlink_addback(&param->plots, plot);
	else
		free(tmp);
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
				error_handler(E_UTOKEN, param->progname, "||");
			else if (!input || (*input && *(input + 1) != '|'))
				error_handler(E_TOKEN, param->progname, "|");
			if (param->plots && *input)
				plotlink_clear(&param->plots);
			g_return = ENOENT;
			return ;
		}
		init_plot(param, input);
		input = jump_next_pipe(input);
		if (*input && pass_white_space(input + 1)[0] != '\0')
			input++;
	}
}
