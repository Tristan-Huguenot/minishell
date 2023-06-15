#include "minishell.h"

void	cd_path_env(t_env *env, char *str, char **str_var)
{
	// char	**names;

	while (env->next)
	{
		if (!ft_strncmp(env->var, str, ft_strlen(str)))
		{
			*str_var = ft_strdup("OLDPWD");
			*str_var = ft_strjoin_free(*str_var, "=");
			*str_var = ft_strjoin_free(*str_var, env->content);
			return ;
		}
		env = env->next;
	}
}

int	cd_path(int argc, char **argv, t_env **env)
{
	char	*str_var[2];

	*str_var = malloc(sizeof(char *) + 1);
	// (void)argc;
	str_var[0] = NULL;
	// str[0] = pwd;
	// str[1] = old_pwd;
	// str[2] = tmp];
	if (opendir(argv[1]))
	{
		str_var[0] =  ft_strjoin_free(str_var[0], "export");
		cd_path_env(*env, "PWD", &str_var[1]);
		// str_var[2] = ft_strdup(str_var[0]);
		// cd_path(*env, "OLDPWD", &str_var[1]);
		printf("str [0] : %s\n str [1] : %s\n  ", str_var[0], str_var[1]);
		ft_export(argc, str_var, env);
	}
	else
	{
		perror(argv[1]);
		return (1);
	}
	return (0);
}

int	cd(int argc, char **argv, t_env **env)
{
	int	ret;

	if (argc == 1)
	{
		ft_fprintf(2, "minishell: %s: need one argument\n", argv[0]);
		return (1);
	}
	else if (argc == 2)
		ret = cd_path(argc, argv, env);
	else
	{
		ft_fprintf(2, "minishell: %s: too many arguments\n", argv[0]);
		return (1);
	}
	return (ret);
}
