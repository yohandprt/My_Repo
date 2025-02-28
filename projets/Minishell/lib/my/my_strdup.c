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
    int i = 0;

    if (src == NULL)
        return NULL;
    nv = malloc(sizeof(char) * (my_strlen(src) + 1));
    for (; src[i] != '\0'; i++)
        nv[i] = src[i];
    nv[i] = '\0';
    return nv;
}
