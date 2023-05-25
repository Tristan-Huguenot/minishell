/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      + +  +:+       + +        */
/*                                                + + + + + +   + +           */
/*   Created: 2022/10/18 15:57:44 by thugueno           +      +              */
/*   Updated: 2023/01/12 23:09:00 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

int	ft_fprintf(int fd, const char *s, ...)
{
	va_list	ap;
	int		printed;
	t_str	*tmp;

	if (!s)
		return (-1);
	va_start(ap, s);
	printed = 0;
	while (*s)
	{
		printed += print_to_next_arg((char **)&s, fd);
		if (*s == '%')
		{
			tmp = pf_create_str((char *)s, ap);
			if (!tmp)
				return (-1);
			printed += tmp->len;
			ft_put_str(tmp, fd);
			pass_arg((char **)&s);
			free(tmp->s);
			free(tmp);
		}
	}
	va_end(ap);
	return (printed);
}
