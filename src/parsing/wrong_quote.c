/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:29:06 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/25 00:49:36 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	first_quote(char *input, int i, char q)
{
	char	*str;
	int		size;
	int		tmp;

	i++;
	tmp = i;
	while (input[i] != q)
	{
		if (input[i] == '\0')
		{
			ft_putendl_fd("your quote is note close", 2);
			g_return = EPERM;
			return (-1);
		}
		i++;
	}
	return (i);
}

int	wrong_quote(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'')
			i = first_quote(input, i, '\'');
		if (input[i] == '\"')
			i = first_quote(input, i, '\"');
		if (i == -1)
			return (1);
		i++;
	}
	return (0);
}
