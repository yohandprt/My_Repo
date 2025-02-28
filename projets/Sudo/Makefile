##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC =	my_sudo.c \
	src/handling_error.c \
	src/get_args.c \
	src/verif.c \
	src/changes.c \
	src/passwd.c \
	src/command.c \

LIB = libmy.a

NAME = my_sudo

NAME_DEBUG = my_sudo

OBJ = $(SRC:.c=.o)

WARNINGS = -Wextra -Wall -Werror

CFLAGS = -Iinclude -Llib -lmy -lcsfml-window -lcsfml-graphics -lcsfml-system \
-lcrypt

$(NAME): 	$(LIB) $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS) $(WARNINGS)

$(NAME_DEBUG): $(LIB) $(OBG)
	gcc -g $(OBJ) -o $(NAME) $(CFLAGS) $(WARNINGS)

$(LIB):
	make -C lib/my

all:	$(NAME)

debug:	$(NAME_DEBUG)
	valgrind ./$(NAME_DEBUG) -g sudo

clean:
	rm $(OBJ)
	make -C lib/my clean

fclean: 	clean
	rm $(NAME)
	make -C lib/my fclean

re:	fclean $(NAME)

.PHONY: clean fclean re
