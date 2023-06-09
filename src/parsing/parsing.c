#include "minishell.h"

static void	rendering(t_plot *plot, t_env *env)
{
	int	i;

	plot->cmd = parsing_variable(plot->cmd, env);
	i = 0;
	while (plot->redir[i])
	{
		plot->redir[i] = parsing_variable(plot->redir[i], env);
		plot->redir[i] = there_is_quote_to_remove(plot->redir[i]);
		i++;
	}
}

static int	parsing_plot(t_param *param)
{
	t_plot	*tmp;
	int		i;

	tmp = param->plots;
	while (tmp)
	{
		if (parsing_redir(tmp, param))
			return (1);
		rendering(tmp, param->env);
		parsing_arg(tmp);
		i = 0;
		while (tmp->cmd_arg[i])
		{
			tmp->cmd_arg[i] = there_is_quote_to_remove(tmp->cmd_arg[i]);
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	parsing(t_param *param, char *input)
{
	char	quote;

	quote = wrong_quote(input);
	if (quote)
	{
		error_handler(E_WQUOTE, param->progname, &quote);
		return (1);
	}
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
