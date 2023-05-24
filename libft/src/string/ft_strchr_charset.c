/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_charset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 04:35:48 by thugueno          #+#    #+#             */
/*   Updated: 2022/10/22 04:49:07 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

int	ft_strchr_charset(char *s, char *charset)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (ft_char_in_set(*s, charset))
			return (1);
		s++;
	}
	return (0);
}
