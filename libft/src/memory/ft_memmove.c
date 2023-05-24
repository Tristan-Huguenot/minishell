/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:11:41 by thugueno          #+#    #+#             */
/*   Updated: 2023/02/04 18:33:53 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!n || (!dest || !src))
		return ((void *)0);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else if (dest > src)
		ft_memrcpy(dest, src, n);
	return (dest);
}
