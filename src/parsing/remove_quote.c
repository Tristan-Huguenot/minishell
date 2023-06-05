#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>
#include "../../libft/include/libft.h"

typedef struct s_plot
{
	char			*cmd;
	char			**cmd_arg;
	int				argc;
	char			**in;
	char			**out;
	struct s_plot	*next;
}	t_plot;

int	first_quote(char *input, int i, char q);

char	*remove_quote(char *str, int i, char c)
{
	int		size;
	int		tmp;
	char	*str2;
	char	*str3;
	char	*str1;

	str2 = ft_substr(str, 0, i);
	str1 = ft_strdup(str);
	str3 = NULL;
	// free(str);
	while (str1[i])
	{
		tmp = i;
		if (str1[i] == c)
		{
			i = first_quote(str1, i, c);
			if (i == -1)
				break ;
			str3 = ft_substr(str1, tmp + 1, i - tmp - 1);
			str2 = ft_strjoin_free(str2, str3);
			free(str3);
			// if (*str1 + i != '\0')
				str = ft_strdup(str1 + i + 1);
			// else
				// str = ft_strdup(str1 + i);
			// 
			printf("i == %di and tmp = %d ", i, tmp);
			printf("\tstr --> %s\n", str);
			printf("\tstr2 --> %s\n", str2);
			printf("\tstr1 --> %s\n", str1);
			free(str1);
			str1 = ft_strjoin(str2, str);
			free(str2);
			str2 = ft_substr(str1, 0, i);
			free(str);
			i = i - 2;
		}
		if (str1[i])
			i++;
	}	
	free(str2);
	printf("----%s-----\n", str1);
	return (str1);
}

void	there_is_quote_to_remove(char **cmd_arg)
{
	char	**tab;
	int		i;
	int		j;

	i = 1;
	tab = cmd_arg;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '\'' || tab[i][j] == '\"')
			{
				tab[i] = remove_quote(tab[i], j, tab[i][j]);
				break ;
			}
			j++;
		}
		i++;
	}
	i = 1;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{

	if (argc < 2)
		return (1);
	
	there_is_quote_to_remove(argv);
	return (0);
}
