/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:08:40 by thugueno          #+#    #+#             */
/*   Updated: 2022/10/04 16:51:46 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

static void	free_strs(char **strs, size_t i)
{
	size_t	y;

	y = 0;
	while (y <= i)
	{
		free(strs[y]);
		y++;
	}
	free(strs);
}

static char	*get_word_x(char const *s, char c, int x)
{
	size_t	i;
	size_t	y;
	int		words;
	char	*str;

	words = 0;
	i = 0;
	while (words != x)
	{
		y = 0;
		while (s[i] == c)
			i++;
		if (s[i])
			words++;
		while (s[i + y] != c && s[i + y])
			y++;
		if (words != x)
			i += y;
	}
	str = malloc(sizeof(*str) * (y + 1));
	if (str == NULL)
		return (str);
	ft_strlcpy(str, s + i, y + 1);
	return (str);
}

static int	count_words(char const *s, char c)
{
	size_t	i;
	int		words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			words++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		words;
	int		i;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	strs = malloc(sizeof(*strs) * (words + 1));
	if (strs == NULL)
		return (strs);
	i = 0;
	while (i < words)
	{
		strs[i] = get_word_x(s, c, i + 1);
		if (strs[i] == NULL)
		{
			free_strs(strs, i);
			return (NULL);
		}
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
