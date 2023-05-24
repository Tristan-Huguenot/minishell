/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:46:39 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/24 17:21:16 by thugueno         ###   ########.fr       */
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

typedef struct s_token
{
	char *cmd;
	char **cmd_arg;
	int	 argc;
	char **in;
	char **out;
	t_token *next;
}; t_token;

#endif
