#include "minishell.h"

static void	err_arg(char *name)
{
	ft_printf("%s: too many argments\n", name);
	g_return = 1;
	return ;
}

void	env(int argc, char **argv, char **env)
{
	int	i;

	if (argc > 1)
		return (err_arg(argv[0]));
	i = 0;
	while (env[i])
	{
		ft_printf("%s\n", env[i]);
		i++;
	}
	return ;
}
