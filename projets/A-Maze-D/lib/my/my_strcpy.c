/*
** EPITECH PROJECT, 2024
** task01
** File description:
** task01
*/

#include "../../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
