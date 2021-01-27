/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:09:28 by eriling           #+#    #+#             */
/*   Updated: 2020/11/27 11:01:41 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_free_str(char **s)
{
	if (s != NULL && *s != NULL)
	{
		free(*s);
		*s = NULL;
	}
}

static int	save_line(char **str, char **line)
{
	int		l;
	char	*tmp;

	l = 0;
	while ((*str)[l] != '\n' && (*str)[l] != '\0')
		l++;
	if ((*str)[l] == '\n')
	{
		*line = ft_substr(*str, 0, l);
		tmp = ft_strdup(&((*str)[l + 1]));
		ft_free_str(str);
		*str = tmp;
		if ((**str) == '\0')
			ft_free_str(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_free_str(str);
		*str = NULL;
		return (0);
	}
	return (1);
}

static int	filter(char **str, int fd, char **line, int r)
{
	if (r == 0 && !str[fd])
	{
		*line = ft_strdup("");
		return (0);
	}
	else if (r < 0)
		return (-1);
	return (save_line(&str[fd], line));
}

int			get_next_line(const int fd, char **line)
{
	int			r;
	char		*tmp;
	static char	*str[256];
	char		buff[BUFFER_SIZE + 1];

	if (fd < 0 || !line || fd > 256 || BUFFER_SIZE <= 0)
		return (-1);
	while ((r = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = tmp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (filter(str, fd, line, r));
}
