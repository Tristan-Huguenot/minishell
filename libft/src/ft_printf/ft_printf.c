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

static int	print_to_next_arg(char **s)
{
	int	printed;

	printed = 0;
	while (**s && **s != '%')
	{
		ft_putchar_fd(**s, 1);
		*s += 1;
		printed++;
	}
	return (printed);
}

static void	pass_arg(char **sptr)
{
	*sptr += 1;
	if (pf_parsing_arg(*sptr))
	{
		while (!ft_char_in_set(**sptr, "cspdiuxX%") && **sptr)
			*sptr += 1;
		if (**sptr)
			*sptr += 1;
	}
}

static void	ft_putt_str(t_str *str)
{
	size_t	i;

	i = 0;
	while (i < str->len)
	{
		ft_putchar_fd(str->s[i], 1);
		i++;
	}
}

int	ft_printf(const char *s, ...)
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
		printed += print_to_next_arg((char **)&s);
		if (*s == '%')
		{
			tmp = pf_create_str((char *)s, ap);
			if (!tmp)
				return (-1);
			printed += tmp->len;
			ft_putt_str(tmp);
			pass_arg((char **)&s);
			free(tmp->s);
			free(tmp);
		}
	}
	va_end(ap);
	return (printed);
}
