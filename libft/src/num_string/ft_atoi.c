/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:52:09 by thugueno          #+#    #+#             */
/*   Updated: 2023/01/16 18:41:00 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_num_string.h"

static void	initiate_var(int *sign, int *nb, int *i, int *y)
{
	*sign = 1;
	*nb = 0;
	*i = 0;
	*y = 0;
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	nb;
	int	i;
	int	y;

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
