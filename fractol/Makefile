# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odidukh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/04 16:18:03 by odidukh           #+#    #+#              #
#    Updated: 2018/10/07 20:09:57 by odidukh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -O3 -pthread

GFLAGS = -lmlx -framework OpenGL -framework AppKit 

all: $(NAME)

$(NAME): lib $(OBJ)
	@gcc $(OBJ) libft/libft.a -I libft -o $(NAME) $(GFLAGS)

%.o: %.c fractol.h
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

lib:
	make -C libft
normin:
	norminette $(SRC)

.PHONY: all clean re lib
