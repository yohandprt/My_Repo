##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC =	organized.c \
	src/extern/external_add.c \
	src/extern/external_del.c \
	src/extern/external_sort.c \

LIB = libmy.a

NAME = organized

NAME_DEBUG = organized

OBJ = $(SRC:.c=.o)

WARNINGS = -Wextra -Wall -Werror

CFLAGS = -I./include -L./lib -L./lib -lmy -lshell

$(NAME):	$(LIB) $(OBJ)
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
