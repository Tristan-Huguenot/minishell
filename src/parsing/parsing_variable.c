#include "minishell.h"

char	*remove_dol(char *str, int i)
{
	char	*strtmp;
	char	*strtmp2;
	int		size;

	strtmp2 = ft_strdup(str);
	free(str);
	str = ft_substr(strtmp2, 0, i);
	size = ft_strlen(strtmp2) - i;
	strtmp = ft_substr(strtmp2, i + 1, size);
	str = ft_strjoin_free(str, strtmp);
	free(strtmp2);
	free(strtmp);
	return (str);
}

char	*find_var(char **str, t_env	*env)
{
	int	size;
	int	size_st;

	size_st = ft_strlen(*str);
	while (env)
	{
		size = ft_strlen(env->var);
		if (size_st == size)
		{
			if (ft_strncmp(*str, env->var, size) == 0)
			{
				free(*str);
				*str = ft_strdup(env->content);
				return (*str);
			}
		}
		env = env->next;
	}
	free(*str);
	return (NULL);
}

char	*interpret_var_changement(char *str, t_env *env, int i, int tmp)
{
	char	*strtmp;
	char	*strtmp2;
	char	*new;
	int		size;

	size = ft_strlen(str) - i;
	strtmp2 = ft_substr(str, i + 1, size);
	size = i - tmp;
	strtmp = ft_substr(str, tmp + 1, size);
	strtmp = find_var(&strtmp, env);
	new = ft_substr(str, 0, tmp);
	free(str);
	str = ft_strjoin_free(new, strtmp);
	free(strtmp);
	str = ft_strjoin_free(str, strtmp2);
	free(strtmp2);
	return (str);
}

char	*interpretation_var(char *str, int i, t_env *env)
{
	int		tmp;

	tmp = i;
	i++;
	if (str[i] && ft_char_in_set(str[i], CS_QUOTE))
	{
		str = remove_dol(str, i - 1);
		return (str);
	}
	else if (!str[i] || !(ft_isalnum(str[i])))
		return (str);
	while (str[i] && ft_isalnum(str[i]) == 1)
		i++;
	if (!(ft_isalnum(str[i])) || str[i] == '|')
		i--;
	str = interpret_var_changement(str, env, i, tmp);
	return (str);
}

int	interpretation_var_q(char **str, int i, t_env *env)
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
			*str = interpretation_var(*str, i, env);
		}
		i++;
	}
	return (i);
}

char	*parsing_variable(char *str, t_env *env)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\'')
			i = first_quote(str, i, '\'');
		if (i == -1 || str[i] == '\0')
			break ;
		if (str[i] == '\"')
			i = interpretation_var_q(&str, i, env);
		else if (str[i] == '$')
		{
			if (i == 1 && str[i + 1] && str[i - 1] != '\"'
				&& ft_char_in_set(str[i + 1], CS_QUOTE))
				str = remove_dol(str, i);
			else if (str[i + 1] && !is_delim_space(str[i + 1]))
				str = interpretation_var(str, i, env);
		}
		if (str[i])
			i++;
	}
	return (str);
}
