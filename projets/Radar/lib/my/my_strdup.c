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
    char *nv;
    int i;
    int size = my_strlen(src);

    if (src == NULL)
        return NULL;
    nv = malloc(size);
    for (i = 0; i < size; i++)
        nv[i] = src[i];
    nv[i] = '\0';
    return nv;
}
