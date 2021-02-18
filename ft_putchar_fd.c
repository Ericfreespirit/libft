/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:27:33 by eriling           #+#    #+#             */
/*   Updated: 2021/02/18 11:42:16 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	uni[2];

	if (c >= 0)
	{
		write(fd, &c, 1);
		return ;
	}
	if (c >= -64)
		uni[0] = 195;
	else
		uni[0] = 194;
	if (c >= -64)
		uni[1] = c + 192;
	else
		uni[1] = c + 256;
	write(fd, uni, 2);
}
