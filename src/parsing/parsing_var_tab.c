/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_var_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:34:02 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/12 07:41:14 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	split_element_without_quote(char *str, int i)
{
	while (str[i] && !ft_char_in_set(str[i], CS_QUOTE))
		i++;
	return (i);
}

static int	split_element(char *str, int *i, int *j)
{
	int	tmp;

	*i = 0;
	*j = 0;
	tmp = 1;
	while (str[*i] != '\0')
	{
		if (str[*i] && ft_char_in_set(str[*i], CS_QUOTE))
		{
			*i = first_quote(str, *i, str[*i]);
			tmp++;
			*i = *i + 1;
		}
		else if (str[*i] && !ft_char_in_set(str[*i], CS_QUOTE))
		{
			*i = split_element_without_quote(str, *i);
			tmp++;
		}
	}
	*i = 0;
	return (tmp);
}

static void	split_inc(int *i, int *tmp, int *j)
{
	*i = *i + 1;
	*j = *j + 1;
	*tmp = *i;
}

char	**split_tmp_var(char *str)
{
	char	**str_split;
	int		i;
	int		tmp;
	int		j;

	tmp = split_element(str, &i, &j);
	str_split = ft_calloc(tmp, sizeof(char *));
	tmp = i;
	while (str[i])
	{
		if (str[i] && ft_char_in_set(str[i], CS_QUOTE))
		{
			i = first_quote(str, i, str[i]);
			str_split[j] = ft_substr(str, tmp, i - tmp + 1);
		}
		else if (str[i] && !ft_char_in_set(str[i], CS_QUOTE))
		{
			while (str[i] && !ft_char_in_set(str[i], CS_QUOTE))
				i++;
			str_split[j] = ft_substr(str, tmp, i - tmp);
			i--;
		}
		split_inc(&i, &tmp, &j);
	}
	return (str_split);
}
