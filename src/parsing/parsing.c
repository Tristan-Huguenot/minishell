#include "minishell.h"

int	parsing_plot(t_param *param)
{
	t_plot	*tmp;

	tmp = param->plots;
	while (tmp)
	{
		parsing_variable(tmp, param->env);
		if (parsing_redir(tmp, param))
			return (1);
		// parsing_token(tmp);
		ft_printf("%s\n", tmp->cmd);
		tmp = tmp->next;
	}
	return (0);
}

int	parsing(t_param *param, char *input)
{
	char	quote;

	quote = wrong_quote(input);
	if (quote)
		error_handler(E_WQUOTE, param, &quote);
	else
	{
		init_plots(param, input);
		if (!param->plots)
			return (1);
		if (parsing_plot(param))
			return (1);
	}
	return (0);
}
