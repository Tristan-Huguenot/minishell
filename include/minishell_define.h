/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_define.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:24:02 by thugueno          #+#    #+#             */
/*   Updated: 2023/06/03 02:39:42 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_DEFINE_H
# define MINISHELL_DEFINE_H

/*	COLORS	*/

# define NOC "\033[0m"
# define PROMPTC "\033[38;5;207m"

/*	ERRORS	*/

# define E_ARGC 1000
# define E_WQUOTE 1001
# define E_TOKEN 1002

/*	CHARSET	*/

# define CS_WSPACE " \b\t\n\v\f\r"
# define CS_QUOTE "\'\""
# define CS_REDIR "<>"

#endif
