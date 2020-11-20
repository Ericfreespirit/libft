/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:01:47 by eriling           #+#    #+#             */
/*   Updated: 2020/11/20 10:22:20 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		is_blank(char letter, char c)
{
	if (letter == c)
		return (1);
	return (0);
}

int		c_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (is_blank(s[i], c))
		i++;
	while (s[i])
	{
		if (s[i] && (!is_blank(s[i], c) && ((is_blank(s[i - 1], c) || i == 0))))
			count++;
		i++;
	}
	return (count);
}

char	*add_string(char const *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (!is_blank(s[i], c))
		i++;
	if (!(str = malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	i = 0;
	while (!is_blank(s[i], c))
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s || (!(array = malloc(sizeof(*array) * (c_word(s, c) + 1)))))
		return (NULL);
	while (is_blank(s[i], c))
		i++;
	while (s[i])
	{
		if (s[i] && (!is_blank(s[i], c) && ((is_blank(s[i - 1], c) || i == 0))))
			array[j++] = add_string(&s[i], c);
		i++;
	}
	array[j] = 0;
	return (array);
}

int main(int ac, char **av)
{
	char **range;
	int	i;

	i = 0;
	if (ac == 3)
	{
		range = ft_split(av[1], *av[2]);
		while (i < c_word(av[1], *av[2]))
		{
			printf("%s\n", range[i]);
			i++;
		}
	}
	return (0);
}