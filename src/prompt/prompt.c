/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:34:39 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 10:34:39 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt_in(t_param *param)
{
	param->input = readline(param->prompt);
	if (!param->input)
		ft_exit(0, NULL, param, 0);
	if (ft_strlen(param->input) != 0)
	{
		add_history(param->input);
		if (!parsing(param, param->input))
			need_execution(param);
		plotlink_clear(&param->plots);
	}
	if (param->input)
		free(param->input);
}
