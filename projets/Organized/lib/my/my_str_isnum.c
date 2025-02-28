/*
** EPITECH PROJECT, 2024
** my_str_isnum.c
** File description:
** my_str_isnum
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    int i = 0;

    if (my_strlen(str) == 0)
        return 1;
    while (i <= my_strlen(str)) {
        if (str[i] >= 48 && str[i] <= 57 || str[i] == '\0')
            i++;
        else
            return 0;
    }
    return 1;
}
