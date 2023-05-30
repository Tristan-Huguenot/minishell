#include "minishell.h"

int	interpretation_var(char *str, int i)
{
	int	tmp;

	tmp = i;
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
	if (str[i] == '\"' || str[i] == ' ' || str[i] == '	')
	{
		while
		i++;
		return (i);
	}
	while (str[i] && str[i] == '\"')
	{
		if (str[i] == '$')
			i = interpretation_var(str, i);
		i++;
	}
	return (i);
}

void	parsing_variable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			i = first_quote(str, i, '\'');
		if (str[i] == '\"')
			i = interpretation_var_q(str, i);
		if (str[i] == '$')
			i = interpretation_var(str, i);
		i++;
	}
}
