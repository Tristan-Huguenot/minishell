/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:48:55 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/24 20:07:25 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

void	parsing_prompt(char *input);
void	parsing_redirection(char **input, int st);
int		wrong_quote(char *input);

#endif
