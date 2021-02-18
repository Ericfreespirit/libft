/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 10:41:03 by eriling           #+#    #+#             */
/*   Updated: 2020/10/28 17:45:38 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	char			*ss;

	ss = (char *)s;
	i = 0;
	while (i < n)
	{
		if (ss[i] == c)
			return (&ss[i]);
		i++;
	}
	return (NULL);
}
