/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:11:42 by vmontero          #+#    #+#             */
/*   Updated: 2021/05/24 17:34:11 by vmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_freeval(char **s)
{
	free(*s);
	*s = NULL;
}

int	ft_cutline(char **s, char **line, int n)
{
	int		i;
	char	*temp;

	i = 0;
	if (!*s && !n)
	{
		*line = ft_strdup("");
		return (0);
	}
	while ((*s)[i] != '\n' && (*s)[i] != '\0')
		i++;
	if ((*s)[i] == '\0')
	{
		*line = ft_strdup(*s);
		ft_freeval(s);
	}
	else if ((*s)[i] == '\n')
	{
		*line = ft_substr(*s, 0, i);
		temp = ft_substr(*s, (i + 1), ft_strlen(*s));
		free(*s);
		*s = temp;
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*s[4096];
	char		*temp;
	int			n;

	n = read(fd, buff, BUFFER_SIZE);
	if (fd < 0 || !line || BUFFER_SIZE < 1 || n < 0)
		return (-1);
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
			break ;
		n = read(fd, buff, BUFFER_SIZE);
	}
	return (ft_cutline(&s[fd], line, n));
}
