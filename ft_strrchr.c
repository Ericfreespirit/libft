/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:29:47 by eriling           #+#    #+#             */
/*   Updated: 2020/10/28 17:44:05 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ss;
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	ss = (char *)s;
	while (i <= ft_strlen(ss))
	{
		if (ss[i] == (char)c)
			tmp = &ss[i];
		i++;
	}
	return (tmp);
}
