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
// printf("ici au debut i = %d\n", i);

//	printf("str : %s\n", *str);
	size = ft_strlen(*str) - i;
	strtmp2 = ft_substr(*str, i + 1, size);
//	printf("___strtmp2 : %s\n", strtmp2);
	size = i - tmp;
	strtmp = ft_substr(*str, tmp + 1, size);
///	printf("strtmp : %s\n", strtmp);
	strtmp = find_var(&strtmp, env);
	if(!strtmp)
	{
		// printf("OH NO!!!!!!!!!!\n");
		i = tmp - 1; 
	}
	else
		i = tmp + ft_strlen(strtmp) - 1;
	//printf("+++___strtmp : %s\n", strtmp);
	new = ft_substr(*str, 0, tmp);
//	printf("new+++___ : %s\n", new);
	free(*str);
	*str = ft_strjoin_free(new, strtmp);
	free(strtmp);
	//printf("___________________________________________\n");
//	printf("str : %s\n", *str);
//	printf("___strtmp2 : %s\n", strtmp2);
//	printf("___________________________________________\n");
	*str = ft_strjoin_free(*str, strtmp2);
//	printf("str[0] = %c--\n", (*str)[0]);
	free(strtmp2);
//	printf("\n--i = %d\n", i);
//	printf(" -----le dernier-----     str :%s|\n", *str);
	printf("ici i = %d\n", i);
	return (i);
}

int	interpretation_var(char **str, int i, t_env *env)
{
	int		tmp;

	tmp = i;
	i++;
	// printf("----------interpretation_ var %s", (*str));
	// printf("index %d", i);
	// printf("----------interpretation_ var %c", (*str)[i]);
	if ((*str)[i] && ft_char_in_set((*str)[i], CS_QUOTE) && (*str)[0] != '\"')
	{
		i = remove_dol(str, i - 1);
		return (i);
	}
	else if (!(*str)[i] || !(ft_isalnum((*str)[i]) || (*str)[i] == '_'))
	{
		// printf(" quoi quoi (*str)[i] == %c\n", (*str)[i]);
		return (i + 1);
	}
	while ((*str)[i] && (ft_isalnum((*str)[i]) || (*str)[i] == '_'))
		i++;
	if (!(ft_isalnum((*str)[i])) || (*str)[i] == '|')
		i--;
	i = interpret_var_changement(str, env, i, tmp);
	// printf("\n--i = %d\n", i);

	return (i);
}

int	remove_dol(char **str, int i)
{
	char	*strtmp;
	char	*strtmp2;
	int		size;

	strtmp2 = ft_strdup(*str);
	free(*str);
	*str = ft_substr(strtmp2, 0, i);
	size = ft_strlen(strtmp2) - i;
	strtmp = ft_substr(strtmp2, i + 1, size);
	*str = ft_strjoin_free(*str, strtmp);
	free(strtmp2);
	free(strtmp);
	return (i - 1);
}

int	remove_dol_num(char **str, int i)
{
	char	*strtmp;
	char	*strtmp2;
	int		size;

	// printf("str : %s\n", *str);
	// printf("coucou\n");
	strtmp2 = ft_strdup(*str);
	free(*str);
	*str = ft_substr(strtmp2, 0, i);
	// printf("str : %s\n", *str);
	size = ft_strlen(strtmp2) - i + 1;
	strtmp = ft_substr(strtmp2, i + 2, size);
	*str = ft_strjoin_free(*str, strtmp);
	// printf("str : %s\n", *str);
	free(strtmp2);
	free(strtmp);
	return (i - 1);
}
