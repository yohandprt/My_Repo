/*
** EPITECH PROJECT, 2024
** my_str_isprintable.c
** File description:
** my_str_isprintable
*/

#include "my.h"
#include "isprintable.h"

int my_str_isprintable(char const *str)
{
    int i = 0;

    if (my_strlen(str) == 0)
        return 1;
    while (i <= my_strlen(str)) {
        if (ISPRINTABLE(str[i]))
            i++;
        else
            return 0;
    }
    return 1;
}
