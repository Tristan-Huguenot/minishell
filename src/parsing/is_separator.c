/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_separator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:33:46 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 10:33:47 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_delim_redir(char sep)
{
	if (sep == '<')
		return (1);
	if (sep == '<')
		return (1);
	return (0);
}

int	is_delim_quote(char sep)
{
	if (sep == '\'')
		return (1);
	if (sep == '\"')
		return (1);
	return (0);
}

int	is_delim_var(char sep)
{
	if (sep == '$')
		return (1);
	if (sep == '%')
		return (1);
	return (0);
}

int	is_delim_space(char sep)
{
	if (sep == ' ')
		return (1);
	if (sep == '\t')
		return (1);
	return (0);
}

int	is_delim(char sep)
{
	int	ret;

	ret = 0;
	ret += is_delim_redir(sep);
	ret += is_delim_quote(sep);
	ret += is_delim_var(sep);
	ret += is_delim_space(sep);
	return (ret);
}
