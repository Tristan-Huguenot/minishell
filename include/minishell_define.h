/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_define.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:24:02 by thugueno          #+#    #+#             */
/*   Updated: 2023/06/07 15:00:43 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_DEFINE_H
# define MINISHELL_DEFINE_H

/*	COLORS	*/

# define NOC     "\001\e[0m\002"            /* "\033\001[0m"*/
# define PROMPTC "\001\e[1m\e[38;5;207m\002"         /*"\033\001[38;5;207m"*/

/*	ERRORS	*/

# define E_ARGC 1000
# define E_WQUOTE 1001
# define E_TOKEN 1002

/*	CHARSET	*/

# define CS_WSPACE " \b\t\n\v\f\r"
# define CS_QUOTE "\'\""
# define CS_REDIR "<>"

/* ENUM BUILTIN */

enum {
	ECHO = 1,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT,
};

#endif
