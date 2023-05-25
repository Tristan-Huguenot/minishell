/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:48:37 by thugueno          #+#    #+#             */
/*   Updated: 2023/05/09 21:53:52 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FILE_H
# define LIBFT_FILE_H

# include "libft_write.h"
# include "libft_string.h"
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define GNL_EOF 0
# define GNL_EOL 1
# define GNL_NNL 2

char	*get_next_line(int fd);
void	gnl_free_buff(char **buff);
char	**get_all_line(int fd);

#endif
