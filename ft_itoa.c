/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:02:03 by eriling           #+#    #+#             */
/*   Updated: 2020/10/28 17:45:50 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	long	val;
	int		sign;
	char	*s;

	val = (n < 0) ? -(long)n : n;
	i = (n < 0) ? 2 : 1;
	sign = (n < 0) ? -1 : 0;
	while (val /= 10)
		i++;
	if (!(s = malloc(sizeof(*s) * i + 1)))
		return (NULL);
	s[i] = '\0';
	val = (n < 0) ? -(long)n : n;
	while (i-- + sign)
	{
		s[i] = (val % 10) + '0';
		val /= 10;
	}
	sign == -1 ? s[0] = '-' : 0;
	return (s);
}
