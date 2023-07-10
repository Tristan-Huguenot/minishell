/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lost_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:31:40 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 10:31:41 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	read_lost_pipe(t_child *child, int state)
{
	char	**tmp;

	if (state % 2 == 0)
		tmp = get_all_line(child->odd[0]);
	else
		tmp = get_all_line(child->even[0]);
	ft_free_strs(tmp);
}
