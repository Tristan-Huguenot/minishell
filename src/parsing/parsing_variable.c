#include "minishell.h"

void	remove_dol(t_plot *plot, int i)
{
	char	*strtmp;
	char	*strtmp2;
	int		size;

	strtmp2 = ft_strdup(plot->cmd);
	free(plot->cmd);
	plot->cmd = ft_substr(strtmp2, 0, i);
	size = ft_strlen(strtmp2) - i;
	strtmp = ft_substr(strtmp2, i + 1, size);
	plot->cmd = ft_strjoin_free(plot->cmd, strtmp);
	free(strtmp2);
	free(strtmp);
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

char	*interpret_var_changement(t_plot *plot, t_env *env, int i, int tmp)
{
	char	*strtmp;
	char	*strtmp2;
	char	*new;
	int		size;

	size = ft_strlen(plot->cmd) - i;
	strtmp2 = ft_substr(plot->cmd, i + 1, size);
	size = i - tmp;
	strtmp = ft_substr(plot->cmd, tmp + 1, size);
	strtmp = find_var(&strtmp, env);
	new = ft_substr(plot->cmd, 0, tmp);
	free(plot->cmd);
	plot->cmd = ft_strjoin_free(new, strtmp);
	free(strtmp);
	plot->cmd = ft_strjoin_free(plot->cmd, strtmp2);
	free(strtmp2);
	return (plot->cmd);
}

char	*interpretation_var(t_plot *plot, int i, t_env *env)
{
	int		tmp;

	tmp = i;
	i++;
	if (plot->cmd[i] && ft_char_in_set(plot->cmd[i], "\'\""))
	{
		remove_dol(plot, i - 1);
		return (plot->cmd);
	}
	else if (!plot->cmd[i] || !(ft_isalnum(plot->cmd[i])))
		return (plot->cmd);
	while (plot->cmd[i] && ft_isalnum(plot->cmd[i]) == 1)
		i++;
	if (!(ft_isalnum(plot->cmd[i])) || plot->cmd[i] == '|')
		i--;
	plot->cmd = interpret_var_changement(plot, env, i, tmp);
	return (plot->cmd);
}

int	interpretation_var_q(t_plot *plot, int i, t_env *env)
{
	i++;
	while (plot->cmd[i] && plot->cmd[i] != '\"')
	{
		if (plot->cmd[i] == '\"')
			return (i - 1);
		if (plot->cmd[i] == '$')
		{
			if (plot->cmd[i + 1] && plot->cmd[i + 1] == '\"')
			{
				i++;
				break ;
			}
			interpretation_var(plot, i, env);
		}
		i++;
	}
	return (i);
}

void	parsing_variable(t_plot *plot, t_env *env)
{
	int	i;

	i = 0;
	while (plot->cmd && plot->cmd[i])
	{
		if (plot->cmd[i] == '\'')
			i = first_quote(plot->cmd, i, '\'');
		if (i == -1 || plot->cmd[i] == '\0')
			break ;
		if (plot->cmd[i] == '\"')
			i = interpretation_var_q(plot, i, env);
		else if (plot->cmd[i] == '$')
		{
			if (i == 1 && plot->cmd[i + 1] && plot->cmd[i - 1] != '\"'
				&& ft_char_in_set(plot->cmd[i + 1], "\'\""))
				remove_dol(plot, i);
			else if (plot->cmd[i + 1] && !is_delim_space(plot->cmd[i + 1]))
				plot->cmd = interpretation_var(plot, i, env);
		}
		if (plot->cmd[i])
			i++;
	}
}
