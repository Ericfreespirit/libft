/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:45:19 by eriling           #+#    #+#             */
/*   Updated: 2021/02/18 11:44:42 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*curr;

	curr = NULL;
	if (lst && f)
	{
		curr = lst;
		while (curr)
		{
			if (curr->content)
				(*f)(curr->content);
			curr = curr->next;
		}
	}
}
