/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:20:21 by thugueno          #+#    #+#             */
/*   Updated: 2023/02/04 18:34:54 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0 || (!s1 || !s2))
		return (0);
	while (n > 0 && (*(unsigned char *)s1 == *(unsigned char *)s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((int)(*(unsigned char *)s1 - *(unsigned char *)s2));
}
