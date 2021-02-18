/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:02:27 by eriling           #+#    #+#             */
/*   Updated: 2021/02/18 11:30:40 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ss;
	unsigned int	i;

	i = 0;
	ss = malloc(sizeof(*ss) * (len + 1));
	if (!s || ss == NULL)
		return (NULL);
	while (ft_strlen(s) > start && i < len)
		ss[i++] = s[start++];
	ss[i] = '\0';
	return (ss);
}
