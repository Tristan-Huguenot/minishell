#include "minishell.h"

static char	*cd_pwd(void)
{
	char	*buf;

	buf = malloc(sizeof(char) * PATH_MAX);
	if (!buf)
		g_return = 12;
	else if (!getcwd(buf, PATH_MAX))
	{
		perror("pwd error:");
		g_return = errno;
	}
	return (buf);
}

void	ft_chdir(int argc, char **argv, t_env **env)
{
	char	*str_old_pwd;
	char	*str_pwd;

	str_old_pwd = cd_pwd();
	str_pwd = ft_strdup(argv[1]);
	free(argv[1]);
	argv[1] = ft_strjoin("OLDPWD=", str_old_pwd);
	ft_export(argc, argv, env);
	chdir(str_pwd);
	free(argv[1]);
	argv[1] = ft_strjoin("PWD=", str_pwd);
	ft_export(argc, argv, env);
	free(str_old_pwd);
	free(str_pwd);
}

char	*return_back(char *buf)
{
	char	*str_end;
	int		size;
	char	*str_tmp;

	str_end = ft_strdup(ft_strrchr(buf, '/'));
	size = ft_strlen(buf) - ft_strlen(str_end);
	free(str_end);
	str_tmp = ft_substr(buf, 0, size);
	free(buf);
	return (str_tmp);
}

void	cd_parsing(int argc, char **argv, t_env **env, char **cd_split)
{
	int		i;
	char	*buf;

	(void)argc;
	(void)env;
	buf = cd_pwd();
	i = 0;
	while (cd_split[i] && buf)
	{
		if (!ft_strncmp(cd_split[i], "..", 2))
		{
			buf = return_back(buf);
		}
		else if (ft_strncmp(cd_split[i], ".", 1))
		{
			buf = ft_strjoin_free(buf, "/");
			buf = ft_strjoin_free(buf, cd_split[i]);
		}
		i++;
	}
	free(argv[1]);
	argv[1] = ft_strdup(buf);
	free(buf);
	ft_chdir(argc, argv, env);
}

int	cd(int argc, char **argv, t_param *param)
{
	int		ret;
	char	**cd_split;

	ret = 0;
	cd_split = NULL;
	if (argc == 1)
	{
		error_handler(E_OARG, param->progname, argv[0]);
		return (1);
	}
	else if (argc == 2)
	{
		if (opendir(argv[1]))
		{
			if (!ft_strncmp(argv[1], "/nfs", 4))
				ft_chdir(argc, argv, &param->env);
			else
			{
				cd_split = ft_split(argv[1], '/');
				cd_parsing(argc, argv, &param->env, cd_split);
				ft_free_strs(cd_split);
			}
		}
		else
		{
			ft_fprintf(2, "%s: %s: %s\n", param->progname, argv[1], strerror(errno));
			return (1);
		}
	}
	else
	{
		error_handler(E_TMARG, param->progname, argv[0]);
		return (1);
	}
	return (ret);
}
