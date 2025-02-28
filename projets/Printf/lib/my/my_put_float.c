/*
** EPITECH PROJECT, 2024
** my_put_float.c
** File description:
** my_put_float
*/

#include "my.h"

int my_put_float(double nb, int precision)
{
    int nb_int = (int)nb;
    double decimal = nb - nb_int;
    int i = 0;
    int new_nb = 0;

    my_putnbr(nb_int);
    if (precision > 0)
        my_putchar('.');
    for (i = 0; i < precision; i++) {
        decimal *= 10;
        new_nb = (int)decimal;
        my_putnbr(new_nb);
        decimal -= new_nb;
    }
    return 0;
}
