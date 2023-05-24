/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:35:28 by thugueno          #+#    #+#             */
/*   Updated: 2022/10/27 14:18:42 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

static char	*get_arg(char *s)
{
	size_t	i;
	char	*arg;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && !ft_char_in_set(s[i], "cspdiuxX%"))
		i++;
	arg = ft_substr(s, 0, i + 1);
	return (arg);
}

static void	set_flag_type(t_flag *flag, char *arg, char *var_type)
{
	flag->padding = pf_get_padding(arg);
	flag->dot = pf_get_dot(arg);
	*var_type = arg[ft_strlen(arg) - 1];
}

static t_str	*get_var(char *arg, va_list ap, t_str *str)
{
	char	var_type;
	t_flag	*flag;

	flag = ft_calloc(1, sizeof(*flag));
	if (!flag || !arg)
	{
		free(flag);
		str->s = NULL;
		str->len = 0;
		return (NULL);
	}
	set_flag_type(flag, arg, &var_type);
	if (var_type == '%')
		pf_get_percent(str);
	else if (var_type == 'c')
		pf_get_c(ap, str);
	else if (var_type == 's')
		pf_get_s(arg, ap, str, flag->dot);
	else if (var_type == 'p')
		pf_get_p(arg, ap, str, flag);
	else if (ft_char_in_set(var_type, "diuxX"))
		pf_get_number(arg, ap, str, flag);
	pf_add_padding(var_type, arg, str, flag->padding);
	free(flag);
	return (str);
}

t_str	*pf_create_str(char *s, va_list ap)
{
	t_str	*str;
	char	*arg;

	str = ft_calloc(1, sizeof(*str));
	if (str == NULL || pf_parsing_arg(s + 1) == -1)
	{
		free(str);
		return (NULL);
	}
	else if (!pf_parsing_arg(s + 1))
	{
		str->s = ft_substr(s, 0, 1);
		if (!str->s)
			str->len = 0;
		else
			str->len = 1;
		return (str);
	}
	arg = get_arg(s + 1);
	str = get_var(arg, ap, str);
	free(arg);
	return (str);
}
