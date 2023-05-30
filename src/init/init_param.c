/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:18:36 by thugueno          #+#    #+#             */
/*   Updated: 2023/05/30 12:32:46 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static char	**init_paths(t_param *param, char **envp)
{
	char	*tmp;
	int		i;

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
}

static char	*init_prompt(char *name)
{
	char 	*tmp;
	char	*prompt;

	tmp = ft_strjoin(PROMPTC, name);
}

t_param	*init_param(char *name, char **envp)
{
	char	*tmp;

	param = ft_calloc(1, sizeof(*param));
	if (!param)
		return (param);
	param->progname = prog;
	param->prompt = init_prompt(name);
	init_paths(param, envp);
	return (param);
}
