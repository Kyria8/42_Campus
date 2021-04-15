# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmontero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/13 17:09:13 by vmontero          #+#    #+#              #
#    Updated: 2021/04/15 18:53:02 by vmontero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

SRCS = 	ft_atoi.c		\
		ft_bzero.c		\
		ft_isalpha.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_memset.c		\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_memcpy.c		\
		ft_memccpy.c	\
		ft_memmove.c	\
		ft_strlcpy.c	\
		ft_strncmp.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strlcat.c	\
		ft_strlen.c		\
		ft_tolower.c	\
		ft_toupper.c	\

OBJS = $(SRCS:.c=.o)

HEADER = libft.h

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) -I $(HEADER) $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
