/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:33:55 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 10:33:56 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	jump_next_charset(char *cmd, int i, char *charset)
{
	while (cmd[i] && !ft_char_in_set(cmd[i], charset))
	{
		if (ft_char_in_set(cmd[i], CS_QUOTE))
			i = first_quote(cmd, i, cmd[i]);
		if (i == -1)
		{
			while (cmd[i + 1])
				i++;
		}
		i++;
	}
	return (i);
}

static void	init_check(int	*i, int *n, int stat[2])
{
	*i = 0;
	*n = 0;
	stat[0] = 0;
	stat[1] = 0;
}

static int	check_redir(t_plot *plot, t_param *param)
{
	int	i;
	int	n;
	int	stat[2];

	init_check(&i, &n, stat);
	i = jump_next_charset(plot->cmd, i, CS_REDIR);
	while (plot->cmd[i])
	{
		n++;
		if (plot->cmd[i] == plot->cmd[i + 1])
			i++;
		i++;
		while (ft_char_in_set(plot->cmd[i], CS_WSPACE))
			i++;
		if (ft_char_in_set(plot->cmd[i], CS_REDIR) || !plot->cmd[i])
		{
			error_redir(i, plot, param);
			n = -1;
			break ;
		}
		i = jump_next_charset(plot->cmd, i, CS_REDIR);
	}
	return (n);
}

int	parsing_redir(t_plot *plot, t_param *param)
{
	int	size;

	size = check_redir(plot, param);
	if (size == -1)
	{
		g_return = ENOENT;
		return (1);
	}
	plot->redir = ft_calloc(size + 1, sizeof(*plot->redir));
	if (!plot->redir)
		return (1);
	move_redir(plot, size);
	return (0);
}
