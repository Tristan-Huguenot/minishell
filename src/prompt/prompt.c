/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:36:04 by thugueno          #+#    #+#             */
/*   Updated: 2023/05/24 20:12:41 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt_in(void)
{
	char	*input;

	input = readline("\033[38;5;196mminishell > \033[0m"); // on rajoutera le chemin?
	// printf("%s", input);
	if (ft_strlen(input) != 0)
	{
		add_history(input);
		wrong_quote(input);
		// parsing_redirection(&input, 0);
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
