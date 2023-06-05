#include "minishell.h"

static void	rendering_variable(t_plot *plot, t_env *env)
{
	int	i;

	i = 0;
	while (plot->cmd_arg[i])
	{
		plot->cmd_arg[i] = parsing_variable(plot->cmd_arg[i], env);
		i++;
	}
	i = 0;
	while (plot->redir[i])
	{
		plot->redir[i] = parsing_variable(plot->redir[i], env);
		i++;
	}
	i = 0;
}

static int	parsing_plot(t_param *param)
{
	t_plot	*tmp;

	tmp = param->plots;
	while (tmp)
	{
		if (parsing_redir(tmp, param))
			return (1);
		parsing_arg(tmp);
		rendering_variable(tmp, param->env);
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
