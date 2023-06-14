#include "minishell.h"

int	pwd(void)
{
	char	*buf;

	buf = malloc(sizeof(char) * PATH_MAX);
	if (!buf)
		return (1);
	if (!getcwd(buf, PATH_MAX))
		perror("pwd error:");
	else
		printf("%s \n", buf);
	return (0);
}
