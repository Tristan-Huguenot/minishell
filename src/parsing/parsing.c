#include "minishell.h"

char	*remove_dol(char *str, int i)
{
	char	*strtmp;
	char	*strtmp2;
	int		size;

	strtmp2 = ft_strdup(str);
	free(str);
	str = ft_substr(strtmp2, 0, i);
	size = ft_strlen(strtmp2) - i;
	strtmp = ft_substr(strtmp2, i + 1, size);
	str = ft_strjoin_free(str, strtmp);
	free(strtmp2);
	free(strtmp);
	return (str);
}

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
		rendering(tmp, param->env);
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
		error_handler(E_WQUOTE, param, &quote);
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
