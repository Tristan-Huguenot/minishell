#include "minishell.h"

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
	// char	quote;

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
		plotlink_clear(&param->plots);
	}
	free(input);
}
