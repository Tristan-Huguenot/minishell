/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_var_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:34:04 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 10:34:05 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**create_str_tmp(char *str, int isheredoc)
{
	char	**str_tmp;

	if (!isheredoc)
		str_tmp = split_tmp_var(str);
	else
	{
		str_tmp = ft_calloc(2, sizeof(*str_tmp));
		if (!str_tmp)
			return (str_tmp);
		str_tmp[0] = ft_strdup(str);
	}
	return (str_tmp);
}

char	*var_dol_interogation(char *str, int i)
{
	char	*str1;
	char	*str2;

	str1 = ft_itoa(g_return);
	str2 = ft_substr(str, 0, i - 1);
	str2 = ft_strjoin_free(str2, str1);
	free(str1);
	if (str[i + 1])
		str1 = ft_substr(str, i + 1, ft_strlen(str) - (i));
	else
		str1 = ft_substr(str, i + 1, 1);
	free(str);
	str = ft_strjoin_free(str2, str1);
	free(str1);
	return (str);
}
