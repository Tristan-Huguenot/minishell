#include "minishell.h"

int	split_element_without_quote(char *str, int i)
{
	while (str[i] && !ft_char_in_set(str[i], CS_QUOTE))
	{
		if (ft_char_in_set(str[i], CS_WSPACE))
		{
			i++;
			break;
		}
		i++;
	}
	return (i);
}

int	split_element(char *str, int i)
{
	int	tmp;

	tmp = 1;
	while (str[i] != '\0')
	{
		if (str[i] && ft_char_in_set(str[i], CS_QUOTE))
		{
			i = first_quote(str, i, str[i]);
			tmp++;
			i++;
		}
		// else if (str[i] && ft_char_in_set(str[i], CS_WSPACE))
		// {
			// while (str[i] && ft_char_in_set(str[i], CS_WSPACE))
				// i++;
			// tmp++;
		// }
		else if (str[i] && !ft_char_in_set(str[i], CS_QUOTE))
		{
			i = split_element_without_quote(str, i);
			tmp++;
		}
	}
	return (tmp);
}

// int	split_sub(int i, int tmp, char **str_split,i char *str)
// {
	// return (i);
// }

char	**split_tmp_var(char *str)
{
	char	**str_split;
	int		i;
	int		tmp;
	int		j;

	i = 0;
	tmp = split_element(str, i);
	j = 0;
	str_split = ft_calloc(sizeof(char *), tmp);
	tmp = i;
	while (str[i])
	{
		// printf("i = %d \t\t\t tmp = %d\n", i, tmp);
		// split_sub(i, tmp, str_split, str);
		if (str[i] && ft_char_in_set(str[i], CS_QUOTE))
		{
			i = first_quote(str, i, str[i]);
			str_split[j] = ft_substr(str, tmp, i - tmp + 1);
			// printf("-------\n str_split[j] = |%s|\n -------------\n", str_split[j]);
		}
		// else if (str[i] && !ft_char_in_set(str[i], CS_QUOTE) && ft_char_in_set(str[i], CS_WSPACE))
		// {
			// while (str[i] && !ft_char_in_set(str[i], CS_QUOTE) && ft_char_in_set(str[i], CS_WSPACE))
				// i++;
			// str_split[j] = ft_substr(str, tmp, i - tmp);
			// printf("-------\n str_split[j] = |%s|\n -------------\n", str_split[j]);
			// i--;
		// }
		else if (str[i] && !ft_char_in_set(str[i], CS_QUOTE))
		{
			while (str[i] && !ft_char_in_set(str[i], CS_QUOTE))
			{
				if (ft_char_in_set(str[i], CS_WSPACE))
				{
					i++;
					break;
				}
				i++;
			}
			str_split[j] = ft_substr(str, tmp, i - tmp);
			// printf("-------\n str_split[j] = |%s|\n -------------\n", str_split[j]);
			i--;
		}
		i++;
		j++;
		tmp = i;
	}
	return (str_split);
}
