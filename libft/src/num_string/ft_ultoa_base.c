/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 01:23:47 by thugueno          #+#    #+#             */
/*   Updated: 2022/10/27 14:29:30 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_num_string.h"

static int	calculate_digit(unsigned long long int nb, char *base, int div)
{
	int	digit;

	div = ft_strlen(base);
	digit = 0;
	while (nb > 0)
	{
		nb /= div;
		digit++;
	}
	return (digit);
}

static char	*get_str_0(char *base)
{
	char	*str;

	str = ft_calloc(2, sizeof(*str));
	if (!str)
		return (str);
	str[0] = base[0];
	str[1] = '\0';
	return (str);
}

char	*ft_ultoa_base(unsigned long long nb, char *base)
{
	char	*str;
	int		len;
	int		div;
	int		i;

	if (nb == 0)
	{
		str = get_str_0(base);
		return (str);
	}
	div = ft_strlen(base);
	len = calculate_digit(nb, base, div);
	str = ft_calloc(len + 1, sizeof(*str));
	if (!str)
		return (str);
	i = len - 1;
	while (nb > 0)
	{
		str[i] = base[nb % div];
		nb /= div;
		i--;
	}
	str[len] = '\0';
	return (str);
}
