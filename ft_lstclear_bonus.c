/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:24:36 by eriling           #+#    #+#             */
/*   Updated: 2020/11/02 16:37:53 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*tmp;

	curr = NULL;
	if (lst && *lst && del)
	{
		curr = *lst;
		while (curr)
		{
			tmp = curr;
			curr = curr->next;
			ft_lstdelone(tmp, del);
		}
		*lst = NULL;
	}
}
