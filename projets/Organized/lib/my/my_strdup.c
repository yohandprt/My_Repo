/*
** EPITECH PROJECT, 2024
** my_strdup.c
** File description:
** my_strdup
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *nv = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;

    if (src == NULL)
        return NULL;
    while (src[i] != '\0') {
        nv[i] = src[i];
        i++;
    }
    nv[i] = '\0';
    return nv;
}
