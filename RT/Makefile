# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/21 15:54:29 by oponomar          #+#    #+#              #
#    Updated: 2019/03/22 12:44:38 by oponomar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RT

SRCS =	$(wildcard srcs/*.c)

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra -g

MAIN_HEADERS = -I ./include -I ./libft -I ./libkiss 

LIB = -L libft -lft -L libkiss -lkiss -lm -lpthread

UNAME_S = $(shell uname -s)
	ifeq ($(UNAME_S),Darwin)
		SDL_HEADERS = -I ./frameworks/SDL2.framework/Headers \
					-I ./frameworks/SDL2_ttf.framework/Headers \
					-I ./frameworks/SDL2_image.framework/Headers
		SDL_FRAMEWORKS = -rpath @loader_path/frameworks -F./frameworks/ \
						-framework SDL2 -framework SDL2_image \
						-framework SDL2_ttf
	endif
	ifeq ($(UNAME_S),Linux)
		LIB += -lSDL2 -lSDL2_image -lSDL2_ttf
	endif

all:			MKLIB $(NAME)

MKLIB:
	@make all -C libft
	@make all -C libkiss

$(NAME):		$(OBJ)
	@clang $(OBJ) $(MAIN_HEADERS) $(SDL_HEADERS) $(SDL_FRAMEWORKS) $(LIB) -o $(NAME)
	@printf "RT compilation was done\n"


%.o: %.c ./include/rt.h
	@clang $(FLAGS) $(MAIN_HEADERS) $(SDL_HEADERS) -c $< -o $@

clean:
	@make clean -C libft
	@make clean -C libkiss
	@rm -f $(OBJ)
	@printf "All objects of RT were deleted\n"

fclean:			clean
	@make fclean -C libft
	@make fclean -C libkiss
	@rm -f $(NAME)
	@printf "All objects and binary of RT were deleted\n"

re:				fclean all
