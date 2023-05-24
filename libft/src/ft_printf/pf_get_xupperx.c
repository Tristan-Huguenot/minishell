/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xupperx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:22:01 by thugueno          #+#    #+#             */
/*   Updated: 2022/10/27 02:40:41 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

static char	*get_number_xupperx(char *arg, int nb)
{
	char	*tmp;

	if (ft_char_in_set('x', arg))
		tmp = ft_ultoa_base((unsigned int)nb, "0123456789abcdef");
	else
		tmp = ft_ultoa_base((unsigned int)nb, "0123456789ABCDEF");
	return (tmp);
}

void	pf_get_xupperx(char *arg, va_list ap, t_str *str, t_flag *flag)
{
	size_t	len;
	int		nb;

	nb = va_arg(ap, int);
	str->s = get_number_xupperx(arg, nb);
	len = ft_strlen(str->s);
	if (ft_char_in_set('.', arg) && nb == 0 && flag->dot == 0)
		str->s[0] = '\0';
	else if (ft_char_in_set('.', arg) && (size_t)flag->dot > len)
		str->s = pf_add_0(str->s, flag->dot, 1, 1);
	else if (pf_is_0_arg(arg) && ft_char_in_set('#', arg)
		&& (size_t)flag->padding - 2 > len && !ft_char_in_set('.', arg))
	{
		str->s = pf_add_0(str->s, flag->padding - 2, 0, 1);
		flag->padding = 0;
	}
	else if (pf_is_0_arg(arg) && !ft_char_in_set('#', arg)
		&& (size_t)flag->padding > len && !ft_char_in_set('.', arg))
	{
		str->s = pf_add_0(str->s, flag->padding, 0, 1);
		flag->padding = 0;
	}
	if (nb != 0)
		str->s = pf_add_0x(str->s, arg);
	str->len = ft_strlen(str->s);
}
