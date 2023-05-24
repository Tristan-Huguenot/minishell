/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:26:42 by thugueno          #+#    #+#             */
/*   Updated: 2022/10/04 18:20:18 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (*s != '\0')
		s++;
	while (i > 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
		i--;
	}
	if (*s == (char)c)
		return ((char *)s);
	return ((void *)0);
}
