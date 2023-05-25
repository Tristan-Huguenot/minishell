/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_ft_printf.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:56:27 by thugueno          #+#    #+#             */
/*   Updated: 2023/03/10 20:05:16 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FT_PRINTF_H
# define LIBFT_FT_PRINTF_H

# include "libft_write.h"
# include "libft_num_string.h"
# include <stdarg.h>

typedef struct s_str
{
	char	*s;
	size_t	len;
}	t_str;

typedef struct s_flag
{
	int	dot;
	int	padding;
}	t_flag;

int		ft_printf(const char *s, ...);
int		ft_fprintf(int fd, const char *s, ...);
int		print_to_next_arg(char **s, int fd);
void	pass_arg(char **sptr);
void	ft_put_str(t_str *str, int fd);
int		pf_parsing_arg(char *s);
int		pf_get_dot(char *arg);
int		pf_get_padding(char *arg);
int		pf_is_0_arg(char *arg);
char	*pf_add_0(char *str, int n, int is_dot, long int nb);
char	*pf_add_char(char *str, size_t len, char c);
char	*pf_add_char_plus_space(char *arg, char *str);
char	*pf_add_0x(char *str, char *arg);
t_str	*pf_create_str(char *s, va_list ap);
void	pf_get_percent(t_str *str);
void	pf_get_p(char *arg, va_list ap, t_str *str, t_flag *flag);
void	pf_get_s(char *arg, va_list ap, t_str *str, int dot);
void	pf_get_c(va_list ap, t_str *str);
void	pf_get_number(char *arg, va_list ap, t_str *str, t_flag *flag);
void	pf_get_xupperx(char *arg, va_list ap, t_str *str, t_flag *flag);
void	pf_add_padding(char var, char *arg, t_str *str, int padding);

#endif
