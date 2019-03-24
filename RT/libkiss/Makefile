
NAME = libkiss.a

SRCS = ./kiss_draw.c\
	./kiss_general.c\
	./kiss_posix.c\
	./kiss_widgets.c

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall --std=c89

UNAME_S = $(shell uname -s)
	ifeq ($(UNAME_S),Darwin)
		FLAGS += -I ../frameworks/SDL2.framework/Headers \
				-I ../frameworks/SDL2_ttf.framework/Headers \
				-I ../frameworks/SDL2_image.framework/Headers
	endif

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o: %.c
	@clang $(FLAGS) -o $@ -c $< 

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all


