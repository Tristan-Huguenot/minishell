/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:52:24 by thugueno          #+#    #+#             */
/*   Updated: 2023/02/16 18:59:15 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

/*
*	ft_memcpy:
*
*	It will copy the memory from src to dest 
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*c_dest;

	if (!n || (!dest || !src))
		return ((void *)0);
	c_dest = dest;
	while (n > 0)
	{
		*c_dest = *(char *)src;
		c_dest++;
		src++;
		n--;
	}
	return (dest);
}
