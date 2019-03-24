# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odidukh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/30 19:56:44 by odidukh           #+#    #+#              #
#    Updated: 2018/10/31 14:21:18 by odidukh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

SRC = $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

LIBS = libft/libft.a vectors/vectors.a

HEADERS = -I ./includes -I ./libft -I ./vectors

HDR = includes/rtv1.h

FLAGS = -Wall -Wextra -Werror

CGFLAGS = -lmlx -framework OpenGL -framework AppKit

INCLUDES	=	-I./frameworks/SDL2.framework/Versions/A/Headers \
				-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I./frameworks/SDL2_image.framework/Versions/A/Headers \
				-I./frameworks/SDL2_mixer.framework/Headers \
				-F./frameworks/

FRAMEWORKS	=	-F./frameworks \
				-rpath ./frameworks \
				-framework OpenGL -framework AppKit -framework OpenCl \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image \
				-framework SDL2_mixer

all: $(NAME)

$(NAME): libft/libft.a vectors/vectors.a $(OBJ) $(HDR)
	@gcc $(FLAGS) $(CGFLAGS) $(FRAMEWORKS) $(OBJ) $(LIBS) -o $(NAME)
	@printf "Compailing RTv1 done\n"

.c.o: $(HDR)
	@gcc $(FLAGS) $(INCLUDES) $(HEADERS) -c $< -o $@

clean:
	@make clean -C libft
	@make clean -C vectors
	@rm -rf $(OBJ)
	@printf "All objects of RTv1 was deleted\n"

fclean:
	@make fclean -C libft
	@make fclean -C vectors
	@rm -rf $(OBJ)
	@rm -rf $(NAME)
	@printf "All objects and binary of RTv1 was deleted\n"

libft/libft.a:
	@make -C libft

vectors/vectors.a:
	@make -C vectors

re: fclean all
