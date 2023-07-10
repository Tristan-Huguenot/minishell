/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 08:58:36 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 12:21:54 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H

typedef struct s_plot
{
	char			*cmd;
	char			**cmd_arg;
	int				argc;
	char			**redir;
	int				fd_heredoc[2];
	int				index_hd;
	char			*path;
	struct s_plot	*next;
}	t_plot;

typedef struct s_env
{
	char			*var;
	char			*content;
	struct s_env	*next;
}	t_env;

typedef struct s_child
{
	int	*pid;
	int	even[2];
	int	odd[2];
	int	fdredir[2];
	int	*w_status;
}	t_child;

typedef struct s_param
{
	char	*progname;
	char	*prompt;
	char	*input;
	char	**paths;
	t_plot	*plots;
	t_env	*env;
	t_child	*child;
}	t_param;

#endif
