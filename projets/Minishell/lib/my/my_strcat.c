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
    int len_dest = my_strlen(dest);
    int len_src = my_strlen(src);
    char *str = malloc((len_dest + len_src + 1) * sizeof(char));
    int i;
    int j;

    if (str == NULL)
        return NULL;
    if (dest == NULL || src == NULL)
        return NULL;
    for (i = 0; i < len_dest; i++)
        str[i] = dest[i];
    for (j = 0; j < len_src; j++) {
        str[i] = src[j];
        i++;
    }
    str[i] = '\0';
    return str;
}
