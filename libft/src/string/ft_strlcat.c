/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <huguenot.tristan@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 00:52:42 by thugueno          #+#    #+#             */
/*   Updated: 2022/10/12 15:34:59 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	y;
	size_t	l_src;

	l_src = ft_strlen(src);
	if (dest == NULL && size == 0)
		return (l_src);
	i = ft_strlen(dest);
	if (size <= i)
		return (l_src + size);
	y = 0;
	if (size > 0)
	{
		while (src[y] && y + i < size - 1)
		{
			dest[i + y] = src[y];
			y++;
		}
		dest[i + y] = '\0';
	}
	return (l_src + i);
}
