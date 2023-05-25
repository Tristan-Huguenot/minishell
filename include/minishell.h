/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:46:39 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/25 11:15:12 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include "libft.h"
# include "define_error.h"

// vvvv a modifier, pas bon de declarer functions avant struct

# include "color.h"
# include "prompt.h"
# include "parsing.h"

typedef struct s_plot
{
	char			*cmd;
	char			**cmd_arg;
	int				argc;
	char			**in;
	char			**out;
	struct s_plot	*next;
}	t_plot;

typedef struct s_param
{
	char	*progname;
	char	**paths;
}	t_param;

extern int	g_return;

/***FILE	*/

char	*file_is_exe(char *file, char **paths);

/***ERROR	*/

void	error_handler(int err, t_param *param, char *name);

#endif
