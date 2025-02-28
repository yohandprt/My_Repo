##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC = deleted.c \

OBJ = $(SRC:.c=.o)

NAME = liborg.a

all: build

build:        $(OBJ)
	ar rc ../$(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)
