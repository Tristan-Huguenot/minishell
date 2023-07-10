/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_compute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:33:01 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 10:33:01 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (file && ft_strchr(file, '/') && !access(file, F_OK | X_OK))
		return (ft_strdup(file));
	if (file[0] == '/')
		return (NULL);
	i = 0;
	while (file && !ft_strchr(file, '/') && paths && paths[i])
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
