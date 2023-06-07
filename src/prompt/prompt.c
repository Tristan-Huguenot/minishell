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

void	do_builtin(t_plot *plot, t_env *envp, int builtin)
{
	if (builtin == ECHO)
		g_return = echo(plot->argc, plot->cmd_arg);
	else if (builtin == CD)
		g_return = 0 ;
	else if (builtin == PWD)
		g_return = 0;
	else if (builtin == EXPORT)
		g_return = 0;
	else if (builtin == UNSET)
		g_return = unset(plot->argc, plot->cmd_arg, envp);
	else if (builtin == ENV)
		g_return = 0;
		// env(plot->argc, plot->cmd_arg, envp->);
	else if (builtin == EXIT)
		g_return = 0;
}

void	exit_tmp(t_param *param, char **input_ptr)
{
	/* exit avec bash peut avoir un argument (0-133 inclut) et fonctionne avec les pipes du genre exit 1 | sleep 5
		j ai mis en temporaire psk faudra le gerer une fois le parsing fait
		au moment d executer la cmd > si param->plot->cmd_arg[0] == keyword alors on appel built in
	*/
	free(*input_ptr);
	rl_clear_history();
	g_return = 0;
	exit_program(param);
}

void	print_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		ft_printf("\t\t%s\n", strs[i]);
		i++;
	}
}

void	print_plots(t_plot *plots)
{
	int	i;

	i = 1;
	while (plots)
	{
		ft_printf("plot %d:\n", i);
		if (plots->cmd)
			ft_printf("\tcmd : %s\n", plots->cmd);
		if (plots->cmd_arg)
		{
			ft_printf("\tcmd_arg :\n", i);
			print_strs(plots->cmd_arg);
		}
		if (plots->redir)
		{
			ft_printf("\tredir :\n", i);
			print_strs(plots->redir);
		}
		i++;
		plots = plots->next;
	}
}

void	prompt_in(t_param *param)
{
	char	**tmp_env;
	char	*input;
	int		builtin;

	input = readline(param->prompt);
	if (ft_strlen(input) != 0)
	{
		add_history(input);
		if (ft_strncmp(input, "exit", 5) == 0)
			exit_tmp(param, &input);
		if (!parsing(param, input))
		{
			if (!ft_strncmp(param->plots->cmd_arg[0], "env", 4))
			{
				tmp_env = convert_env_strs(param->env);
				env(param->plots->argc, param->plots->cmd_arg, tmp_env);
				ft_free_strs(tmp_env);
			}
			else
				print_plots(param->plots);
		}
		builtin = is_builtin(param->plots->cmd_arg[0]);
		if (builtin)
			do_builtin(param->plots, param->env, builtin);
		// else
			// do_execve(param->plots, param->env);
		plotlink_clear(&param->plots);
	}
	free(input);
}
