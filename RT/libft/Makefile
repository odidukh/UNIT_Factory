#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oponomar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/27 14:14:27 by oponomar          #+#    #+#              #
#    Updated: 2018/03/27 15:05:22 by oponomar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRCS =	$(wildcard *.c)

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $< 

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
