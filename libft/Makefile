# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmontero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/13 17:09:13 by vmontero          #+#    #+#              #
#    Updated: 2021/04/17 20:40:05 by vmontero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

CC = gcc 

RM = rm -f

AR = ar rcs

SRCS = 	ft_atoi.c		\
		ft_bzero.c		\
		ft_calloc.c		\
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
		ft_putchar_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_putstr_fd.c	\
		ft_strdup.c		\
		ft_strjoin.c	\
		ft_strlcpy.c	\
		ft_strncmp.c	\
		ft_strnstr.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strlcat.c	\
		ft_strlen.c		\
		ft_substr.c		\
		ft_tolower.c	\
		ft_toupper.c	\

OBJS = $(SRCS:.c=.o)

HEADER = libft.h

all: $(NAME)

$(NAME):	$(SRCS)
			$(CC)  $(FLAGS) -I $(HEADER) -c  $(SRCS)
			$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean
