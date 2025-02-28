##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## build and clear do_op
##

all: build clean

build:
		make -C lib/my/
		gcc -o my_ls my_ls.c -I./include -L. -lmy
clean:
		make clean -C lib/my/

fclean: clean
		rm -f a.out
		make fclean -C lib/my/

re: fclean all
