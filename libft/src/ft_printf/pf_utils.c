/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      + +  +:+       + +        */
/*                                                + + + + + +   + +           */
/*   Created: 2023/03/23 00:12:00 by thugueno           +      +              */
/*   Updated: 2023/03/23 00:12:00 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

int	print_to_next_arg(char **s, int fd)
{
	int	printed;

	printed = 0;
	while (**s && **s != '%')
	{
		ft_putchar_fd(**s, fd);
		*s += 1;
		printed++;
	}
	return (printed);
}

void	pass_arg(char **sptr)
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

void	ft_put_str(t_str *str, int fd)
{
	size_t	i;

	i = 0;
	while (i < str->len)
	{
		ft_putchar_fd(str->s[i], fd);
		i++;
	}
}
