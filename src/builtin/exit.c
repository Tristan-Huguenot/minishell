#include "minishell.h"

static void	handle_non_numeric(char **argv, t_param *param)
{
	char	*tmp;

	tmp = ft_strjoin(argv[0], ": ");
	tmp = ft_strjoin_free(tmp, argv[1]);
	error_handler(E_NUMARG, param->progname, tmp);
	free(tmp);
	g_return = ENOENT;
}

static int	check_arg(char *arg)
{
	char			*nstr;
	long			nlong;
	unsigned int	nfinal;
	int				i;

	printf("narg : %s\n", arg);
	nlong = ft_atol(arg);
	printf("nlong : %ld\n", nlong);
	nstr = ft_ltoa(nlong);
	printf("nstr : %s\n", nstr);
	if (!nstr)
		return (-1);
	i = (arg[0] == '+' || arg[0] == '-');
	if (ft_strncmp(arg + i, nstr, ft_strlen(arg + i)) != 0)
	{
		free(nstr);
		return (-1);
	}
	free(nstr);
	nfinal = nlong;
	return (nfinal % 256);
}

void	ft_exit(int argc, char **argv, t_param *param)
{
	printf("exit\n");
	if (argc <= 1)
		g_return = 0;
	else if (argc > 2)
	{
		if (check_arg(argv[1]) != -1)
		{
			error_handler(E_TMARG, param->progname, argv[0]);
			g_return = EPERM;
			return ;
		}
		else
			handle_non_numeric(argv, param);
	}
	else if (argc == 2)
	{
		if (check_arg(argv[1]) != -1)
			g_return = check_arg(argv[1]);
		else
			handle_non_numeric(argv, param);
	}
	exit_program(param);
}
