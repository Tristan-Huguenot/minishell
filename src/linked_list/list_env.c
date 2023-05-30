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

void	envlink_delvar(t_env *head, char *var)
{
	t_env	*tmp;

	if (!head)
		return ;
	while (head->next && ft_strncmp(var, head->next->var, ft_strlen(var)))
		head = head->next;
	if (head->next->var)
		free(head->next->var);
	if (head->next->content)
		free(head->next->content);
	tmp = head->next->next;
	if (head->next)
		free(head->next);
	head->next = tmp;
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

	if (!new)
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
