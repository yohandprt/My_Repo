/*
** EPITECH PROJECT, 2024
** my_putnbr.c
** File description:
** my_putnbr
*/

#include "my.h"

int my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb > 9)
        my_putnbr(nb / 10);
    my_putchar((nb % 10) + '0');
}
