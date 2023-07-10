/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_execve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:31:34 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 15:54:55 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dup_pipe(t_plot *plot, t_child *child, int state)
{
	if (state % 2 == 0)
		dup_pipe_even(plot, child);
	else if (state % 2)
		dup_pipe_odd(plot, child);
}

void	do_execve(t_plot *tmp_head, t_param *param, char *path)
{
	char	**tmp;

	tmp = convert_env_strs(param->env);
	execve(path, tmp_head->cmd_arg, tmp);
}
