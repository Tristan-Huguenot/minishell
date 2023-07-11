/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:34:41 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/11 17:05:42 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *str)
{
	int	size;

	size = ft_strlen(str) + 1;
	if (!ft_strncmp(str, "echo", size))
		return (ECHO);
	if (!ft_strncmp(str, "cd", size))
		return (CD);
	if (!ft_strncmp(str, "pwd", size))
		return (PWD);
	if (!ft_strncmp(str, "export", size))
		return (EXPORT);
	if (!ft_strncmp(str, "unset", size))
		return (UNSET);
	if (!ft_strncmp(str, "env", size))
		return (ENV);
	if (!ft_strncmp(str, "exit", size))
		return (EXIT);
	return (0);
}

void	do_builtin(t_plot *plot, t_param *param, int builtin, int isfork)
{
	char	**tmp;

	tmp = convert_env_strs(param->env);
	signal(SIGPIPE, SIG_IGN);
	if (builtin == ECHO)
		g_return = echo(plot->argc, plot->cmd_arg);
	else if (builtin == CD)
		g_return = cd(plot->argc, plot->cmd_arg, param);
	else if (builtin == PWD)
		g_return = pwd();
	else if (builtin == EXPORT)
		g_return = ft_export(plot->argc, plot->cmd_arg, param);
	else if (builtin == UNSET)
		g_return = unset(plot->argc, plot->cmd_arg, param);
	else if (builtin == ENV)
		g_return = env(plot->argc, plot->cmd_arg, tmp);
	ft_free_strs(tmp);
	signal(SIGPIPE, SIG_DFL);
	if (builtin == EXIT)
		ft_exit(plot->argc, plot->cmd_arg, param, isfork);
	if (isfork)
		exit_program(param);
}

static int	preparation_fork(t_param *param, int builtin, int stateredir)
{
	int		i;
	t_plot	*tmp_head;

	tmp_head = param->plots;
	i = 0;
	while (tmp_head)
	{
		builtin = is_builtin(tmp_head->cmd_arg[0]);
		stateredir = check_open_redir(tmp_head->redir);
		if (init_pipe(i, param->child))
			return (1);
		set_handler_sig_child();
		tmp_head->path = file_is_exe(tmp_head->cmd_arg[0], param->paths);
		if (!stateredir && (tmp_head->path || builtin))
			execute_fork(tmp_head, param, builtin, i);
		else
			exe_badcmd_redir(tmp_head, param, stateredir, i);
		i++;
		close_pipe(param->child, i);
		tmp_head = tmp_head->next;
	}
	close_pipe(param->child, i + 1);
	free(tmp_head);
	return (stateredir);
}

void	need_execution(t_param *param)
{
	int		builtin;
	int		stateredir;
	t_plot	*tmp_head;

	stateredir = 0;
	tmp_head = param->plots;
	if (init_child(plotlink_size(param->plots), param->child))
		return (error_handler(E_CHILD, param->progname, NULL));
	builtin = is_builtin(tmp_head->cmd_arg[0]);
	if (init_heredoc_plots(tmp_head, param->env))
	{
		free_child(param);
		return ;
	}
	set_handler_sig_parent();
	if (plotlink_size(param->plots) == 1 && builtin == EXIT)
	{
		close_heredoc_fd(tmp_head);
		if (!check_open_redir(tmp_head->redir))
			do_builtin(tmp_head, param, builtin, 0);
	}
	else
		stateredir = preparation_fork(param, builtin, stateredir);
	wait_close_childs(param, param->child, stateredir);
}
