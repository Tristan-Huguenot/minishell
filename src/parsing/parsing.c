#include "minishell.h"

static void	rendering(t_plot *plot, t_env *env)
{
	int	i;

	i = 0;
	while (plot->cmd_arg[i])
	{
		plot->cmd_arg[i] = parsing_variable(plot->cmd_arg[i], env);
		plot->cmd_arg[i] = there_is_quote_to_remove(plot->cmd_arg[i]);
		i++;
	}
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

	tmp = param->plots;
	while (tmp)
	{
		if (parsing_redir(tmp, param))
			return (1);
		parsing_arg(tmp);
		rendering(tmp, param->env);
		tmp = tmp->next;
	}
	return (0);
}

static int	check_unmanaged_token(t_param *param, char *input)
{
	int		i;
	char	c[2];

	i = 0;
	while (input[i])
	{
		if (ft_char_in_set(input[i], CS_QUOTE))
			i = first_quote(input, i, input[i]);
		if (i == -1)
			return (0);
		if (ft_char_in_set(input[i], CS_UTOKEN))
		{
			c[0] = input[i];
			c[1] = 0;
			error_handler(E_UTOKEN, param->progname, c);
			return (1);
		}
		i++;
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
		if (check_unmanaged_token(param, input))
			return (1);
		init_plots(param, input);
		if (!param->plots)
			return (1);
		if (parsing_plot(param))
			return (1);
	}
	return (0);
}
