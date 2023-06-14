#include "minishell.h"

void	export_adding(char *arg, char *name, t_env *env)
{
	t_env	*link;
	char	*new_cont;

	link = envlink_getvar(env, name);
	new_cont = ft_strjoin(link->content, arg);
	if (!new_cont)
		return ;
	free(link->content);
	link->content = new_cont;
	free(name);
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
		if (cont)
			free(cont);
	}
	envlink_addback(env, new);
}
