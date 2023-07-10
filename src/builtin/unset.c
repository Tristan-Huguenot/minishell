/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:35:03 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 10:35:04 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	delete_var(char *argv, t_param *param)
{
	envlink_delvar(&param->env, argv);
	if (!ft_strncmp(argv, "PATH", ft_strlen("PATH") + 1))
	{
		ft_free_strs(param->paths);
		param->paths = NULL;
	}
}

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
			delete_var(argv[i], param);
		i++;
	}
	return (ret);
}
