/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:30:29 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 10:31:08 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	nlong = ft_atol(arg);
	nstr = ft_ltoa(nlong);
	if (!nstr)
		return (-1);
	i = (arg[0] == '+');
	if (ft_strncmp(arg + i, nstr, ft_strlen(arg + i)) != 0)
	{
		free(nstr);
		return (-1);
	}
	free(nstr);
	nfinal = nlong;
	return (nfinal % 256);
}

void	ft_exit(int argc, char **argv, t_param *param, int isfork)
{
	if (!isfork)
		printf("exit\n");
	if (argc > 2)
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
