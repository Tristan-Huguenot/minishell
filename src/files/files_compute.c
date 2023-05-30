/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_compute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:58:27 by thugueno          #+#    #+#             */
/*   Updated: 2023/05/26 17:05:09 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
