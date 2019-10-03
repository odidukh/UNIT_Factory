NAME = computor

all: $(NAME)

$(NAME):
	npm i
	echo '#!/bin/sh' > ./computor
	echo 'node ./computor.js "$$@"' >> ./computor
	chmod +x ./computor

clean:
	rm -rf node_modules

fclean: clean
	rm -f computor

re: fclean all

.PHONY: all clean fclean re