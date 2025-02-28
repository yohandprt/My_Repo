/*
** EPITECH PROJECT, 2024
** my_getnbr.c
** File description:
** my_getnbr
*/

#include "my.h"

void verif_neg(char const *str, int i)
{
    if (str[i] == '-' && str[(i + 1)] >= 48 && str[(i + 1)] <= 57)
        my_putchar('-');
}

int my_getnbr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        verif_neg(str, i);
        if (str[i] >= 48 && str[i] <= 57)
            my_putchar(str[i]);
        i++;
    }
}
