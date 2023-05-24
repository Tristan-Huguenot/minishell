/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_percentsc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:59:15 by thugueno          #+#    #+#             */
/*   Updated: 2022/10/27 14:32:48 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

void	pf_get_percent(t_str *str)
{
	str->s = ft_calloc(2, sizeof(char));
	if (!str->s)
	{
		str->len = 0;
		return ;
	}
	str->s[0] = '%';
	str->len = 1;
}

void	pf_get_s(char *arg, va_list ap, t_str *str, int dot)
{
	char	*tmp;
	char	*var;
	size_t	len;

	var = va_arg(ap, char *);
	len = ft_strlen(var);
	if (!var && ft_char_in_set('.', arg) && dot < 6)
		tmp = ft_strdup("");
	else if (!var)
		tmp = ft_strdup("(null)");
	else if (ft_char_in_set('.', arg))
	{
		tmp = ft_calloc(dot + 1, sizeof(*tmp));
		ft_strlcpy(tmp, var, dot + 1);
	}
	else
	{
		tmp = ft_calloc(len + 1, sizeof(*tmp));
		ft_strlcpy(tmp, var, len + 1);
	}
	str->s = tmp;
	str->len = ft_strlen(tmp);
}

void	pf_get_c(va_list ap, t_str *str)
{
	str->s = ft_calloc(2, sizeof(char));
	if (!str->s)
	{
		str->len = 0;
		return ;
	}
	str->s[0] = va_arg(ap, int);
	str->len = 1;
}
