/*
** EPITECH PROJECT, 2024
** my_str_to_int.c
** File description:
** my_str_to_int
*/

#include "my.h"

int my_str_to_int(char const *str)
{
    int nb = str[0] - '0';
    int i = 1;

    while (str[i] != '\0') {
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
    return nb;
}
