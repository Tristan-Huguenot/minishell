/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:27:32 by thugueno          #+#    #+#             */
/*   Updated: 2023/02/04 18:35:11 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	bytes;
	void	*memptr;

	if (size == 0 || nmemb == 0)
	{
		memptr = malloc(0);
		return (memptr);
	}
	bytes = nmemb * size;
	if (bytes / size != nmemb)
		return (NULL);
	memptr = malloc(bytes);
	if (memptr == NULL)
		return (NULL);
	ft_bzero(memptr, bytes);
	return (memptr);
}
