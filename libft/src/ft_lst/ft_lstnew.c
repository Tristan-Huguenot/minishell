/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:11:31 by thugueno          #+#    #+#             */
/*   Updated: 2022/10/13 12:28:33 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_lst.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*new_el;

	new_el = ft_calloc(1, sizeof(*new_el));
	if (!new_el)
		return (new_el);
	new_el->content = content;
	new_el->next = NULL;
	return (new_el);
}
