/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:15:52 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 10:33:23 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*envlink_last(t_env *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

t_env	*envlink_new(char *var, char *content)
{
	t_env	*new_link;

	new_link = ft_calloc(1, sizeof(*new_link));
	if (!new_link)
		return (new_link);
	new_link->var = var;
	new_link->content = content;
	new_link->next = NULL;
	return (new_link);
}

void	envlink_delvar(t_env **head, char *var)
{
	t_env	*tmp[2];

	if (!*head)
		return ;
	tmp[0] = *head;
	if (!ft_strncmp(var, tmp[0]->var, ft_strlen(var)))
	{	
		if (tmp[0]->var)
			free(tmp[0]->var);
		if (tmp[0]->content)
			free(tmp[0]->content);
		*head = (*head)->next;
		free(tmp[0]);
		return ;
	}
	tmp[0] = envlink_getnextvar(tmp[0], var);
	if (!tmp[0] || !tmp[0]->next)
		return ;
	if (tmp[0]->next->var)
		free(tmp[0]->next->var);
	if (tmp[0]->next->content)
		free(tmp[0]->next->content);
	tmp[1] = tmp[0]->next->next;
	free(tmp[0]->next);
	tmp[0]->next = tmp[1];
}

void	envlink_clear(t_env **head)
{
	t_env	*tmp;

	if (!head)
		return ;
	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		if (tmp->var)
			free(tmp->var);
		if (tmp->content)
			free(tmp->content);
		free(tmp);
	}
}

void	envlink_addback(t_env **lst, t_env *new)
{
	t_env	*last;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = envlink_last(*lst);
	last->next = new;
	if (new->next != NULL)
		new->next = NULL;
}
