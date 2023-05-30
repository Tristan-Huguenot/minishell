#include "minishell.h"

int	first_quote(char *input, int i, char q)
{
	if (!input)
		return (-1);
	i++;
	while (input[i] != q)
	{
		if (input[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}

int	wrong_quote(char *input)
{
	int	i;

	if (!input)
		return (-1);
	i = 0;
	while (input[i])
	{
		if (input[i] == '\'')
			i = first_quote(input, i, '\'');
		if (input[i] == '\"')
			i = first_quote(input, i, '\"');
		if (i == -1)
		{
			ft_putendl_fd("your quote is note close", 2);
			g_return = EINVAL;
			return (1);
		}
		i++;
	}
	return (0);
}
