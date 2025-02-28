/*
** EPITECH PROJECT, 2025
** my_decstr.c
** File description:
** my_decstr
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

char *my_decstr(char *str, int left, int right)
{
    char *new_str = malloc(sizeof(char) * ((my_strlen(str) -
        left - right) + 1));
    int i = 0;
    int ind = 0;

    while (i < my_strlen(str)) {
        if (i > left - 1 && i < my_strlen(str) - right) {
            new_str[ind] = str[i];
            ind++;
        }
        i++;
    }
    new_str[ind] = '\0';
    return new_str;
}
