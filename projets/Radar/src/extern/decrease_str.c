/*
** EPITECH PROJECT, 2024
** decrease_str.c
** File description:
** decrease_str
*/

#include <stdlib.h>
#include "../../include/my.h"

char *decrease_str(char *str, int n)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) - n + 1));
    int i = 0;
    int j = 0;

    if (n > my_strlen(str)) {
        my_putstr("Error: variable n larger than size of str\n");
        return str;
    }
    while (str[i] != '\0') {
        if (i > n) {
            new_str[j] = str[i];
            j++;
        }
        i++;
    }
    new_str[j] = '\0';
    return new_str;
}
