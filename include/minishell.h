/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:46:39 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/24 23:13:04 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "prompt.h"
# include "parsing.h"
# include "libft.h"
# include "color.h"

int	g_return = 0;

typedef struct s_plot
{
	char	*cmd;
	char	**cmd_arg;
	int		argc;
	char	**in;
	char	**out;
	t_plot	*next;
}	t_plot;

#endif
