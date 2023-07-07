#include "minishell.h"

void	set_handler_sig_parent(void)
{	
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	set_handler_sig_hered(void)
{
	signal(SIGINT, signal_handler_hd);
	signal(SIGQUIT, SIG_IGN);
}

void	signal_handler_hd(int sig)
{
	char	c;

	if (sig == SIGINT)
		close(0);
	c = '\0';
	write(1, &c, 1);
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
