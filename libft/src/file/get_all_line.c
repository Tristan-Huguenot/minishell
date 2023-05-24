/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:46:14 by thugueno          #+#    #+#             */
/*   Updated: 2023/02/09 00:06:11 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_file.h"

char	**get_all_line(int fd)
{
	char	**file;
	char	*join;
	char	*join_tmp;
	char	*gnl_tmp;

	join = NULL;
	gnl_tmp = get_next_line(fd);
	while (gnl_tmp)
	{
		join_tmp = ft_strjoin(join, gnl_tmp);
		free(join);
		join = join_tmp;
		free(gnl_tmp);
		gnl_tmp = get_next_line(fd);
	}
	file = ft_split(join, '\n');
	free(join);
	return (file);
}
