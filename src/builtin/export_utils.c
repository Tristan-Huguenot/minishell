/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:31:12 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/12 11:48:17 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_adding(char *arg, char **nameptr, t_env *env)
{
	t_env	*link;
	char	*new_cont;

	link = envlink_getvar(env, *nameptr);
	if (link)
	{
		new_cont = ft_strjoin(link->content, arg);
		if (!new_cont)
			return ;
		free(link->content);
		link->content = new_cont;
	}
	free(*nameptr);
	*nameptr = NULL;
}

void	export_create(char *arg, char *name, t_env **env)
{
	t_env	*new;
	char	*cont;
	int		i;

	envlink_delvar(env, name);
	i = 1;
	if (arg[0] == '+')
		i++;
	cont = ft_strdup(arg + i);
	new = envlink_new(name, cont);
	if (!new)
	{
		free(name);
		name = NULL;
		if (cont)
			free(cont);
	}
	envlink_addback(env, new);
}
