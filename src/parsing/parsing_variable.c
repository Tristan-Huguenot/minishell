/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:34:10 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/11 01:11:43 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	interpretation_var_q(char **str, int i, int j, t_env *env)
{
	while (str[i][j] && str[i][j] != '\"')
	{
		if (str[i][j] == '$')
		{
			if (str[i][j + 1] && str[i][j + 1] == '\"')
				return (j + 1);
			if (str[i][j + 1] && str[i][j + 1] == '?')
				str[i] = var_dol_interogation(str[i], j + 1);
			else if (str[i][j + 1] && ft_isdigit(str[i][j + 1]))
			{
				remove_dol_num(&str[i], j);
				return (j - 1);
			}
			else
				j = interpretation_var(&str[i], j, env);
		}
		j++;
	}
	return (j);
}

int	interpretation_dol_lastcase(char **str, int i, int j, t_env *env)
{
	if (str[i][j + 1] && is_delim_space(str[i][j + 1]
		&& str[i][j] && str[i][j] != '$'))
		return (j);
	else if (str[i][j + 1] && !is_delim_space(str[i][j + 1]))
		j = interpretation_var(&str[i], j, env);
	else if (str[i][j + 1] && is_delim_space(str[i][j + 1])
		&& str[i][j] && str[i][j] == '$')
		j++;
	return (j);
}

int	interpretation_dollar(char **str, int i, int j, t_env *env)
{
	if (str[i][0] == '\"')
		j = interpretation_var_q(str, i, j, env);
	if (str[i][j] == '$')
	{
		if (str[i][j + 1] && str[i][j + 1] == '?')
			str[i] = var_dol_interogation(str[i], j + 1);
		else if (str[i][j + 1] == '\0' && str[i + 1]
				&& ft_char_in_set(str[i + 1][0], CS_QUOTE))
		{
			remove_dol(&str[i], j);
			return (j - 1);
		}
		else if (str[i][j + 1] && ft_isdigit(str[i][j + 1]))
		{
			remove_dol_num(&str[i], j);
			return (j - 1);
		}
		else
			j = interpretation_dol_lastcase(str, i, j, env);
		if (j == -1)
			return (-1);
		if (!str[i] || str[i][j + 1] == '\0')
			return (j);
	}
	return (j - 1);
}

static void	ft_free(char **str_tmp, char *str)
{
	ft_free_strs(str_tmp);
	free(str);
}

char	*parsing_variable(char *str, t_env *env, int isheredoc)
{
	int		i;
	int		j;
	char	**str_tmp;
	char	*str2;

	str_tmp = create_str_tmp(str, isheredoc);
	i = 0;
	str2 = NULL;
	while (str_tmp && str_tmp[i])
	{
		j = 0;
		if (str_tmp[i][j] != '\'' || isheredoc)
		{
			while (str_tmp[i] && str_tmp[i][j])
			{			
				if (str_tmp[i][j] == '$')
					j = interpretation_dollar(str_tmp, i, j, env);
				j++;
			}
		}
		str2 = ft_strjoin_free(str2, str_tmp[i]);
		i++;
	}
	ft_free(str_tmp, str);
	return (str2);
}
