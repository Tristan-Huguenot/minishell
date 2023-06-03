#include "minishell.h"

int	jump_next_redir(char *cmd, int i)
{
	while (cmd[i] && !ft_char_in_set(cmd[i], CS_REDIR))
	{
		if (ft_char_in_set(cmd[i], CS_QUOTE))
			i = first_quote(cmd, i, cmd[i]);
		if (i == -1)
		{
			while (cmd[i + 1])
				i++;
		}
		i++;
	}
	return (i);
}
