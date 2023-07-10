/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:04:19 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 13:09:32 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_close_childs(t_param *param, t_child *child, int stateredir)
{
	t_plot	*tmp;
	int	i;

	i = 0;
	tmp = param->plots;
	while (i < plotlink_size(param->plots))
	{
		if (child->pid[i] != -1)
		{
			waitpid(child->pid[i], &child->w_status[i], 0);
			if (!is_builtin(tmp->cmd_arg[0]))
			{
				if (WIFEXITED(child->w_status[i]) && !stateredir)
					g_return = WEXITSTATUS(child->w_status[i]);
			}
		}
		i++;
		tmp = tmp->next;
	}
	free_child(param);
}
