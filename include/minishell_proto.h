/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_proto.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:24:02 by thugueno          #+#    #+#             */
/*   Updated: 2023/05/30 13:18:19 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PROTO_H
# define MINISHELL_PROTO_H

extern int	g_return;

/*	INIT	*/

t_param	*init_param(char *name, char **envp);

/*	FILE	*/

char	*file_is_exe(char *file, char **paths);

/*	ERROR	*/

void	error_handler(int err, t_param *param, char *name);

/*	PARSING	*/

int		parsing(t_param *param, char *input);
int		wrong_quote(char *input);
int		first_qote(char *input, int t, char q);
void	parsing_prompt(char *input);
void	parsing_redirection(char **input, int st);
void	parsing_variable(char *str, t_env *env);

/*	PROMPT	*/

void	prompt_in(t_param *param);

/*	EXIT	*/

void	free_param(t_param *param);
void	exit_program(t_param *param);

#endif
