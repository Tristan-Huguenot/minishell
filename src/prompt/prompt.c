/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:36:04 by thugueno          #+#    #+#             */
/*   Updated: 2023/05/30 12:32:52 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt_in(t_param *param)
{
	char	*input;

	input = readline(param->prompt); // on rajoutera le chemin?
	if (ft_strlen(input) != 0)
	{
		add_history(input);
		parsing_redirection(&input, 0);
		if (ft_strncmp(input, "exit", 5) == 0)
		{
			rl_clear_history();
			free(input);
			g_return = 0;
			exit_program(param);
		}
		free(input);
	}
}
