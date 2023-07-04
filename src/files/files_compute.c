#include "minishell.h"

int	file_is_dir(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (1);
	}
	return (0);
}

char	*file_is_exe(char *file, char **paths)
{
	char	*tmp;
	int		i;

	if (!file || ft_strlen(file) == 0 || file_is_dir(file))
		return (NULL);
	if (file && !access(file, F_OK | X_OK))
		return (ft_strdup(file));
	if (file[0] == '/')
		return (NULL);
	i = 0;
	while (file && paths && paths[i])
	{
		tmp = ft_strjoin(paths[i], file);
		if (!tmp)
			return (tmp);
		if (!access(tmp, F_OK | X_OK))
			return (tmp);
		free(tmp);
		i++;
	}
	return (NULL);
}
