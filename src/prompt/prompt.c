/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:36:04 by thugueno          #+#    #+#             */
/*   Updated: 2023/05/30 12:43:02 by thugueno         ###   ########.fr       */
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
		if (ft_strncmp(input, "exit", 5) == 0)
		{
			rl_clear_history();
			free(input);
			g_return = 0;
			exit_program(param);
		}
		if (!parsing(&input))
		{		
			//execut();
			//free_chained_link();
		}
		free(input);
	}
}
