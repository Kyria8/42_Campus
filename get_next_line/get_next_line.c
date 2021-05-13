/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:11:42 by vmontero          #+#    #+#             */
/*   Updated: 2021/05/13 13:52:26 by vmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

# define BUFFER_SIZE 25

char	*ft_select(char *src, char end)
{
	int		i;
	//int		j;
	char	*res;
	//char	*aux;

	i = 0;
	printf("-Acabo de entrar y src es: .......%s\n", src);
	while (src[i] != end)
	{
		i++;
	}
	printf("-Soy la cantidad de caracteres que tengo %d\n", i);
	res = malloc(sizeof(char) * i + 1);
	res = ft_substr(src, 0, i);
	res[i] = '\0';
	//aux = res;
	//free(res);
	printf("-Estoy en la funcion select\n");
	printf("-Soy el res que devuelve la funcion select: .....%s\n", res);
	return (res);
}

char	*cutline(char **s, char *line)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*s)[i] != '\n' && (*s)[i] != '\0')
	   i++;
	if (i < ft_strlen(*s))
	{
		*line = ft_substr(*s, 0, i);
		temp = ft_substr(*s, i, ft_strlen(*s));
		free(*s);
		*s = temp;
	}
	return (line);
}

int	get_next_line(int fd, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	static char	*s[4096];
	char *temp;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
	{	
		printf("PATADA EN LA ESPINILLA");
		return (-1);
	}
	while (read(fd, buff, BUFFER_SIZE) > 0)
	{
		if (!s[fd])
			s[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = temp;
		}
		if (ft_strchr(s[fd], '\n'))
			break;
	}
	if (!s[fd] && (read(fd, buff, BUFFER_SIZE) <= 0))
	{
		*line = ft_strdup("");
		return (0);
	}
	else
	{
		*line = cutline(&s[fd], *line);
		//s[fd] = cutline(&s[fd]);
	}
	return (1);
}

int main(void)
{
	int fd;
	char	*lines;

	printf("-Antes del antes, esta main\n");
	fd = open("text1.text", O_RDWR);
	get_next_line(fd, &lines);
	free(lines);
	printf("\n\n\n\n-----------------\n\n\n");
	
	get_next_line(fd, &lines);
	free(lines);
	printf("\n\n\n\n----------------\n\n\n");

	get_next_line(fd, &lines);
	free(lines);
}
