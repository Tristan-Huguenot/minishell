#include "minishell.h"

char	*var_dol_interogation(char *str, int i)
{
	char	*str1;
	char	*str2;

	str1 = ft_itoa(g_return);
	str2 = ft_substr(str, 0, i - 1);
	str2 = ft_strjoin_free(str2, str1);
	free(str1);
	if (str[i + 1])
		str1 = ft_substr(str, i + 1, ft_strlen(str) - (i));
	else
		str1 = ft_substr(str, i + 1, 1);
	free(str);
	str = ft_strjoin_free(str2, str1);
	free(str1);
	return (str);
}
