#include "minishell.h"

char	*file_is_exe(char *file, char **paths)
{
	char	*tmp;
	int		i;

	if (!file)
		return (NULL);
	if (file && !access(file, F_OK | X_OK))
		return (ft_strdup(file));
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
