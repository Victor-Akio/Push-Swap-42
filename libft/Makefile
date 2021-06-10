# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 12:18:16 by hbuisser          #+#    #+#              #
#    Updated: 2021/06/03 08:08:44 by vminomiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -g -fsanitize=address -Wall -Wextra -Werror -I $(HEADER)

SRCS =	*.c

OBJECTS = $(SRCS:%.c=%.o)

CC = gcc

REM = rm -rf

HEADER = ./

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJECTS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	$(REM) $(OBJECTS)

fclean: clean
	$(REM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
