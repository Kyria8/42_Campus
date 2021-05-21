/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:01:06 by vmontero          #+#    #+#             */
/*   Updated: 2021/05/21 16:04:28 by vmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

int	cutline(char **s, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*s)[i] != '\n' && (*s)[i] != '\0')
	{
		i++;
	}
	if ((*s)[i] == '\0')
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = NULL;
	}
	else if ((*s)[i] == '\n')
	{
		*line = ft_substr(*s, 0, i);
		temp = ft_substr(*s, (i + 1), ft_strlen(*s));
		free(*s);
		*s = temp;
		return(1);
	}
	return (0);
}

int	get_next_line_bonus(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*s[4096];
	char		 *temp;
	int			n;

	n = read(fd, buff, BUFFER_SIZE);
	if (fd < 0 || !line || BUFFER_SIZE < 1 || n < 0)
	{
		return (-1);
	}
	while (n > 0)
	{
		buff[n] = '\0';
		if (!s[fd])
			s[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = temp;
		}
		if (ft_strchr(buff, '\n'))
			break;

		n = read(fd, buff, BUFFER_SIZE);
	}
	if (!s[fd] && !n)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (cutline(&s[fd], line));
}
