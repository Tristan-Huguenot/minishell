/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_num_string.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:44:44 by thugueno          #+#    #+#             */
/*   Updated: 2023/06/14 15:35:05 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_NUM_STRING_H
# define LIBFT_NUM_STRING_H

# include "libft_string.h"

int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
char	*ft_itoa(int n);
char	*ft_ltoa(long n);
char	*ft_ultoa_base(unsigned long long int nb, char *base);

#endif
