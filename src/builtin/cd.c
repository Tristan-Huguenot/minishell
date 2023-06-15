#include "minishell.h"

void	cd_path_env(t_env *env, char *str, char *str_replace, char **str_var)
{
	while (env->next)
	{
		if (!ft_strncmp(env->var, str, ft_strlen(str)))
		{
			*str_var = ft_strdup(str_replace);
			*str_var = ft_strjoin_free(*str_var, "=");
			*str_var = ft_strjoin_free(*str_var, env->content);
			return ;
		}
		env = env->next;
	}
}

char	*there_is_slash(char *argv)
{
	int		i;
	char	*str_tmp;

	i = 0;
	if (argv[i] != '/')
	{
		argv = ft_strjoin("/", argv);
	}
	while (argv[i])
		i++;
	i--;
	if (argv[i] == '/')
	{
		str_tmp = ft_substr(argv, 0, i);
		free(argv);
		argv = str_tmp;
		free(str_tmp);
	}
	return (argv);
}

int	cd_path(int argc, char **argv, t_param *param)
{
	char	**str_var_pwd;
	char	**str_var_old;
	char	**str_var_tmp;

	if (opendir(argv[1]))
	{
		if (ft_strncmp(argv[i], "..", 2))
			return_back(argv[i], param->env);
		there_is_slash(argv[1]);
	str_var_tmp = malloc(sizeof(char *) * 2);
	str_var_pwd = malloc(sizeof(char *) * 3);
	str_var_old = malloc(sizeof(char *) * 3);
	str_var_tmp[0] = NULL;
	cd_path_env(param->env, "PWD", "PWD", &str_var_tmp[0]);
	str_var_pwd[0] = ft_strdup("export");
	str_var_old[0] = ft_strdup("export");
	cd_path_env(param->env, "PWD", "OLDPWD", &str_var_pwd[1]);
	printf("str pwd [0] : %s\n str pwd[1] : %s\n  ", str_var_pwd[0], str_var_pwd[1]);
	ft_export(argc, str_var_pwd, &param->env);
	
		chdir(argv[1]);
		str_var_old[1] = ft_strdup(str_var_tmp[0]);

		str_var_old[1] = ft_strjoin_free(str_var_old[1], argv[1]);
		printf("str old pwd [0] : %s\n str old pwd [1] : %s\n  ", str_var_old[0], str_var_old[1]);
		ft_export(argc, str_var_old, &param->env);
	}
	else
	{
		ft_fprintf(2, "%s: %s: %s\n", param->progname, argv[1], strerror(errno));
		return (1);
	}
	return (0);
}



int	cd(int argc, char **argv, t_param *param)
{
	int	ret;

	if (argc == 1)
	{
		ft_fprintf(2, "%s: %s: need one argument\n", param->progname, argv[0]);
		return (1);
	}
	else if (argc == 2)
	{
		ret = cd_path(argc, argv, param);
	}
	else
	{
		ft_fprintf(2, "%s: %s: too many arguments\n", param->progname, argv[0]);
		return (1);
	}
	return (ret);
}
