/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:11:42 by vmontero          #+#    #+#             */
/*   Updated: 2021/05/07 18:00:36 by vmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

# define BUFFER_SIZE 5

char	*ft_select(char *src, char end)
{
	int		i;
	char	*res;

	i = 0;
	while (src[i] != end)
	{
		i++;
	}
	res = malloc(sizeof(char) * i);
	i = 0;
	while (src[i++] != end)
	{
		res[i] = src[i];
	}
	printf("Estoy en la funcion select\n");
	printf("%s\n", res);
	return (res);
}

int	get_next_line(int fd, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	static char	*s[4096];
	char *temp;

	temp = "";
	printf("Antes del bucle\n");
	while (read(fd, buff, BUFFER_SIZE) != 0)
	{
		temp = ft_strjoin(temp, buff);
		printf("Estamos en el bucle\n");
		if (ft_strchr(temp, '\n') != 0)
			{
	 			*line = ft_select(temp, '\n');
				*s = ft_strchr(temp, '\n');
				printf("%s\n", *s + 1);
				printf("%s\n", *line);
				break;
			}
	}
	//free(temp);


	//printf("%d\n", fd);
//	printf("%zd\n", nr_bytes);
//	printf("%s\n", *line);
//	printf("%s\n", *s + 1);
	return (0);
}

int main(void)
{
	int fd;
	char	*lines;

	printf("Antes del antes\n");
	fd = open("text1.text", O_RDWR);
	get_next_line(fd, &lines);
}
