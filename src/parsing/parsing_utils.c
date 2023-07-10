/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:33:59 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 10:34:01 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_cmd_arg(t_plot *plot, int i)
{
	free(plot->cmd_arg[i]);
	plot->cmd_arg[i] = NULL;
}
