#include "minishell.h"

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

int	interpretation_var_q(char **str, int i, int j, t_env *env)
{
	while (str[i][j] && str[i][j] != '\"')
	{
		if (str[i][j] == '$')
		{
			if (str[i][j + 1] && str[i][j + 1] == '\"')
			{
				printf("ici j = %d", j);
				return (j + 1);
			}
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


int	interpretation_dollar(char **str, int i, int j, t_env *env)
{
	if (str[i][0] == '\"')
		j = interpretation_var_q(str, i, j, env);
	if (str[i][j] == '$')
	{
		if (str[i][j + 1] && str[i][j + 1] == '?')
			str[i] = var_dol_interogation(str[i], j + 1);
		else if (str[i][j + 1] && is_delim_space(str[i][j + 1]))
			return (j);
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
		else if (str[i][j + 1] && !is_delim_space(str[i][j + 1]))
			j = interpretation_var(&str[i], j, env);
		if (j == -1)
			return (-1);
		if (!str[i] || str[i][j + 1] == '\0')
			return (j);
	}
	return (j - 1);
}

char	*parsing_variable(char *str, t_env *env)
{
	int		i;
	int		j;
	char	**str_tmp;
	char	*str2;

	str_tmp = split_tmp_var(str);
	free(str);
	i = 0;
	str2 = NULL;
	while (str_tmp[i])
		i++;
	i = 0;
	while (str_tmp[i])
	{
		j = 0;
		if (str_tmp[i][j] != '\'' )
		{
			while (str_tmp[i][j])
			{			
				if (str_tmp[i][j] == '$')
					j = interpretation_dollar(str_tmp, i, j, env);
				j++;
			}
		}
		str2 = ft_strjoin_free(str2, str_tmp[i]);
		i++;
	}
	ft_free_strs(str_tmp);
	return (str2);
}
