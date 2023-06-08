#include "minishell.h"

char	*var_dol_interogation(char *str, int i)
{
	char	*str1;
	char	*str2;

	str1 = ft_itoa(g_return);
	str2 = ft_substr(str, 0, i - 1);
	str2 = ft_strjoin_free(str2, str1);
	free(str1);
	str1 = ft_substr(str, i + 1, ft_strlen(str) - (i + 1));
	free(str);
	str = ft_strjoin(str2, str1);
	free(str1);
	free(str2);
	return (str);
}

int	interpretation_var_q(char **str, int i, t_env *env, int tmp)
{
	i++;
	while ((*str)[i] && (*str)[i] != '\"')
	{
		if ((*str)[i] == '\"')
			return (i - 1);
		if ((*str)[i] == '$')
		{
			if ((*str)[i + 1] && (*str)[i + 1] == '\"')
			{
				i++;
				break ;
			}
			if ((*str)[i + 1] && (*str)[i + 1] == '?')
				*str = var_dol_interogation(*str, i + 1);
			else
				tmp = interpretation_var(str, i, env);
			i = tmp;
			if (i == -1)
			{
				i = 1;
				break ;
			}
		}
		i++;
	}
	return (i);
}

char	*parsing_variable(char *str, t_env *env)
{
	int	i;
	int	tmp;	

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\'')
			i = first_quote(str, i, '\'');
		if (i == -1 || str[i] == '\0')
			break ;
		tmp = i;
		if (str[i] == '\"')
			tmp = interpretation_var_q(&str, i, env, tmp);
		else if (str[i] == '$')
		{
			if (str[i + 1] && str[i + 1] == '?')
				str = var_dol_interogation(str, i + 1);
			else if (i == 1 && str[i + 1] && str[i - 1] != '\"'
				&& ft_char_in_set(str[i + 1], CS_QUOTE))
				tmp = remove_dol(&str, i);
			else if (str[i + 1] && !is_delim_space(str[i + 1]))
				tmp = interpretation_var(&str, i, env);
			// i = tmp;
		}
		printf("---    %d    ---\n", tmp);
		printf("str == %s\n", str);	
		if (tmp >= 0) 
		{
			if (str[i])
			{
				i = tmp;
				i++;
				printf("\t ---    %d    ---\n", i);
			}
		}
		else if (tmp < 0)
			tmp = i;

	}
	return (str);
}
