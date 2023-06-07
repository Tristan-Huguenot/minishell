#include "minishell.h" 

static int	echo_flag(char *cmd)
{
	int	i;

	if (cmd[0] == '-')
	{
		i = 1;
		while (cmd[i] && cmd[i] == 'n')
			i++;
		if (cmd[i] == '\0' && cmd[i - 1] == 'n')
			return (1);
	}
	return (0);
}

static int	echo_more_flag(char **cmd, int i, int flag)
{
	int	tmp;

	tmp = i;
	i++;
	while (cmd[i])
	{
		if (flag)
			flag = echo_flag(cmd[i]);
		if (flag)
			tmp = i;
		i++;
	}
	return (tmp);
}

static void	print_with_flag(char **cmd_arg, int flag)
{
	char	*str;

	str = NULL;
	flag++;
	while (cmd_arg[flag])
	{
		str = ft_strjoin_free(str, cmd_arg[flag]);
		if (cmd_arg[flag + 1])
			str = ft_strjoin_free(str, " ");
		flag++;
	}
	ft_putstr_fd(str, 1);
	free(str);
}

static void	print_without_flag(char **cmd_arg, int i)
{
	char	*str;

	str = NULL;
	while (cmd_arg[i])
	{
		str = ft_strjoin_free(str, cmd_arg[i]);
		if (cmd_arg[i + 1])
			str = ft_strjoin_free(str, " ");
		i++;
	}
	ft_putendl_fd(str, 1);
	free(str);
}

int	echo(int argc, char **cmd_arg)
{
	int		i;
	int		flag;

	if (argc == 1)
		return (0);
	i = 1;
	flag = 0;
	flag = echo_flag(cmd_arg[i]);
	if (flag)
		flag = echo_more_flag(cmd_arg, i, flag);
	if (flag)
		print_with_flag(cmd_arg, flag);
	else
		print_without_flag(cmd_arg, i);
	return (0);
}
