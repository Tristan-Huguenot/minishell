#include "minishell.h"

int	is_builtin(char *str)
{
	int	size;

	size = ft_strlen(str) + 1;
	if (!ft_strncmp(str, "echo", size))
		return (ECHO);
	if (!ft_strncmp(str, "cd", size))
		return (CD);
	if (!ft_strncmp(str, "pwd", size))
		return (PWD);
	if (!ft_strncmp(str, "export", size))
		return (EXPORT);
	if (!ft_strncmp(str, "unset", size))
		return (UNSET);
	if (!ft_strncmp(str, "env", size))
		return (ENV);
	if (!ft_strncmp(str, "exit", size))
		return (EXIT);
	return (0);
}

void	do_builtin(t_plot *plot, t_env **envp, int builtin)
{
	if (builtin == ECHO)
		g_return = echo(plot->argc, plot->cmd_arg);
	else if (builtin == CD)
		g_return = 0 ;
	else if (builtin == PWD)
		g_return = 0;// pwd(plot->argc, plot->cmd_arg, envp);
	else if (builtin == EXPORT)
		g_return = ft_export(plot->argc, plot->cmd_arg, *envp);
	else if (builtin == UNSET)
		g_return = unset(plot->argc, plot->cmd_arg, *envp);
	else if (builtin == ENV)
		g_return = 0;
		// env(plot->argc, plot->cmd_arg, envp);
	else if (builtin == EXIT)
		g_return = 0;
}

void	need_execution(t_param *param)
{
	int		builtin;
	
	builtin = is_builtin(param->plots->cmd_arg[0]);
	if (builtin)
		do_builtin(param->plots, &param->env, builtin);
	// else
		// do_execve(param->plots, param->env);

}
