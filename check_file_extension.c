/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_extension.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:39:50 by eriling           #+#    #+#             */
/*   Updated: 2021/02/16 11:06:45 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_file_extension(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i])
		i++;
	while (i > 0)
	{
		if (s2[i] == '.')
			break ;
		i--;
	}
	while (*s1 && (*s1 == s2[i]))
	{
		s1++;
		i++;
		if (*s1 == '\0' && s2[i] == '\0')
			return (1);
	}
	return (0);
}
