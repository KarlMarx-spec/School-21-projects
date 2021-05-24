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

NAME = libft.a

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c\
ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_calloc.c ft_strdup.c\
ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c\
ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_split.c\
ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c\
ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c\
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr.c\

OBJ = $(SRCS:.c=.o)

BONUS = ft_lstiter.c ft_lstmap.c ft_lstclear.c ft_lstadd_front.c\
ft_lstdelone.c ft_lstadd_back.c ft_lstlast.c ft_lstsize.c ft_lstnew.c $(SRCS)

OBJBON = $(BONUS:.c=.o)
INCLUDES = libft.h

all: $(NAME)

bonus: $(OBJ) $(OBJBON)
		ar rc $(NAME) $(OBJ) $(OBJBON)
		ranlib $(NAME)

%.o: %.c libft.h
	gcc -Wall -Wextra -Werror -c $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJBON)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(NAME)
