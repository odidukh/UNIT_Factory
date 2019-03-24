# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proshchy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/04 15:44:07 by proshchy          #+#    #+#              #
#    Updated: 2018/02/13 14:35:07 by odidukh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

HEADER = libft.h

FLAGS = -Wall -Werror -Wextra

SRC = $(wildcard ./*.c)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@gcc -c $(SRC) $(FLAGS)
	@ar rc $(NAME) $(OBJ) $(HEADER)
	@printf "Compailing libft.a done\n"

.c.o: $(HEADER)
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@printf "All objects of libft was deleted\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "Libft is clean\n"

re: fclean all

.PHONY: all clean fclean re