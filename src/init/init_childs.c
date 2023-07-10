/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_childs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:33:10 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 10:33:10 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_child(int size, t_child *child)
{
	child->pid = ft_calloc(size, sizeof(*child->pid));
	if (!child->pid)
		return (1);
	child->w_status = ft_calloc(size, sizeof(*child->w_status));
	if (!child->w_status)
	{
		free(child->pid);
		return (1);
	}
	child->odd[0] = -1;
	child->odd[1] = -1;
	child->even[0] = -1;
	child->even[1] = -1;
	return (0);
}
