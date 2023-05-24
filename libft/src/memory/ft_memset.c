/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:55:31 by thugueno          #+#    #+#             */
/*   Updated: 2023/02/04 18:35:33 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*cast;

	if (!s)
		return ((void *)0);
	cast = s;
	while (n > 0)
	{
		*cast = c;
		cast++;
		n--;
	}
	return (s);
}
