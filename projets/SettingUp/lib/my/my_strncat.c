/*
** EPITECH PROJECT, 2024
** my_strncat.c
** File description:
** my_strncat
*/

#include "my.h"
#include <stdlib.h>

char *my_strncat(char *dest, char const *src, int nb)
{
    int maxi = my_strlen(dest) + my_strlen(src);
    char *str = malloc(maxi * sizeof(char) + 1);
    int i;
    int j;

    for (i = 0; i < my_strlen(dest); i++)
        str[i] = dest[i];
    for (j = 0; j < nb; j++) {
        str[i] = src[j];
        i++;
    }
    str[i] = '\0';
    return str;
}
