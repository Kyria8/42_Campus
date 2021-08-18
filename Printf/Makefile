# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmontero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 16:36:36 by vmontero          #+#    #+#              #
#    Updated: 2021/05/31 17:23:48 by vmontero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ./libft/libft.a

FLAGS = -Wall -Werror -Wextra

CC = gcc

RM = rm -f

AR = ar rcs

SRCS = ft_printf.c		\
		ft_data.C		\
		ft_flags		\
		ft_ft_type.c

OBJS = $(SRCS:.c=.o)

$(NAME):	$(OBJS)
			$(MAKE) -C ./libft
			cp libft/libft.a $(NAME)

			$(AR)	$(NAME)		$(OBJS)

all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(RM)	$(OBJS)

fclean: clean
		$(MAKE) -C ./libft
		$(RM)	$(NAME)

re: fclean all

.PHONY: all bonus clean fclean
