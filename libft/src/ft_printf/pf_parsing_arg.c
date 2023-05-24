/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 22:13:26 by thugueno          #+#    #+#             */
/*   Updated: 2022/10/27 14:17:09 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

int	pf_get_dot(char *arg)
{
	int	ret;

	ret = 0;
	if (!arg)
		return (0);
	while (*arg && *arg != '.')
		arg++;
	if (!*arg)
		return (ret);
	ret += ft_atoi(arg + 1);
	if (ret < 0)
		return (0);
	return (ret);
}

int	pf_get_padding(char *arg)
{
	int		ret;
	char	*set;

	ret = 0;
	set = ft_strdup("-0# +");
	if (!set || !arg)
		return (0);
	while (ft_char_in_set(*arg, set) && *arg)
		arg++;
	if (*arg)
		ret += ft_atoi(arg);
	free(set);
	if (ret < 0)
		return (0);
	return (ret);
}

int	pf_is_0_arg(char *arg)
{
	int	i;

	if (!arg)
		return (0);
	i = 0;
	while (arg[i] && ft_char_in_set(arg[i], "#- +"))
		i++;
	if (!arg[i] || arg[i] != '0')
		return (0);
	return (1);
}

static void	initiate_var(int *i, char **set)
{
	*set = ft_strdup("-0# +");
	*i = 0;
}

int	pf_parsing_arg(char *s)
{
	char	*set;
	int		i;

	initiate_var(&i, &set);
	if (!set)
		return (0);
	while (ft_char_in_set(s[i], set))
		i++;
	while (ft_isdigit(s[i]))
		i++;
	if (s[i] == '.')
	{
		i++;
		while (ft_isdigit(s[i]))
			i++;
	}
	free(set);
	if (ft_char_in_set(s[i], "cspdiuxX%"))
		return (1);
	if (!s[i])
		return (-1);
	return (0);
}
