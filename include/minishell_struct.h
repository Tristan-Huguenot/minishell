/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:24:02 by thugueno          #+#    #+#             */
/*   Updated: 2023/05/30 16:39:30 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H

typedef struct s_plot
{
	char			*cmd;
	char			**cmd_arg;
	int				argc;
	char			**in;
	char			**out;
	struct s_plot	*next;
}	t_plot;

typedef struct s_env
{
	char			*var;
	char			*content;
	struct s_env	*next;
}	t_env;

typedef struct s_param
{
	char	*progname;
	char	*prompt;
	char	**paths;
	t_plot	*plots;
	t_env	*env;
}	t_param;

#endif
