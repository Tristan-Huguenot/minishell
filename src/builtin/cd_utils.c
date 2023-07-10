/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:30:17 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 10:30:18 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
