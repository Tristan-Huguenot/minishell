#include "minishell.h"

int	envlink_size(t_env *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

char **convert_env_strs(t_env *head)
{
	char	**strs;
	char	*tmp;
	int		size;
	int		i;

	size = envlink_size(head);
	strs = ft_calloc(size + 1, sizeof(*strs));
	i = 0;
	while (head)
	{
		tmp = ft_strjoin(head->var, "=");
		strs[i] = ft_strjoin_free(tmp, head->content);
		head = head->next;
		i++;
	}
	return (strs);
}

t_env	*envlink_getvar(t_env *head, char *var)
{
	while (head && ft_strncmp(head->var, var, ft_strlen(var)))
		head = head->next;
	return (head);
}
