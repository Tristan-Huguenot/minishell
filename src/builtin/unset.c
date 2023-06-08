#include "minishell.h"

int	unset(int argc, char **argv, t_env **env)
{
	int	i;

	if (argc == 1)
		return (0);
	i = 1;
	while (argv[i])
	{
		envlink_delvar(env, argv[i]);
		i++;
	}
	return (0);
}
