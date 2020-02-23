NAME = computor

all: $(NAME)

$(NAME):
	echo '#!/bin/sh' > ./computor
	echo 'node ./computor.js "$$@"' >> ./computor
	chmod +x ./computor

clean:
	rm -f computor

fclean: clean
	rm -f computor

re: fclean all

.PHONY: all clean fclean re