/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_proto.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:24:02 by thugueno          #+#    #+#             */
/*   Updated: 2023/06/04 02:04:45 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PROTO_H
# define MINISHELL_PROTO_H

extern int	g_return;

/*	INIT	*/

t_param	*init_param(char *name, char **envp);
void	init_plots(t_param *param, char *input);

/*	FILE	*/

char	*file_is_exe(char *file, char **paths);

/*	ERROR	*/

void	error_handler(int err, t_param *param, char *name);
void	error_redir(int i, t_plot *plot, t_param *param);

/*	LST		*/

t_env	*envlink_last(t_env *head);
t_env	*envlink_getvar(t_env *head, char *var);
t_env	*envlink_new(char *var, char *content);
void	envlink_delvar(t_env *head, char *var);
void	envlink_clear(t_env **head);
void	envlink_addback(t_env **lst, t_env *new);
t_plot	*plotlink_last(t_plot *plots);
t_plot	*plotlink_new(char *cmd);
void	plotlink_addback(t_plot **plots, t_plot *new);
void	delete_plot(t_plot *plot);
void	plotlink_clear(t_plot **plots);

/*	IS_DELIM	*/

int		is_delim(char sep);
int		is_delim_redir(char sep);
int		is_delim_quote(char sep);
int		is_delim_var(char sep);
int		is_delim_space(char sep);


/*	PARSING	*/

int		parsing(t_param *param, char *input);
int		parsing_redir(t_plot *plot, t_param *param);
void	parsing_arg(t_plot *plot);
void	move_redir(t_plot *plot, int size);
int		jump_next_charset(char *cmd, int i, char *charset);
int		first_quote(char *input, int t, char q);
char	wrong_quote(char *input);
void	parsing_prompt(char *input);
void	parsing_redirection(char **input, int st);
void	parsing_variable(t_plot *plot, t_env *env);

/*	PROMPT	*/

void	prompt_in(t_param *param);

/*	EXIT	*/

void	free_param(t_param *param);
void	exit_program(t_param *param);

#endif
