#include "minishell.h"

int	g_return = 0;

int	main(int argc, char **argv, char **envp)
{
	t_param	*param;

	param = init_param(argv[0] + 2, envp);
	if (argc != 1)
	{
		error_handler(E_ARGC, param, argv[1]);
		exit_program(param);
	}
	while (1)
		prompt_in(param);
	g_return = 0;
	exit_program(param);
}
