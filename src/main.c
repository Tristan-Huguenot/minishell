/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:35:10 by thugueno          #+#    #+#             */
/*   Updated: 2023/07/10 10:35:10 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_return = 0;

int	main(int argc, char **argv, char **envp)
{
	t_param	*param;

	param = init_param(argv[0] + 2, envp);
	if (argc != 1)
	{
		error_argc(param, argv[1]);
		exit_program(param);
	}
	while (1)
	{
		set_handler_sig_parent();
		prompt_in(param);
	}
	g_return = 0;
	exit_program(param);
}
