/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:34:25 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 10:34:26 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	first_quote(char *input, int i, char q)
{
	if (!input)
		return (-1);
	i++;
	while (input[i] != q)
	{
		if (input[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}

char	wrong_quote(char *input)
{
	char	c;

	if (!input)
		return (-1);
	while (*input)
	{
		if (*input == '\'')
		{
			input = ft_strchr(input + 1, '\'');
			c = '\'';
		}
		else if (*input == '\"')
		{
			input = ft_strchr(input + 1, '\"');
			c = '\"';
		}
		if (!input)
		{
			g_return = EINVAL;
			return (c);
		}
		c = 0;
		input++;
	}
	return (c);
}
