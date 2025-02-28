/*
** EPITECH PROJECT, 2024
** my_revstr.c
** File description:
** my_revstr
*/

#include "my.h"

char *my_revstr(char *str)
{
    int nb = my_strlen(str);
    char temp[nb];
    int i;

    for (i = 0; i != nb; i++)
        temp[nb - i - 1] = str[i];
    for (int j = 0; j < nb; j++)
        str[j] = temp[j];
    str[nb] = '\0';
    return str;
}
