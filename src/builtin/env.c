#include "minishell.h"

int	env(int argc, char **argv, char **env)
{
	int	i;

	if (argc > 1)
	{
		printf("%s: too many argments\n", argv[0]);
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
