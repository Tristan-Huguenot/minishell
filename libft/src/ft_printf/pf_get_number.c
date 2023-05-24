/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 03:06:27 by thugueno          #+#    #+#             */
/*   Updated: 2022/10/27 14:47:39 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

static char	*create_str_p(char *tmp, char *arg, t_flag *flag)
{
	if ((ft_char_in_set('+', arg) || ft_char_in_set(' ', arg))
		&& !ft_char_in_set('.', arg))
		flag->padding--;
	if (ft_char_in_set('.', arg) && (size_t)flag->dot > ft_strlen(tmp))
		tmp = pf_add_0(tmp, flag->dot, 1, 1);
	else if (pf_is_0_arg(arg) && (size_t)flag->padding - 2 > ft_strlen(tmp))
	{
		tmp = pf_add_0(tmp, flag->padding - 2, 0, 1);
		flag->padding = 0;
	}
	tmp = pf_add_0x(tmp, "#x");
	tmp = pf_add_char_plus_space(arg, tmp);
	return (tmp);
}

void	pf_get_p(char *arg, va_list ap, t_str *str, t_flag *flag)
{
	void	*ptr;
	char	*tmp;

	ptr = va_arg(ap, void *);
	if (!ptr)
	{
		str->s = ft_strdup("(nil)");
		str->len = ft_strlen(str->s);
		return ;
	}
	tmp = ft_ultoa_base((unsigned long long int)ptr, "0123456789abcdef");
	if (tmp)
		str->s = create_str_p(tmp, arg, flag);
	else
		str->s = NULL;
	str->len = ft_strlen(str->s);
}

static void	get_u(char *arg, va_list ap, t_str *str, t_flag *flag)
{
	char			*tmp;
	size_t			len;
	unsigned int	nb;

	nb = va_arg(ap, unsigned int);
	tmp = ft_ultoa_base(nb, "0123456789");
	if (tmp)
	{
		len = ft_strlen(tmp);
		if (ft_char_in_set('.', arg) && nb == 0 && flag->dot == 0)
			tmp[0] = '\0';
		else if (ft_char_in_set('.', arg) && (size_t)flag->dot > len)
			tmp = pf_add_0(tmp, flag->dot, 1, nb);
		else if (pf_is_0_arg(arg) && (size_t)flag->padding > len
			&& !ft_char_in_set('.', arg))
		{
			tmp = pf_add_0(tmp, flag->padding, 1, nb);
			flag->padding = 0;
		}
	}
	str->s = tmp;
	str->len = ft_strlen(tmp);
}

static void	get_di(char *arg, va_list ap, t_str *str, t_flag *flag)
{
	char	*tmp;
	size_t	len;
	int		nb;

	nb = va_arg(ap, int);
	tmp = ft_itoa(nb);
	if (tmp)
	{
		len = ft_strlen(tmp);
		if (ft_char_in_set('.', arg) && nb == 0 && flag->dot == 0)
			tmp[0] = '\0';
		else if (ft_char_in_set('.', arg)
			&& (size_t)flag ->dot > (len - (1 - (nb > 0))))
			tmp = pf_add_0(tmp, flag->dot, 1, nb);
		else if (pf_is_0_arg(arg) && (size_t)flag->padding > len
			&& !ft_char_in_set('.', arg))
		{
			tmp = pf_add_0(tmp, flag->padding, 0, nb);
			flag->padding = 0;
		}
		if (nb >= 0)
			tmp = pf_add_char_plus_space(arg, tmp);
	}
	str->s = tmp;
	str->len = ft_strlen(tmp);
}

void	pf_get_number(char *arg, va_list ap, t_str *str, t_flag *flag)
{
	char	var_type;

	var_type = arg[ft_strlen(arg) - 1];
	if (ft_char_in_set(var_type, "di"))
		get_di(arg, ap, str, flag);
	else if (var_type == 'u')
		get_u(arg, ap, str, flag);
	else if (ft_char_in_set(var_type, "xX"))
		pf_get_xupperx(arg, ap, str, flag);
}
