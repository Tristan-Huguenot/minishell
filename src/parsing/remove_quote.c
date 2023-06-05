#include "minishell.h"

int	remove_quote(char **str, int i, char c)
{
	int		tmp;
	char	*str2;
	char	*str3;
	char	*str1;

	str2 = ft_substr(*str, 0, i);
	str1 = *str;
	tmp = i;
	i = first_quote(str1, i, c);
	if (i == -1)
		return (-1);
	str3 = ft_substr(str1, tmp + 1, i - tmp - 1);
	str2 = ft_strjoin_free(str2, str3);
	free(str3);
	str3 = ft_strdup(str1 + i + 1);
	*str = ft_strjoin(str2, str3);
	free(str2);
	free(str3);
	free(str1);
	i = i - 2;
	return (i);
}

char	*there_is_quote_to_remove(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		if (ft_char_in_set(str[i], CS_QUOTE))
		{
			i = remove_quote(&str, i, str[i]);
			if (i == -1 && str[i + 1] == '\0')
				break ;
		}
		i++;
	}
	return (str);
}
