/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:52:58 by eriling           #+#    #+#             */
/*   Updated: 2021/02/18 11:44:24 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*curr;
	t_list	*new;
	t_list	*tmp;

	curr = NULL;
	new = NULL;
	if (!lst || !f)
		return (NULL);
	curr = lst;
	while (curr)
	{
		tmp = ft_lstnew(f(curr->content));
		if (tmp)
			ft_lstadd_back(&new, tmp);
		else
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		curr = curr->next;
	}
	return (new);
}
