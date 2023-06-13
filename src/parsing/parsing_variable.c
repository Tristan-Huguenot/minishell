#include "minishell.h"

char	*var_dol_interogation(char *str, int i)
{
	char	*str1;
	char	*str2;

	str1 = ft_itoa(g_return);
	str2 = ft_substr(str, 0, i - 1);
	//printf("remove $? i - %d\n", i);
//	printf("_____str1 SDFSFD :%s\n", str1);
//	printf("_____str2 SDFSFD :%s\n", str2);
	str2 = ft_strjoin_free(str2, str1);
	// printf("_____str2 :%s\n", str2);
	free(str1);
	if (str[i + 1])
		str1 = ft_substr(str, i + 1, ft_strlen(str) - (i));
	else
		str1 = ft_substr(str, i + 1, 1);
	free(str);
	//printf("----str1 :%s\n", str1);
//	printf("_____str2 :%s\n", str2);
	str = ft_strjoin_free(str2, str1);
//	printf("+++++++++++++----str :%s\n", str);
	free(str1);
	return (str);
}

int	interpretation_var_q(char **str, int i, int j, t_env *env)
{
	while (str[i][j] && str[i][j] != '\"')
	{
	 	// printf("----str ++=  %s---\n", str[i]);
		// printf("j = %d && str[i][j]  = %c-------\n", j - 1, str[i][j - 1]);
		// if (str[i][j + 1] == '\"')
			// return (j - 1);
		if (str[i][j] == '$')
		{
			if (str[i][j + 1] && str[i][j + 1] == '\"')
			{
				printf("ici j = %d", j);
				return (j + 1);
			}
			if (str[i][j + 1] && str[i][j + 1] == '?')
				str[i] = var_dol_interogation(str[i], j + 1);
			// else if (str[i][j + 1] == '\0' && str[i + 1]
					// && ft_char_in_set(str[i + 1][0], CS_QUOTE))
			// {
			// //	printf("j = %d \n", j);
				// remove_dol(&str[i], j);
				// return (j - 1);
			// }
			else if (str[i][j + 1] && ft_isdigit(str[i][j + 1]))
			{
				remove_dol_num(&str[i], j);
				return (j - 1);
			}
			else
				j = interpretation_var(&str[i], j, env);
	//	printf("\t\t\t\t\tj = %d && str[i][j] = %c-------\n", j, str[i][j]);
			// if (j == -1)
			// {
				// j = 1;
				// break ;
			// }
		}
		j++;
	}
	return (j);
}


int	interpretation_dollar(char **str, int i, int j, t_env *env)
{
	printf("\t\t\t\t\t\tj = %d\n", j);
	if (str[i][0] == '\"')
	{
		printf("str avec les quotes  : %s et j = %d\n", str[i], j);
		j = interpretation_var_q(str, i, j, env);
		printf("str avec les quotes  : %s et j = %d\n", str[i], j);
	}
	if (str[i][j] == '$')
	{
		// printf("JJJJJJJJJJJ = %d-----------\n", j);
		if (str[i][j + 1] && str[i][j + 1] == '?')
		{
			//printf("go var_remove_dol?\n");
			str[i] = var_dol_interogation(str[i], j + 1);
		}
		else if (str[i][j + 1] && is_delim_space(str[i][j + 1]))
			return (j);

		else if (str[i][j + 1] == '\0' && str[i + 1]
				&& ft_char_in_set(str[i + 1][0], CS_QUOTE))
		{
			remove_dol(&str[i], j);
			return (j - 1);
		}
		else if (str[i][j + 1] && ft_isdigit(str[i][j + 1]))
		{
			remove_dol_num(&str[i], j);
			return (j - 1);
		}
		else if (str[i][j + 1] && !is_delim_space(str[i][j + 1]))
			j = interpretation_var(&str[i], j, env);
		if (j == -1)
			return (-1);
		printf("\t\t\t\t\t\tj = %d\n", j);
		printf("str[i][j] : %c\n",str[i][j]);
		if (!str[i] || str[i][j + 1] == '\0')
		{
			// printf("pas de suite 			\n");
			return (j);
		}
	}
	return (j - 1);
}

char	*parsing_variable(char *str, t_env *env)
{
	int		i;
	int		j;
	char	**str_tmp;
	char	*str2;

	// (void)env;
	str_tmp = split_tmp_var(str);
	free(str);
	i = 0;
	str2 = NULL;
	while (str_tmp[i])
	{
		printf("////------str[%d] -  %s------------- \n", i, str_tmp[i]);
		i++;
	}
	i = 0;
	while (str_tmp[i])
	{
		j = 0;
	//	printf("------str -  %s------------- \n", str_tmp[i]);
	// printf("___________________________________________\n");
	//	printf("str principale ===%s|\n", str_tmp[i]);
	//	printf("y ==%d && I ==%d\n", j, i);
		printf("_______________i = %d____________________________\n", i);
		if (str_tmp[i][j] != '\'' )
		{

			while (str_tmp[i][j])
			{			
				printf("----------------  J = %d ---------------------\n", j);
				// printf("test ici :: %s\n j == %d\n", str_tmp[i], j);
				// printf("test ici :: %c\n \n", str_tmp[i][j]);
				if (str_tmp[i][j] == '$')
				{
					printf("avant j = %d \n", j );
					j = interpretation_dollar(str_tmp, i, j, env);
					// printf("apres j = %d \n", j );
				}
				//printf("i = %d apres j = %d \n", i, j );
				j++;
				// printf(" a %s \n", str_tmp[i]);
			}
		}
		// printf("------str -  %s------------- \n", str_tmp[i]);
		// printf("------str -  %s------------- \n", str2);
		str2 = ft_strjoin_free(str2, str_tmp[i]);
		i++;
	}
	ft_free_strs(str_tmp);
	return (str2);
}
