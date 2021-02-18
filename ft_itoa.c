/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:02:03 by eriling           #+#    #+#             */
/*   Updated: 2021/02/18 12:17:08 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_ft_itoa(long *val, int *i, int *sign, int n)
{
	if (n < 0)
	{
		*val = - (long)n;
		*i = 2;
		*sign = -1;
	}
	else
	{
		*val = n;
		*i = 1;
		*sign = 0;
	}
}

void	*len_ft_itoa(long val, int i)
{
	while (val > 0)
	{
		val /= 10;
		i++;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	long	val;
	int		sign;
	char	*s;

	init_ft_itoa(&val, &i, &sign, n);
	len_ft_itoa(val, i);
	s = malloc(sizeof(*s) * i + 1);
	if (!s)
		return (NULL);
	s[i] = '\0';
	if (n < 0)
		val = - (long)n;
	else
		val = n;
	while (i-- + sign)
	{
		s[i] = (val % 10) + '0';
		val /= 10;
	}
	if (sign == -1)
		s[0] = '-';
	return (s);
}
