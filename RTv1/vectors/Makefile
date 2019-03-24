# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odidukh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/30 20:01:27 by odidukh           #+#    #+#              #
#    Updated: 2018/10/30 20:03:34 by odidukh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = vectors.a

FLAGS = -Wall -Wextra -Werror

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

HEADER = vector.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@gcc -c $(SRC) $(FLAGS)
	@ar rc $(NAME) $(OBJ) $(HEADER)
	@printf "Compailing vectors.a done\n"

.c.o: $(HEADER)
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@printf "All objects of vector operation library was deleted\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "Vector operation library is clean\n"

re: fclean all

.PHONY: all clean fclean re
