/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 00:50:45 by thugueno          #+#    #+#             */
/*   Updated: 2023/02/16 18:28:44 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

/*
*	ft_memrcpy:
*
*	It will copy the n bytes from src to dest but only n bytes,
*	starting at the end of src & dest
*	
*	@param	void *dest:	destination for the copy
*	@param	void *src:	source for the copy
*	@param	size_t	n:	number of bytes to copy
*
*	@return	pointer to the n byte of dest starting at end or NULL in case of error
*
*	@error	dest or src == NULL
*/
void	*ft_memrcpy(void *dest, const void *src, size_t n)
{
	char	*c_dest;

	if (!dest || !src)
		return ((void *)0);
	c_dest = dest + (n - 1);
	src += (n - 1);
	while (n > 0)
	{
		*c_dest = *(char *)src;
		c_dest--;
		src--;
		n--;
	}
	return (dest);
}
