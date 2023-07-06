#include "minishell.h"
#include <dirent.h>

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

void	ft_chdir(int argc, char **argv, t_param *param)
{
	char	*str_old_pwd;
	char	*str_pwd;

	str_old_pwd = cd_pwd();
	str_pwd = ft_strdup(argv[1]);
	free(argv[1]);
	argv[1] = ft_strjoin("OLDPWD=", str_old_pwd);
	ft_export(argc, argv, param);
	chdir(str_pwd);
	free(argv[1]);
	free(str_pwd);
	str_pwd = cd_pwd();
	argv[1] = ft_strjoin("PWD=", str_pwd);
	ft_export(argc, argv, param);
	free(str_old_pwd);
	free(str_pwd);
}

void	cd_parsing(int argc, char **argv, t_param *param, char **cd_split)
{
	int		i;
	char	*str_old_pwd;
	char	*str_pwd;

	str_old_pwd = cd_pwd();
	i = 0;
	while (cd_split[i])
	{
		chdir(cd_split[i]);
		i++;
	}
	free(argv[1]);
	argv[1] = ft_strjoin("OLDPWD=", str_old_pwd);
	ft_export(argc, argv, param);
	free(argv[1]);
	str_pwd = cd_pwd();
	argv[1] = ft_strjoin("PWD=", str_pwd);
	ft_export(argc, argv, param);
	free(str_old_pwd);
	free(str_pwd);
}

int	cd_arg(int argc, char **argv, t_param *param, char **cd_split)
{
	DIR	*dir;

	dir = opendir(argv[1]);
	if (argv && argv[1] && dir)
	{
		if (!ft_strncmp(argv[1], "/", 1))
			ft_chdir(argc, argv, param);
		else
		{
			cd_split = ft_split(argv[1], '/');
			cd_parsing(argc, argv, param, cd_split);
			ft_free_strs(cd_split);
		}
		closedir(dir);
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
		ret = cd_arg(argc, argv, param, cd_split);
	else
	{
		error_handler(E_TMARG, param->progname, argv[0]);
		return (1);
	}
	return (ret);
}
