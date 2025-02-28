/*
** EPITECH PROJECT, 2024
** my_strcat.c
** File description:
** my_strcat
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int maxi = my_strlen(dest) + my_strlen(src);
    char *str = malloc(maxi * sizeof(char));
    int i;
    int j;

    for (i = 0; i < my_strlen(dest); i++)
        str[i] = dest[i];
    for (j = 0; j < my_strlen(src); j++) {
        str[i] = src[j];
        i++;
    }
    str[i] = '\0';
    return str;
}
