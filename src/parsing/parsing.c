#include "minishell.h"

int	parsing_plot(t_param *param)
{
	t_plot	*tmp;

	tmp = param->plots;
	parsing_variable(param->plots, param->env);
	while (tmp)
	{
		// parsing_variable(tmp->cmd, param->env);
		// if (parsing_redir(tmp, param))
			// return (1);
		// parsing_token(tmp);
		tmp= tmp->next;
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
		ft_printf("%s\n", input);// int ret;
		param->plots = ft_calloc(1, sizeof(*param->plots));
		param->plots->cmd = input;
		// init_plots(param, input);
		parsing_plot(param);
		free(param->plots->cmd);
		free(param->plots);
	}
	return (0);
}
