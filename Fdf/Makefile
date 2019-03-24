# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odidukh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/16 14:09:53 by odidukh           #+#    #+#              #
#    Updated: 2018/09/17 21:50:53 by odidukh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MFLAGS = -framework OpenGL -framework AppKit -lmlx

SRCS = $(wildcard src/*.c)

OBJ = $(SRCS:.c=.o)

NAME = fdf

FLAGS = -Wall -Wextra -Werror 

all: $(OBJ)
	@gcc $(SRCS) $(MFLAGS) libft/libft.a -o $(NAME)

$(NAME): all

%.o: %.c
	gcc -o $@ -c $< $(FLAGS) 

re: relib fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

lib: 
	make -C libft

relib:
	make -C libft re
normin:
	norminette $(SRCS)
.PHONY: all clean re lib
