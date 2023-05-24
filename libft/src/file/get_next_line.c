/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:54:02 by thugueno          #+#    #+#             */
/*   Updated: 2023/02/04 19:02:53 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_file.h"

static int	gnl_read_line(char *li, int fd)
{
	int	ret;

	if (!li)
		ret = 0;
	else
		ret = read(fd, li, BUFFER_SIZE);
	return (ret);
}

static char	*gnl_end_of_file(char **buff, char *li)
{
	free(li);
	free(*buff);
	*buff = NULL;
	return (*buff);
}

static char	*gnl_buff_new_line(char **buff)
{
	char	*tmp;
	char	*li;
	size_t	pos_eol;

	pos_eol = 0;
	while ((*buff)[pos_eol] != '\n')
		pos_eol++;
	pos_eol++;
	tmp = ft_calloc(pos_eol + 1, sizeof(*tmp));
	if (!tmp)
		return (gnl_end_of_file(buff, tmp));
	ft_strlcat(tmp, *buff, pos_eol + 1);
	li = ft_strdup(*buff + pos_eol);
	free(*buff);
	*buff = li;
	return (tmp);
}

static char	*gnl_add_line(char **buff, char *li, int type)
{
	char	*tmp;
	size_t	len;

	len = 1;
	if (type == GNL_EOL)
		while (li[len - 1] != '\n')
			len++;
	else
		len = ft_strlen(li);
	tmp = ft_calloc(ft_strlen(*buff) + len + 1, sizeof(*tmp));
	if (!tmp)
		return (gnl_end_of_file(buff, li));
	ft_strlcat(tmp, *buff, ft_strlen(*buff) + 1);
	if (type == GNL_EOF)
		ft_strlcat(tmp, li, ft_strlen(*buff) + len + 1);
	else
		ft_strlcat(tmp, li, ft_strlen(tmp) + len + 1);
	free(*buff);
	if (type == GNL_EOL)
		*buff = ft_strdup(li + len);
	else
		*buff = NULL;
	free(li);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*li;
	int			ret;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!buff)
		buff = ft_strdup("");
	if (ft_char_in_set('\n', buff))
		return (gnl_buff_new_line(&buff));
	li = ft_calloc(BUFFER_SIZE + 1, sizeof(*li));
	ret = gnl_read_line(li, fd);
	while (ret > 0 && !ft_char_in_set('\n', li))
	{
		buff = gnl_add_line(&buff, li, GNL_NNL);
		li = ft_calloc(BUFFER_SIZE + 1, sizeof(*li));
		ret = gnl_read_line(li, fd);
	}
	if (ret == -1 || (ret == 0 && ft_strlen(buff) == 0) || !li)
		return (gnl_end_of_file(&buff, li));
	if (ft_char_in_set('\n', li))
		return (gnl_add_line(&buff, li, GNL_EOL));
	return (gnl_add_line(&buff, li, GNL_EOF));
}
