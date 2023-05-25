/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:01:30 by thugueno          #+#    #+#             */
/*   Updated: 2023/05/08 14:26:28 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

int	ft_free_strs(char **strs)
{
	int	i;

	if (!strs)
		return (1);
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (0);
}
