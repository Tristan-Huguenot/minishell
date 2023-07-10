/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:33:52 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 10:33:53 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_arg(char *str)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	while (str[i])
	{
		while (ft_char_in_set(str[i], CS_WSPACE))
			i++;
		if (!str[i])
			return (c);
		c++;
		i = jump_next_charset(str, i, CS_WSPACE);
	}
	return (c);
}

void	parsing_arg(t_plot *plot)
{
	char	*tmp;
	int		i;
	int		start;
	int		end;

	plot->argc = count_arg(plot->cmd);
	plot->cmd_arg = ft_calloc(plot->argc + 1, sizeof(*plot->cmd_arg));
	if (!plot->cmd_arg)
		return ;
	i = 0;
	while (i < plot->argc)
	{
		start = 0;
		while (ft_char_in_set(plot->cmd[start], CS_WSPACE))
			start++;
		end = jump_next_charset(plot->cmd, start, CS_WSPACE);
		plot->cmd_arg[i] = ft_substr(plot->cmd, start, end - start);
		tmp = ft_strdup(plot->cmd + end);
		free(plot->cmd);
		plot->cmd = tmp;
		i++;
	}
}
