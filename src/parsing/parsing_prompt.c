/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:07:05 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/24 14:42:30 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_redirection_in(char *input)
{
	int	i;
	int	rtrn;

	i = 1;
	if (!(input[i] == '<'))
	{
		while (input[i] && input[i] == ' ')
			i++;
		if (input[i] == '\0')
		{
			if (/*structure_next*/ 0 == 1)
				printf("bash: syntax error near unexpected token `|''");
			else
				printf("bash: syntax error near unexpected token `newline'");
			return (2);
		}
		if (input[i] == '>')
		{
			i++;
			if (input[i] == '>')
				printf("bash: syntax error near unexpected token `>>'");
			else if (input[i] == '<')
				printf("bash: syntax error near unexpected token `><'");
			else
				printf("bash: syntax error near unexpected token `>'");
			return (2);
		}
		else if (input[i] == '<')
		{
			i++;
			if (input[i] == '<')
				printf("bash: syntax error near unexpected token `<<'");
			else if (input[i] == '<')
				printf("bash: syntax error near unexpected token `<>'");
			else
				printf("bash: syntax error near unexpected token `<'");
			return (2);
		}
		return (0);
	}
	else
	{
		input = ft_substr(input, 1, (ft_strlen(input) - 1));
		parse_redirection_in(input);
	}
/*	else
	{
		while (input[i])
		{
			if (input[i] == '>')
			{
				input = ft_substr(input, 2, (ft_strlen(input) - 1));
				parse_redirection_out(input);
			}
			else if (input[i] == '>'))
			{
				input = ft_substr(input, 2, (ft_strlen(input) - 1));
				parse_redirection_out(input);
			}
			i++;
		}
	}*/
	(void)rtrn;
	return (0);
}

int	parse_redirection_out(char *input)
{
	int	i;

	i = 1;
	if (!(input[i] == '>'))
	{
		while (input[i] && input[i] == ' ')
			i++;
		if (input[i] == '\0')
		{
			if (/*structure_next*/ 0 == 1)
				printf("bash: syntax error near unexpected token `|''");
			else
				printf("bash: syntax error near unexpected token `newline'");
			return (2);
		}
		if (input[i] == '<')
		{
			i++;
			if (input[i] == '<')
				printf("bash: syntax error near unexpected token `<<'");
			else if (input[i] == '>')
				printf("bash: syntax error near unexpected token `<>'");
			else
				printf("bash: syntax error near unexpected token `<'");
			return (2);
		}
		else if (input[i] == '>')
		{
			i++;
			if (input[i] == '>')
				printf("bash: syntax error near unexpected token `>>'");
			else if (input[i] == '<')
				printf("bash: syntax error near unexpected token `><'");
			else
				printf("bash: syntax error near unexpected token `>'");
			return (2);
		}
		return (0);
	}
	else if (input[1] == '>')
	{
		input = ft_substr(input, 2, (ft_strlen(input) - 1));
		parse_redirection_out(input);
	}
	else
	{
		while (input[i])
		{
			if (input[i] == '>')
			{
				input = ft_substr(input, 2, (ft_strlen(input) - 1));
				parse_redirection_out(input);
			}
			else if (input[i] == '>')
			{
				input = ft_substr(input, 2, (ft_strlen(input) - 1));
				parse_redirection_out(input);
			}
			i++;
		}
	}
	return (0);
}

/*void	syntax_error_pipe(char *input)
{
	if (!variable)
	{
		printf("bash: syntax error near unexpected token '|'");
		return (2);
	}
}*/

void	parsing_redirection(char **input, int st)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;
	int		vreturn;

	i = 0;
	j = 0;
	vreturn = 0;
	while (input[i])
	{
		tmp = ft_strjoin_free(tmp, input[i]);
		i++;
	}
	while (tmp[j])
	{
		if (tmp[j] == '<' && st == 0)
		{
			k = j;
			j = ft_strlen(tmp) - k;
			tmp = ft_substr(tmp, k, j);
			vreturn = parse_redirection_in(tmp);

			break ;
		}
		if (tmp[j] == '>' && st == 0)
		{
			k = j;
			j = ft_strlen(tmp) - k;
			tmp = ft_substr(tmp, k, j);
			vreturn = parse_redirection_out(tmp);
			break ;
		}
		j++;
	}
}
