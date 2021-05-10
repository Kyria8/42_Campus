/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:11:42 by vmontero          #+#    #+#             */
/*   Updated: 2021/05/10 18:47:26 by vmontero         ###   ########.fr       */
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
	int		j;
	char	*res;
	char	*aux;

	i = 0;
	j = 0;
	printf("-Acabo de entrar y src es: .......%s\n", src);
	while (src[i] != end)
	{
		i++;
	}
	printf("-Soy la cantidad de caracteres que tengo %d\n", i);
	res = malloc(sizeof(char) * i + 1);
	while (i-- > 0)
	{
		res[j] = src[j];
		j++;
		//printf("-Estoy dentro del bucle de la funcion y res va siendo: ......%c\n", res[j]);
	}
	res[j] = '\0';
	//aux = res;
	//free(res);
	printf("-Estoy en la funcion select\n");
	printf("-Soy el res que devuelve la funcion select: .....%s\n", res);
	return (res);
}

char	*cutline(char **s)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*s)[i] != '\n' && (*s)[i] != '\0')
	   i++;
	if ((*s)[i] == '\n')
	{
		temp = ft_substr(*s, 0, i);
		*s = ft_strdup(&(*s)[i + 1]);
	}
	else if ((*s)[i] == '\0')
	{
		temp = ft_strdup(*s);
		free(*s);
		*s = NULL;
	}
	return (temp);
}

int	get_next_line(int fd, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	static char	*s[4096];
	char *temp;
	int n;

	if (!fd || !line || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
	{	
		printf("PATADA EN LA ESPINILLA");
		return (-1);
	}
	temp = "";
	if (!*s)
	{
		*s = ft_strdup("");
		printf("IF DE S");
	}
	printf("-Antes del bucle dentro de Get Next Line, empezamos\n");
	if (*s && ft_strchr(*s, '\n') != 0)
		{
			printf("- Estoy en el primer if con s estática llena de cosas\n");
			*line = cutline(&s[fd]);
			return (1);
		}
	n = read(fd,buff, BUFFER_SIZE);
	while (n > 0)
	{
			buff[n] = 0;
		if (!*s)
		{
			
			n = read(fd,buff, BUFFER_SIZE);
			//temp = ft_strjoin(temp, buff);
			printf("PRUEBA RUBEN --->%s<------", temp);
			printf("-Estamos en el bucle\n");

			temp = ft_strjoin(temp, buff);
			if (ft_strchr(temp, '\n') != 0)
				{
	 				*line = ft_select(temp, '\n');
					*s = ft_strchr(temp, '\n');
					printf("-Soy lo que va a guardar la variable estatica: ....%s\n", *s);
					printf("-Soy lo que se va a guardar en line: ...%s\n", *line);
					return (1);
				}
			else
			{
	 				*line = ft_select(temp, '\0');
					*s = ft_strchr(temp, '\0');

			}
		}
		else
		{
			printf("-Segunda llamada a funcion, s tiene cosas que juntar\n");
			temp = ft_strjoin(*s, buff);
			*s = NULL;	
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

	printf("-Antes del antes, esta main\n");
	fd = open("text1.text", O_RDWR);
	get_next_line(fd, &lines);
	free(lines);
	printf("\n\n\n\n-----------------\n\n\n");
	
	get_next_line(fd, &lines);
	free(lines);
	get_next_line(fd, &lines);
	free(lines);
}
