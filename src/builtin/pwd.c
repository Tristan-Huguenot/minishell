/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:31:15 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 10:31:15 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(void)
{
	char	*buf;

	buf = malloc(sizeof(char) * PATH_MAX);
	if (!buf)
		return (12);
	if (!getcwd(buf, PATH_MAX))
		perror("pwd error:");
	else
		printf("%s\n", buf);
	free(buf);
	return (0);
}
