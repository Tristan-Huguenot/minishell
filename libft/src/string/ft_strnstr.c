/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:45:02 by thugueno          #+#    #+#             */
/*   Updated: 2022/09/29 09:42:10 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;

	i = 0;
	if (!little[i])
		return ((char *)big);
	while (i < len && big[i])
	{
		y = 0;
		while (i + y < len && big[i + y] == little[y] && big[i + y])
		{
			y++;
			if (little[y] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
