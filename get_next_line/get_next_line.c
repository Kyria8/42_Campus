/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:11:42 by vmontero          #+#    #+#             */
/*   Updated: 2021/05/07 18:23:37 by vmontero         ###   ########.fr       */
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
	printf("Acabo de entrar y src es: .......%s\n", src);
	while (src[i] != end)
	{
		i++;
	}
	//printf("%d\n", i);
	res = malloc(sizeof(char) * i + 1);
	i = -1;
	while (src[i++] != end)
	{
		res[i] = src[i];
		printf("Estoy dentro del bucle de la funcion y res va siendo: ......%c\n", res[i]);
	}
	printf("Estoy en la funcion select\n");
	printf("Soy el res que devuelve la funcion select: .....%s\n", res);
	return (res);
}

int	get_next_line(int fd, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	static char	*s[4096];
	char *temp;

	if (!fd)
		return (-1);
	temp = "";
	printf("Antes del bucle dentro de Get Next Line, empezamos\n");
	while (read(fd, buff, BUFFER_SIZE) != 0)
	{
		temp = ft_strjoin(temp, buff);
		printf("Estamos en el bucle\n");
		if (ft_strchr(temp, '\n') != 0)
			{
	 			*line = ft_select(temp, '\n');
				*s = ft_strchr(temp, '\n');
				printf("Soy lo que va a guardar la variable estatica: ....%s\n", *s + 1);
				printf("Soy lo que se va a guardar en line: ...%s\n", *line);
				break;
			}
	}
	//free(temp);


	//printf("%d\n", fd);
	return (0);
}

int main(void)
{
	int fd;
	char	*lines;

	printf("Antes del antes, esta main\n");
	fd = open("text1.text", O_RDWR);
	get_next_line(fd, &lines);
}
