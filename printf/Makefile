# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfeijoa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/27 17:41:26 by wfeijoa           #+#    #+#              #
#    Updated: 2020/09/27 18:19:28 by wfeijoa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c parse.c printf_utils.c printf_utils2.c printf_utils3.c\
ft_digit.c ft_str.c ft_point.c ft_x.c ft_uns.c printf_utils4.c
OBJ = $(SRCS:.c=.o)

INCLUDES = printf.h

all: $(NAME)

%.o: %.c printf.h
	gcc -Wall -Wextra -Werror -c $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
