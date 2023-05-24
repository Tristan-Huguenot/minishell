/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <huguenot.tristan@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:01:20 by thugueno          #+#    #+#             */
/*   Updated: 2022/10/18 15:25:25 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	if (!s1 && !s2)
		return (NULL);
	len = 0;
	if (s1)
		len += ft_strlen(s1);
	if (s2)
		len += ft_strlen(s2);
	str = ft_calloc(len + 1, sizeof(*str));
	if (!str)
		return (str);
	if (s1)
		ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	if (s2)
		ft_strlcat(str, s2, len + 1);
	return (str);
}
