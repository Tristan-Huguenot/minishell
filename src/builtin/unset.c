#include "minishell.h"

static int	check_arg(char *arg)
{
	int	i;

	i = 0;
	if (ft_isdigit(arg[i]))
		return (1);
	while (ft_isalnum(arg[i]) || arg[i] == '_')
		i++;
	if (arg[i])
		return (1);
	return (0);
}

int	unset(int argc, char **argv, t_param *param)
{
	int	i;
	int	ret;

	if (argc == 1)
		return (0);
	i = 1;
	ret = 0;
	while (argv[i])
	{
		if (check_arg(argv[i]))
		{
			ret = 1;
			error_handler(E_IDENTIFIER, argv[0], argv[i]);
		}
		else
		{
			envlink_delvar(&param->env, argv[i]);
			if (!ft_strncmp(argv[i], "PATH", ft_strlen("PATH") + 1))
			{
				ft_free_strs(param->paths);
				param->paths = NULL;
			}
		}
		i++;
	}
	return (ret);
}
