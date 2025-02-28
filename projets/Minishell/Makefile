##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC =	mysh.c \
	src/string_to_array.c \
	src/get_path.c \
	src/check_files.c \
	src/handle_array.c \
	src/commands/commands.c \
	src/commands/cd.c \
	src/commands/env.c \
	src/errors/handling_error.c \
	src/errors/error_cd.c \
	src/errors/error_env.c \

LIB = libmy.a

NAME = mysh

NAME_DEBUG = mysh

OBJ = $(SRC:.c=.o)

WARNINGS = -Wextra -Wall -Werror

CFLAGS = -I./include -L./lib -lmy -g

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
	rm -f $(OBJ)
	make -C lib/my clean

fclean: 	clean
	rm -f $(NAME)
	make -C lib/my fclean

re:	fclean all

.PHONY: clean fclean re
