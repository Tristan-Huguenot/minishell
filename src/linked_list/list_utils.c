#include "minishell.h"

t_env	*envlink_getvar(t_env *head, char *var)
{
	while (ft_strncmp(head->var, var, ft_strlen(var)))
	{
		if (!head->next)
			return (NULL);
		head = head->next;
	}
	return (head);
}
