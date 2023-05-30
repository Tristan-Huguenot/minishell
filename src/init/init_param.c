/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:18:36 by thugueno          #+#    #+#             */
/*   Updated: 2023/05/31 00:51:38 by thugueno         ###   ########.fr       */
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

static void	init_paths(t_param *param)
{
	t_env	*path;

	path = envlink_getvar(param->env, "PATH");
	if (!path)
		param->paths = NULL;
	else
	{
		param->paths = ft_split(path->content, ':');
		if (!param->paths)
			return ;
		add_last_slash(param->paths);
	}
}

static void	init_env(t_param *param, char **envp)
{
	int	i;
	int y;

	i = 0;
	while (envp[i])
	{
		y = 0;
		while (envp[i][y] != '=')
			y++;
		envlink_addback(&param->env, envlink_new(ft_substr(envp[i], 0, y), \
		ft_strdup(envp[i] + y + 1)));
		i++;
	}
}

static char	*init_prompt(char *name)
{
	char 	*tmp;
	char	*prompt;

	prompt = ft_strjoin(PROMPTC, name);
	tmp = ft_strjoin(prompt, " $> ");
	free(prompt);
	prompt = ft_strjoin(tmp, NOC);
	free(tmp);
	return (prompt);
}

t_param	*init_param(char *name, char **envp)
{
	t_param	*param;

	param = ft_calloc(1, sizeof(*param));
	if (!param)
		return (param);
	param->progname = name;
	param->prompt = init_prompt(name);
	init_env(param, envp);
	init_paths(param);
	return (param);
}
