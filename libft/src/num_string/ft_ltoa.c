/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:32:54 by thugueno          #+#    #+#             */
/*   Updated: 2023/06/14 15:33:57 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_num_string.h"

static char	*fill_itoa(int n, unsigned long nb, long int div, char *str)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		i++;
	}
	while (div > 0)
	{
		str[i] = (nb / div) % 10 + '0';
		div /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_ltoa(long n)
{
	unsigned long	nb;
	long int		div;
	int				len;
	char			*str;

	len = 0;
	if (n < 0)
		len += 1;
	nb = n;
	if (n < 1)
		nb *= -1;
	div = 1;
	while (nb / (div * 10) > 0)
	{
		div *= 10;
		len++;
	}
	len++;
	str = malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (str);
	str = fill_itoa(n, nb, div, str);
	return (str);
}
