#include "minishell.h"

static void	print_env(t_env *env)
{
	char	**names;
	char	*tmp_content;
	int		i;

	names = convert_env_names_strs(env);
	if (!names)
		return ;
	sort_strs(names);
	i = 0;
	while (names[i])
	{
		if (ft_strncmp(names[i], "_", 2) != 0)
		{
			tmp_content = NULL;
			if (envlink_getvar(env, names[i]) != NULL)
				tmp_content = envlink_getvar(env, names[i])->content;
			if (tmp_content)
				printf("declare -x %s=\"%s\"\n", names[i], tmp_content);
			else
				printf("declare -x %s\n", names[i]);
		}
		i++;
	}
	ft_free_strs(names);
}

static int	check_identifier(char *arg, int end)
{
	int	i;

	if (!arg[0])
		return (0);
	i = 0;
	if (ft_isdigit(arg[i]))
		return (1);
	while (i < end)
	{
		if (arg[i] != '_' && !ft_isalnum(arg[i]))
			return (1);
		i++;
	}
	if (arg[end] && arg[end] == '+' && arg[end + 1] != '=')
		return (1);
	return (0);
}

static void	export_nonull(int middle, char *arg, t_param *param)
{
	char	*var;

	var = ft_substr(arg, 0, middle);
	if (!var)
		return ;
	if (!ft_strncmp(var, "_", 2))
	{
		free(var);
		return ;
	}
	if (arg[middle] != '=' && envlink_getvar(param->env, var))
		export_adding(arg + middle + 2, var, param->env);
	else
		export_create(arg + middle, var, &param->env);
	if (!ft_strncmp(var, "PATH", ft_strlen("PATH") + 1))
	{
		if (param->paths)
			ft_free_strs(param->paths);
		init_paths(param);
	}
}

static int	handle_arg(char *arg, t_param *param)
{
	t_env	*new;
	char	*tmp;
	int		i;

	i = 0;
	while (arg[i] && arg[i] != '+' && arg[i] != '=')
		i++;
	if (i == 0 || check_identifier(arg, i))
		error_handler(E_IDENTIFIER, "export", arg);
	if (i == 0 || check_identifier(arg, i))
		return (1);
	if (!arg[i] && !envlink_getvar(param->env, arg))
	{
		new = NULL;
		tmp = ft_strdup(arg);
		if (tmp)
			new = envlink_new(tmp, NULL);
		if (new)
			envlink_addback(&param->env, new);
		else
			free(tmp);
	}
	else if (arg[i])
		export_nonull(i, arg, param);
	return (0);
}

int	ft_export(int argc, char **argv, t_param *param)
{
	int	i;
	int	ret;

	if (argc == 1)
	{
		print_env(param->env);
		return (0);
	}
	ret = 0;
	i = 1;
	while (i < argc)
	{
		if (handle_arg(argv[i], param))
			ret = 1;
		i++;
	}
	return (ret);
}
