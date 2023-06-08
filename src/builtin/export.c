#include "minishell.h"

void	print_env(t_env *env)
{
	char	**names;
	int		i;

	names = convert_env_names_strs(env);
	if (!names)
		return ;
	sort_strs(names);
	i = 0;
	while (names[i])
	{
		if (ft_strncmp(names[i], "_", 2) != 0)
			printf("declare -x %s=\"%s\"\n", names[i], \
			(envlink_getvar(env, names[i]))->content);
		i++;
	}
}

int	ft_export(int argc, char **argv, t_env *env)
{
	if (argc == 1)
	{
		print_env(env);
		return (0);
	}
	(void)argv;
	return (0);
}
