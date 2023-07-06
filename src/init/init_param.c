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

void	init_paths(t_param *param)
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
	t_env	*new;
	char	*tmp[2];
	int		i[2];

	if (!envp)
		return ;
	i[0] = 0;
	while (envp[i[0]])
	{
		new = NULL;
		i[1] = 0;
		while (envp[i[0]][i[1]] != '=')
			i[1]++;
		tmp[0] = ft_substr(envp[i[0]], 0, i[1]);
		tmp[1] = ft_strdup(envp[i[0]] + i[1] + 1);
		if (tmp[0] && tmp[1])
			new = envlink_new(tmp[0], tmp[1]);
		if (new)
			envlink_addback(&param->env, new);
		if (!new && tmp[0])
			free(tmp[0]);
		if (!new && tmp[1])
			free(tmp[1]);
		i[0]++;
	}
}

char	*init_prompt(char *name, t_env *env)
{
	char	*tmp;
	char	*prompt;

	prompt = ft_strjoin(PROMPTC, " $? ");
	prompt = ft_strjoin_free(prompt, name);
	tmp = ft_strjoin_free(prompt, " $> ");
	prompt = ft_strjoin_free(tmp, NOC);
	prompt = parsing_variable(prompt, env);
	return (prompt);
}

t_param	*init_param(char *name, char **envp)
{
	t_param	*param;
	t_child	*child;

	param = ft_calloc(1, sizeof(*param));
	if (!param)
		return (param);
	param->progname = name;
	init_env(param, envp);
	param->prompt = init_prompt(name, param->env);
	init_paths(param);
	child = ft_calloc(1, sizeof(*child));
	param->child = child;
	return (param);
}
