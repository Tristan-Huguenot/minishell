#include "minishell.h"

int	env(int argc, char **argv, char **env)
{
	int	i;

	if (argc > 1)
	{
		error_handler(E_TMARG, argv[0], NULL);
		return (1);
	}
	i = 0;
	while (env && env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
