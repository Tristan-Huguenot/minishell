#include "minishell.h"

char	*find_var(char **str, t_env	*env)
{
	int		size;
	int		size_st;

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

int	interpret_var_changement(char **str, t_env *env, int i, int tmp)
{
	char	*strtmp;
	char	*strtmp2;
	char	*new;
	int		size;

	size = ft_strlen(*str) - i;
	strtmp2 = ft_substr(*str, i + 1, size);
	size = i - tmp;
	strtmp = ft_substr(*str, tmp + 1, size);
	strtmp = find_var(&strtmp, env);
	if (!(strtmp))
	{
		// printf("dflsmf\n" );
		i = -1;
	}
	new = ft_substr(*str, 0, tmp);
	free(*str);
	*str = ft_strjoin_free(new, strtmp);
	free(strtmp);
	*str = ft_strjoin_free(*str, strtmp2);
	free(strtmp2);
	// printf("\t---i  =  %d --------------\n", i);
	return (i);
}

int	interpretation_var(char **str, int i, t_env *env)
{
	int		tmp;

	tmp = i;
	i++;
	if ((*str)[i] && ft_char_in_set((*str)[i], CS_QUOTE))
	{
		i = remove_dol(str, i - 1);
		return (i);
	}
	else if (!(*str)[i] || !(ft_isalnum((*str)[i])))
		return (i);
	while ((*str)[i] && ft_isalnum((*str)[i]) == 1)
		i++;
	if (!(ft_isalnum((*str)[i])) || (*str)[i] == '|')
		i--;
	i = interpret_var_changement(str, env, i, tmp);
	// printf("---i  =  %d --------------\n", i);
	return (i);
}

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
			i = interpretation_var_q(&str, i, env, tmp);
		else if (str[i] == '$')
		{
			if (str[i + 1] && str[i + 1] == '?')
				str = var_dol_interogation(str, i + 1);
			else if (i == 1 && str[i + 1] && str[i - 1] != '\"'
				&& ft_char_in_set(str[i + 1], CS_QUOTE))
				tmp = remove_dol(&str, i);
			else if (str[i + 1] && !is_delim_space(str[i + 1]))
				tmp = interpretation_var(&str, i, env);
			i = tmp;
		}
		// printf("---%d---\n", i);
		// printf("str == %s\n", str);	
		if (i >= 0) 
		{
			if (str[i])
				i++;
		}
		else if (i < 0)
			i = 0;

	}
	return (str);
}
