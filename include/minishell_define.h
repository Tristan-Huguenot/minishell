/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_define.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:24:02 by thugueno          #+#    #+#             */
/*   Updated: 2023/06/10 17:02:08 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_DEFINE_H
# define MINISHELL_DEFINE_H

/*	COLORS	*/

# define NOC     "\001\e[0m\002"
# define PROMPTC "\001\e[1m\e[38;5;207m\002"

/*	CHARSET	*/

# define CS_WSPACE " \b\t\n\v\f\r"
# define CS_QUOTE "\'\""
# define CS_REDIR "<>"
# define CS_UTOKEN "\\\;\#\&\(\)"

/*	ENUM ERRORS	*/

enum e_error {
	E_ARGC = 1000,
	E_WQUOTE,
	E_TOKEN,
	E_UTOKEN,
	E_IDENTIFIER,
};

/* ENUM BUILTIN */

enum e_builtin {
	ECHO = 1,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT,
};

#endif
