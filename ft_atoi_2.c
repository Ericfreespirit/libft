/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:10:41 by eriling           #+#    #+#             */
/*   Updated: 2021/02/18 09:36:42 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_2(char **str)
{
	long	sign;
	long	nb;

	sign = 1;
	nb = 0;
	while ((**str >= 9 && **str <= 13) || **str == ' ')
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign *= -1;
		(*str)++;
	}
	while (**str && **str >= '0' && **str <= '9')
	{
		nb = (nb * 10) + (**str - '0');
		if (nb < 0 && sign == -1)
			return (0);
		else if (nb < 0 && sign == 1)
			return (-1);
		(*str)++;
	}
	return (nb * sign);
}
