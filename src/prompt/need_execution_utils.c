/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_execution_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:19:17 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 12:55:07 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_fork(t_plot *actual, t_param *param, int builtin, int i)
{
	param->child->pid[i] = fork();
	if (param->child->pid[i] == 0)
	{
		dup_pipe(actual, param->child, i);
		close_pipe(param->child, i);
		init_redir(actual);
		close_other_plot_hd(actual, param->plots);
		if (builtin)
			do_builtin(actual, param, builtin, 1);
		else
			do_execve(actual, param, i, actual->path);
	}
	else if (actual->fd_heredoc[0] != -1)
		close_heredoc_fd(actual);
}

void	exe_badcmd_redir(t_plot *actual, t_param *param, int sredir, int i)
{
	if (!sredir && actual->cmd_arg[0])
		handle_bad_command(actual, param->child, i);
	else
	{
		if (!sredir)
		{
			param->child->pid[i] = fork();
			if (param->child->pid[i] == 0)
			{
				dup_pipe(actual, param->child, i);
				close_pipe(param->child, i);
				init_redir(actual);
				exit_program(param);
			}
		}
		else
			param->child->pid[i] = -1;
	}
	read_lost_pipe(param->child, i);
}
