#include "minishell.h"

void	print_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		printf("\t\t%s\n", strs[i]);
		i++;
	}
}

void	print_plots(t_plot *plots)
{
	int	i;

	i = 1;
	while (plots)
	{
		printf("plot %d:\n", i);
		if (plots->cmd)
			printf("\tcmd : %s\n", plots->cmd);
		if (plots->cmd_arg)
		{
			printf("\tcmd_arg :\n");
			print_strs(plots->cmd_arg);
		}
		if (plots->redir)
		{
			printf("\tredir :\n");
			print_strs(plots->redir);
		}
		i++;
		plots = plots->next;
	}
}

void	prompt_in(t_param *param)
{
	param->input = readline(param->prompt);
	if (!param->input)
		ft_exit(0, NULL, param, 0);
	if (ft_strlen(param->input) != 0)
	{
		add_history(param->input);
		if (!parsing(param, param->input))
		{
			// print_plots(param->plots);
			need_execution(param);
		}
		plotlink_clear(&param->plots);
	}
	if (param->input)
		free(param->input);
}
