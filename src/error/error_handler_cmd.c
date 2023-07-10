/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:31:48 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 17:01:04 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	command_contain_slash(t_plot *plot)
{
	if (file_is_dir(plot->cmd_arg[0]))
	{
		g_return = 126;
		ft_fprintf(2, "%s: %s\n", plot->cmd_arg[0], strerror(EISDIR));
	}
	else if (!access(plot->cmd_arg[0], F_OK))
	{
		g_return = 126;
		ft_fprintf(2, "%s: %s\n", plot->cmd_arg[0], strerror(EACCES));
	}
	else
		ft_fprintf(2, "%s: %s\n", plot->cmd_arg[0], strerror(ENOENT));
}

static void	command_start_slash(t_plot *plot)
{
	if (!file_is_dir(plot->cmd_arg[0]))
		ft_fprintf(2, "%s: %s\n", plot->cmd_arg[0], strerror(ENOENT));
	else
	{
		g_return = 126;
		ft_fprintf(2, "%s: %s\n", plot->cmd_arg[0], strerror(EISDIR));
	}
}

void	handle_bad_command(t_plot *plot, t_child *child, int state)
{
	child->pid[state] = -1;
	g_return = 127;
	if (!plot->cmd_arg || !plot->cmd_arg[0])
	{
		g_return = 0;
		return ;
	}
	if (plot->cmd_arg[0][0] == '/')
		command_start_slash(plot);
	else if (ft_strchr(plot->cmd_arg[0], '/'))
		command_contain_slash(plot);
	else
		ft_fprintf(2, "%s: command not found\n", plot->cmd_arg[0]);
}
