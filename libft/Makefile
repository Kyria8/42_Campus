# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmontero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/13 17:09:13 by vmontero          #+#    #+#              #
#    Updated: 2021/04/13 19:02:52 by vmontero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

SRCS = 	ft_bzero.c		\
		ft_memset.c		\
		ft_memcpy.c		\
		ft_memccpy.c	\
		ft_memmove.c	\

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
