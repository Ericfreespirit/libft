/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:16:51 by eriling           #+#    #+#             */
/*   Updated: 2021/02/18 09:35:02 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void 	is_fract(double *fract_part, int *div, char **str)
{
	*fract_part = *fract_part * 10 + (**str - '0');
	*div *= 10;
}

double	solve_ft_atof_2(char **str, double inter_part, double fr_part, int div)
{
	int	fract;

	fract = 0;
	while (**str)
	{
		if (**str >= '0' && **str <= '9')
		{
			if (fract)
				is_fract(&fr_part, &div, str);
			else
				inter_part = inter_part * 10 + (**str - '0');
		}
		else if (**str == '.')
		{
			if (fract)
				return (inter_part + fr_part / div);
			else
				fract = 1;
		}
		else
			break ;
		(*str)++;
	}
	return (inter_part + fr_part / div);
}

double	ft_atof_2(char **str)
{
	int		sign;
	double	inter_part;
	double	fract_part;
	int		div;

	if (!str)
		return (0);
	div = 1;
	inter_part = 0;
	fract_part = 0;
	sign = 1;
	while ((**str >= 9 && **str <= 13) || **str == ' ')
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign *= -1;
		(*str)++;
	}	
	return (sign * solve_ft_atof_2(str, inter_part, fract_part, div));
}
