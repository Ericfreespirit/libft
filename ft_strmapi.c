/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:53:13 by eriling           #+#    #+#             */
/*   Updated: 2021/02/18 11:32:39 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dst;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	dst = ft_strdup(s);
	if (dst == NULL)
		return (NULL);
	while (dst[i])
	{
		dst[i] = (*f)(i, dst[i]);
		i++;
	}
	return (dst);
}
