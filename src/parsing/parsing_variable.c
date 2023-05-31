#include "minishell.h"

int	remove_dol(char *str, int i)
{
	char	*str2;
	int		size;

	str2 = ft_strdup(str);
	str = ft_substr(str, 0, i);
	size = ft_strlen(str2) - i;
	str2 = ft_substr(str, i, size);
	str = ft_strjoin_free(str, str2);
	free(str2);
	return (i);
}

int	interpretation_var(char *str, int i)
{
	//int	tmp;

//	tmp = i;
	i++;
	while (str[i] && str[i] != ' ' && str[i] == '	')
	{
		i++;
	}
	return (i);
}

int	interpretation_var_q(char *str, int i)
{
	i++;
	while (str[i] && str[i] == '\"')
	{
		if (str[i] == '\"' || str[i] == ' ' || str[i] == '	')
		{
			while (str[i] && str[i] == '\"')
				i++;
			return (i);
		}
		if (str[i] == '$')
			i = interpretation_var(str, i);
		i++;
	}
	return (i);
}

void	parsing_variable(char *str, t_env *env)
{
	int	i;
	//int	tmp;

	(void)env;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			i = first_quote(str, i, '\'');
		if (str[i] == '\"')
		{
			//tmp = i;
			i = interpretation_var_q(str, i);
		}
		if (str[i] == '$')
		{
			//tmp = i;
			if (str[i + 1] && ((str[i + 1] == '\'') || (str[i + 1] == '\"')))
				remove_dol(str, i);
			else if (str[i + 1] && ((str[i + 1] != ' ') || (str[i + 1] != '	')))
				i = interpretation_var(str, i);
		}
		i++;
	}
}
