##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC =	my_radar.c \
	src/extern/decrease_str.c \
	src/extern/getting_infos.c \
	src/extern/parsing.c \
	src/extern/counts.c \
	src/extern/creating.c \
	src/extern/check_error.c \
	src/extern/event.c \

LIB = libmy.a

NAME = my_radar

NAME_DEBUG = my_radar

OBJ = $(SRC:.c=.o)

WARNINGS = -Wextra -Wall -Werror

CFLAGS = -Iinclude -Llib -lmy -lcsfml-window -lcsfml-graphics -lcsfml-system \
-lm

$(NAME): 	$(LIB) $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS) $(WARNINGS)

$(NAME_DEBUG): $(LIB) $(OBG)
	gcc -g $(OBJ) -o $(NAME) $(CFLAGS) $(WARNINGS)

$(LIB):
	make -C lib/my

all:	$(NAME)

debug:	$(NAME_DEBUG)
	valgrind ./$(NAME_DEBUG)

clean:
	rm $(OBJ)
	make -C lib/my clean

fclean: 	clean
	rm $(NAME)
	make -C lib/my fclean

re:	fclean $(NAME)

.PHONY: clean fclean re
