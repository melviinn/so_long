/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:07:11 by mduchauf          #+#    #+#             */
/*   Updated: 2023/11/09 12:07:12 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	node = NULL;
	while (lst)
	{
		new_node = ft_lstnew((*f)(lst->content));
		if (!new_node)
		{
			ft_lstclear(&node, (*del));
			return (NULL);
		}
		ft_lstadd_back(&node, new_node);
		lst = lst->next;
	}
	new_node->next = NULL;
	return (node);
}
