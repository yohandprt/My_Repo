##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

SRC =	src/extern/hashtable.c \
	src/extern/hash.c \
	src/extern/handle_table.c \

OBJ = $(SRC:.c=.o)

NAME = libhashtable.a

all: $(NAME)

$(NAME):        $(OBJ)
	ar rc $(NAME) $(OBJ)
	make -C lib/my/

clean:
	rm -f $(OBJ)
	make -C lib/my clean

fclean: clean
	rm -f $(NAME)
	make -C lib/my fclean

re: fclean $(NAME)
