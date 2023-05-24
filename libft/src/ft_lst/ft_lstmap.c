/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugueno <thugueno@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:08:14 by thugueno          #+#    #+#             */
/*   Updated: 2022/10/13 15:55:21 by thugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_lst.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**list;
	t_list	*tmp;

	list = ft_calloc(1, sizeof(*list));
	if (!lst || !f || !del || !list)
		return (NULL);
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (tmp == NULL)
		{
			ft_lstclear(list, del);
			free(list);
			return (tmp);
		}
		ft_lstadd_back(list, tmp);
		lst = lst->next;
	}
	tmp = *list;
	free(list);
	return (tmp);
}
