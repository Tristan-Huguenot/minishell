/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:15:43 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 12:17:50 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_handler_sig_child(void)
{
	signal(SIGINT, sig_child);
	signal(SIGQUIT, sig_child);
}

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
