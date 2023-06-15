#ifndef MINISHELL_PROTO_H
# define MINISHELL_PROTO_H

extern int	g_return;

/*	INIT	*/

t_param	*init_param(char *name, char **envp);
void	init_plots(t_param *param, char *input);

/*	FILE	*/

char	*file_is_exe(char *file, char **paths);

/*	ERROR	*/

void	error_handler(int err, char *progname, char *name);
void	error_argc(t_param *param, char *file);
void	error_redir(int i, t_plot *plot, t_param *param);

/*	LST		*/

t_env	*envlink_last(t_env *head);
t_env	*envlink_getvar(t_env *head, char *var);
t_env	*envlink_getnextvar(t_env *head, char *var);
t_env	*envlink_new(char *var, char *content);
void	envlink_delvar(t_env **head, char *var);
void	envlink_clear(t_env **head);
void	envlink_addback(t_env **lst, t_env *new);
int		envlink_size(t_env *head);
char	**convert_env_names_strs(t_env *head);
char	**convert_env_strs(t_env *head);
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
void	parsing_redirection(char **input, int st);
char	*parsing_variable(char *str, t_env *env);
int		remove_dol(char **str, int i);
int		remove_dol_num(char **str, int i);
int		interpret_var_changement(char **str, t_env *env, int i, int tmp);
int		interpretation_var(char **str, int i, t_env *env);
char	*find_var(char **str, t_env	*env);
char	**split_tmp_var(char *str);
char	*there_is_quote_to_remove(char *str);

/*	PROMPT	*/

void	prompt_in(t_param *param);
void	need_execution(t_param *param);

/*	EXIT	*/

void	free_param(t_param *param);
void	exit_program(t_param *param);

/*	BUILTIN	*/

int		env(int argc, char **argv, char **env);
int		unset(int argc, char **argv, t_env **env);
int		echo(int argc, char **cmd_arg);
int		pwd(void);
void	sort_strs(char **strs);
<<<<<<< HEAD
int		cd(int argc, char **argv, t_env **env);
=======
void	ft_exit(int argc, char **argv, t_param *param);
>>>>>>> 0d814082da504783338f6c018716c665e5aa7381

	/*	EXPORT	*/

int		ft_export(int argc, char **argv, t_env **env);
void	export_adding(char *arg, char *name, t_env *env);
void	export_create(char *arg, char *name, t_env **env);

#endif
