/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:17:35 by eriling           #+#    #+#             */
/*   Updated: 2020/10/28 17:44:42 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*new_s;

	i = 0;
	while (s[i])
		i++;
	if (!(new_s = malloc(sizeof(*new_s) * (i + 1))))
		return (NULL);
	new_s[i] = '\0';
	i = 0;
	while (s[i])
	{
		new_s[i] = s[i];
		i++;
	}
	return (new_s);
}
