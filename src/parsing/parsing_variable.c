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

void	interpretation_var(t_plot *plot, int i, t_env *env)
{
	int		tmp;
	char	*new;
	char	*strtmp;
	char	*strtmp2;

	tmp = i;
	i++;
	if (plot->cmd[i] && ft_char_in_set(plot->cmd[i], "\'\""))
		remove_dol(plot, i - 1);
	else if (!plot->cmd[i] || !(ft_isalnum(plot->cmd[i])))
		return ;
	while (plot->cmd[i] && ft_isalnum(plot->cmd[i]) == 1)
		i++;
	if (!(ft_isalnum(plot->cmd[i])) || plot->cmd[i] == '|')
		i--;
	strtmp2 = ft_substr(plot->cmd, i + 1, ft_strlen(plot->cmd) - i);
	strtmp = ft_substr(plot->cmd, tmp + 1, i - tmp);
	strtmp = find_var(&strtmp, env);
	new = ft_substr(plot->cmd, 0, tmp);
	free(plot->cmd);
	plot->cmd = ft_strjoin_free(new, strtmp);
	free(strtmp);
	plot->cmd = ft_strjoin_free(plot->cmd, strtmp2);
	free(strtmp2);
}

int	interpretation_var_q(t_plot *plot, int i, t_env *env)
{

	i++;
	while (plot->cmd[i] && plot->cmd[i] != '\"')
	{
		if (plot->cmd[i] == '\"')
			return (i - 1);
		if (plot->cmd[i] == '$')
			interpretation_var(plot, i, env);
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
			if (i != 0 && plot->cmd[i + 1] && plot->cmd[i - 1] != '\"'
				&& ft_char_in_set(plot->cmd[i + 1], "\'\""))
				remove_dol(plot, i);
			else if (plot->cmd[i + 1] && !is_delim_space(plot->cmd[i + 1]))
				interpretation_var(plot, i, env);
		}
		if (plot->cmd[i])
			i++;
	}
}
