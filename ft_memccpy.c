/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:35:56 by eriling           #+#    #+#             */
/*   Updated: 2020/10/28 17:45:43 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int				i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	c_char;

	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	c_char = (unsigned char)c;
	i = 0;
	while (n--)
	{
		s1[i] = s2[i];
		if (s2[i] == c_char)
			return ((void *)&s1[i + 1]);
		i++;
	}
	return (NULL);
}
