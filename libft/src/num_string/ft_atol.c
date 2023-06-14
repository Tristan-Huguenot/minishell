/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:07:06 by thugueno          #+#    #+#             */
/*   Updated: 2023/06/14 15:09:06 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_num_string.h"

static void	initiate_var(int *sign, long *nb, int *i, int *y)
{
	*sign = 1;
	*nb = 0;
	*i = 0;
	*y = 0;
}

long	ft_atol(const char *nptr)
{
	int		sign;
	long	nb;
	int		i;
	int		y;

	if (!nptr)
		return (0);
	initiate_var(&sign, &nb, &i, &y);
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] == '0')
		i++;
	while (ft_isdigit(nptr[i + y]))
	{
		nb = nb * 10 + (nptr[i + y] - '0');
		y++;
	}
	return (nb * sign);
}
