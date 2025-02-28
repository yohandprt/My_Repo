##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## build and clear do_op
##

SRC = 	cases/case_e.c \
	cases/case_fi.c \
	cases/case_g.c \
	cases/case_ou.c \
	cases/case_p.c \
	cases/case_pourcent.c \
	cases/case_sd.c \
	cases/case_x.c \
	cases/case_l.c \
	cases/case_minus.c \
	cases/case_plus.c \
	cases/case_zero.c \

all: build clean

build:
		make -C lib/my/
		gcc -o my_printf my_printf.c -I. -L. -lmy
clean:
		make clean -C lib/my/

fclean: clean
		rm -f a.out
		make fclean -C lib/my/

re: fclean all
