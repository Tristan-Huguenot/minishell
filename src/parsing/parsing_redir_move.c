#include "minishell.h"

static char	*delete_redir(char *cmd, int redir)
{
	char	*first;
	char	*last;

	first = ft_substr(cmd, 0, redir);
	if (cmd[redir] && cmd[redir] == cmd[redir + 1])
		redir++;
	redir++;
	while (ft_char_in_set(cmd[redir], CS_WSPACE))
		redir++;
	while (cmd[redir] && !ft_char_in_set(cmd[redir], CS_WSPACE))
	{
		if (ft_char_in_set(cmd[redir], CS_REDIR))
			break ;
		if (ft_char_in_set(cmd[redir], CS_QUOTE))
			redir = first_quote(cmd, redir, cmd[redir]);
		redir++;
	}
	last = ft_strdup(cmd + redir);
	first = ft_strjoin_free(first, last);
	free(last);
	return (first);
}

static char	*get_redir_name(char *cmd, int redir)
{
	char	*name;
	int		end;

	if (cmd[redir] && cmd[redir] == cmd[redir + 1])
		redir++;
	redir++;
	while (ft_char_in_set(cmd[redir], CS_WSPACE))
		redir++;
	end = redir;
	while (cmd[end] && !ft_char_in_set(cmd[end], CS_WSPACE))
	{
		if (ft_char_in_set(cmd[end], CS_REDIR))
			break ;
		if (ft_char_in_set(cmd[end], CS_QUOTE))
			end = first_quote(cmd, end, cmd[end]);
		end++;
	}
	name = ft_substr(cmd, redir, end - redir);
	return (name);
}

static char	*get_redir_type(char *cmd, int redir)
{
	char	*type;

	type = ft_calloc(4, sizeof(*type));
	if (!type)
		return (type);
	if (cmd[redir] == '<')
		type[0] = '0';
	else
		type[0] = '1';
	if (cmd[redir] && cmd[redir] == cmd[redir + 1])
		type[1] = '2';
	else
		type[1] = '1';
	type[2] = '=';
	return (type);
}

void	move_redir(t_plot *plot, int size)
{
	char	*tmp;
	char	*name;
	int		redir;
	int		i;

	i = 0;
	while (i < size)
	{
		redir = jump_next_charset(plot->cmd, 0, CS_REDIR);
		tmp = get_redir_type(plot->cmd, redir);
		name = get_redir_name(plot->cmd, redir);
		tmp = ft_strjoin_free(tmp, name);
		free(name);
		plot->redir[i] = tmp;
		tmp = delete_redir(plot->cmd, redir);
		free(plot->cmd);
		plot->cmd = tmp;
		i++;
	}

}
