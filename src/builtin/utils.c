/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:31:26 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 10:31:27 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sort_strs(char **strs)
{
	char	*tmp;
	int		i;
	int		y;

	if (!strs)
		return ;
	i = 0;
	y = 1;
	while (strs[i] && strs[y])
	{
		if (ft_strncmp(strs[i], strs[y], ft_strlen(strs[i])) > 0)
		{
			tmp = strs[i];
			strs[i] = strs[y];
			strs[y] = tmp;
			i = 0;
			y = 1;
		}
		else
		{
			i++;
			y++;
		}
	}
}
