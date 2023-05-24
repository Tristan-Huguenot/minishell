/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:29:06 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/24 20:56:46 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	quote_need_end(char *str)
{
	printf("%s", str);
	exit(0);
}

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
			size = ft_strlen(input) - tmp;
			str = ft_substr(input, tmp, size);
			quote_need_end(str);
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
		if (input[i] == '"')
			i = first_quote(input, i, '\"');
		i++;
	}
	return (0);
}
