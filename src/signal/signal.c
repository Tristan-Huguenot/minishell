#include "minishell.h"

// void	sig_heredoc(int sig)
// {
	// if ()
	// 
// }

// void	sig_child(void)
// {
	// if ()
		// kill(pid)
// }

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
