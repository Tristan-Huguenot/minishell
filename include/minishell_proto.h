/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_proto.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:24:02 by thugueno          #+#    #+#             */
/*   Updated: 2023/05/31 02:10:34 by thugueno         ###   ########.fr       */
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

/*	LST		*/

t_env	*envlink_getvar(t_env *head, char *var);
t_env	*envlink_last(t_env *head);
t_env	*envlink_new(char *var, char *content);
void	envlink_delvar(t_env *head, char *var);
void	envlink_clear(t_env **head);
void	envlink_addback(t_env **lst, t_env *new);

/*	PARSING	*/

int		parsing(t_param *param, char *input);
int		first_quote(char *input, int t, char q);
char	wrong_quote(char *input);
void	parsing_prompt(char *input);
void	parsing_redirection(char **input, int st);
void	parsing_variable(char *str, t_env *env);

/*	PROMPT	*/

void	prompt_in(t_param *param);

/*	EXIT	*/

void	free_param(t_param *param);
void	exit_program(t_param *param);

#endif
