/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:42:31 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/25 11:40:34 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_return = 0;

static void	add_last_slash(char **paths)
{
	char	*tmp;
	int		i;

	i = 0;
	while (paths && paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = tmp;
		i++;
	}
	return ;
}

static t_param	*init(char *prog, char **envp)
{
	t_param	*param;
	char	*tmp;
	int		i;

	param = ft_calloc(1, sizeof(*param));
	if (!param)
		return (param);
	param->progname = prog;
	i = 0;
	while (envp && envp[i] && ft_strncmp("PATH=", envp[i], 5))
		i++;
	if (!envp[i])
		param->paths = NULL;
	else
	{
		param->paths = ft_split(envp[i], ':');
		if (!param->paths)
			return (param);
		tmp = ft_strdup(param->paths[0] + 5);
		free(param->paths[0]);
		param->paths[0] = tmp;
	}
	add_last_slash(param->paths);
	return (param);
}

void	free_param(t_param *param)
{
	if (param && param->paths)
		ft_free_strs(param->paths);
	free(param);
}

int	main(int argc, char **argv, char **envp)
{
	t_param	*param;

	param = init(argv[0] + 2, envp);
	if (argc != 1)
	{
		error_handler(E_ARGC, param, argv[1]);
		free_param(param);
		exit(g_return);
	}
	free_param(param);
	return (0);
}
