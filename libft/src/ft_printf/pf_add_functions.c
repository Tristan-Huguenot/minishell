/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_add_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:20:03 by thugueno          #+#    #+#             */
/*   Updated: 2023/02/04 20:07:45 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

char	*pf_add_char(char *str, size_t len, char c)
{
	char	*new;

	new = ft_calloc(len + 2, sizeof(*new));
	if (!new)
		return (str);
	new[0] = c;
	ft_strlcpy(new + 1, str, len + 1);
	free(str);
	return (new);
}

char	*pf_add_char_plus_space(char *arg, char *str)
{
	if (!arg || !str)
		return (str);
	if (ft_char_in_set('+', arg))
			str = pf_add_char(str, ft_strlen(str), '+');
	else if (ft_char_in_set(' ', arg))
			str = pf_add_char(str, ft_strlen(str), ' ');
	return (str);
}

char	*pf_add_0(char *str, int n, int is_dot, long int nb)
{
	char	*new;
	size_t	len;

	len = ft_strlen(str);
	if (str && nb < 0 && is_dot)
		new = ft_calloc(len + (n - (len - 1)) + 1, sizeof(*new));
	else if (str)
		new = ft_calloc(len + (n - len) + 1, sizeof(*new));
	if (!str || !new)
		return (str);
	if (nb < 0)
	{
		if (is_dot)
			len -= 1;
		ft_memset(new, '-', 1);
		ft_memset(new + 1, '0', n - len);
		ft_strlcpy(new + 1 + (n - len), str + 1, len + 1);
	}
	else
	{
		ft_memset(new, '0', n - len);
		ft_strlcpy(new + (n - len), str, len + 1);
	}
	free(str);
	return (new);
}

char	*pf_add_0x(char *str, char *arg)
{
	char	*tmp;

	if (!str || !ft_char_in_set('#', arg))
		return (str);
	tmp = ft_calloc(ft_strlen(str) + 3, sizeof(*tmp));
	if (ft_char_in_set('x', arg) && tmp)
		ft_memmove(tmp, "0x", 2);
	else if (ft_char_in_set('X', arg) && tmp)
		ft_memmove(tmp, "0X", 2);
	if (!tmp)
		return (tmp);
	ft_strlcpy(tmp + 2, str, ft_strlen(str) + 1);
	free(str);
	return (tmp);
}

void	pf_add_padding(char var, char *arg, t_str *str, int padding)
{
	char	*tmp;

	if (padding <= 0 || var == '%')
		return ;
	if (!str->s || (int)str->len >= padding)
		return ;
	tmp = ft_calloc(padding + 1, sizeof(*tmp));
	if (!tmp)
		return ;
	if (ft_char_in_set('-', arg))
		ft_memset(tmp + str->len, ' ', padding - str->len);
	else
		ft_memset(tmp, ' ', padding - str->len);
	if (ft_char_in_set('-', arg))
		ft_memmove(tmp, str->s, str->len);
	else
		ft_memmove(tmp + (padding - str->len), str->s, str->len);
	str->len = padding;
	free(str->s);
	str->s = tmp;
}
