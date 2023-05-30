/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:12:27 by thugueno          #+#    #+#             */
/*   Updated: 2023/05/30 17:47:04 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_param(t_param *param)
{
	if (param && param->paths)
		ft_free_strs(param->paths);
	if (param && param->env)
		envlink_clear(&param->env);
	if (param && param->prompt)
		free(param->prompt);
	if (param)
		free(param);
}

void	exit_program(t_param *param)
{
	free_param(param);
	exit(g_return);
}
