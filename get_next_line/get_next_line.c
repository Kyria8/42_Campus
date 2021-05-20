/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:11:42 by vmontero          #+#    #+#             */
/*   Updated: 2021/05/20 14:25:34 by vmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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
//		printf("####%c###\n", (*s)[i]);
		i++;
	}
	if ((*s)[i] == '\0')
	{
		printf("**********\n");
		*line = ft_strdup(*s);
		free(*s);
	}
	else if ((*s)[i] == '\n')
	{
	//	printf("*****%s****\n", *s);
		*line = ft_substr(*s, 0, i);
//		printf("--->%s<----\n", *line);
//		printf("- dentro de cutline, line es: %s\n", *line);
		temp = ft_substr(*s, (i + 1), ft_strlen(*s));
//		printf("- Estoy en cutline, la tem es: %s\n", temp);
		free(*s);
		*s = temp;
		return(1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*s[4096];
	char		 *temp;
	int			n;

//	printf("He entrado en la funcion\n");
	n = read(fd, buff, BUFFER_SIZE);
//	printf("La lectura es: %d\n", n);
	if (fd < 0 || !line || BUFFER_SIZE < 1 || n < 0)
	{	
//		printf("PATADA EN LA ESPINILLA");
		return (-1);
	}
	while (n > 0)
	{
		printf("- Soy buff -------- %s-----\n", buff);
		buff[n] = 0;
		if (!s[fd])
			s[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = temp;
			printf("- LA estatiica es --------%s-------\n", s[fd]);
		}
		if (ft_strchr(buff, '\n'))
			break;
	//	else if(ft_strchr(buff, '\0') && n == 0)
	//	{
	//		printf("Estoy en el supuesto perdido de mierda");
	//		break;
	//	}
		n = read(fd, buff, BUFFER_SIZE);
	}
	if (!s[fd] && !n)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (cutline(&s[fd], line));
}

int main(void)
{
	int fd;
	char	*lines;
	int	r;

	printf("-Antes del antes, esta main\n");
	fd = open("text1.text", O_RDONLY);
	r = get_next_line(fd, &lines);
	printf("%d\n", r);
	printf("%s\n", lines);
	free(lines);
	printf("\n\n\n\n-----------------\n\n\n");
	
	r = get_next_line(fd, &lines);
	printf("%d\n", r);
	printf("%s\n", lines);
	free(lines);
	printf("\n\n\n\n-----------------\n\n\n");
	
	r = get_next_line(fd, &lines);
	printf("%d\n", r);
	printf("%s\n", lines);
	free(lines);
	printf("\n\n\n\n-----------------\n\n\n");
	
	r = get_next_line(fd, &lines);
	printf("%d\n", r);
	free(lines);
	printf("\n\n\n\n----------------\n\n\n");

	r = get_next_line(fd, &lines);
	free(lines);
}
