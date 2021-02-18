/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 11:54:14 by eriling           #+#    #+#             */
/*   Updated: 2021/02/18 11:31:19 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(char c, char const *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && is_set(s1[start], set))
		start++;
	if (s1[start] == '\0')
		return (ft_strdup(&s1[start]));
	end = ft_strlen(s1) - 1;
	while (end > 0 && is_set(s1[end], set))
		end--;
	return (ft_substr(s1, start, (end - start) + 1));
}
