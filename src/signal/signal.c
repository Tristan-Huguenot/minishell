#include "minishell.h"

void	signal_handler_hd(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		return ;
	}
}

void	sig_child(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		g_return = 130;
	}
	if (sig == SIGQUIT)
	{
		printf("Quit (core dumped)\n");
		g_return = 131;
	}
}

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		g_return = 130;
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
		return ;
	}
}
