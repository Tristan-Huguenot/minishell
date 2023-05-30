#include "minishell.h"

int	parsing_plot(t_param *param)
{
	t_plot	*tmp;

	tmp = param->plots;
	while (tmp)
	{
		parsing_variable(tmp->cmd, param->env);
		// if (parsing_redir(tmp, param))
			// return (1);
		// parsing_token(tmp);
		tmp= tmp->next;
	}
	return (0);
}

int	parsing(t_param *param, char *input)
{
	// int ret;

	if ((wrong_quote(input)) != 0)
		return (1);
	// init_plots(param, input);
	parsing_plot(param);
	return (0);
}
