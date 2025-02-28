/*
** EPITECH PROJECT, 2024
** my_str_isupper.c
** File description:
** my_str_isupper
*/

#include "my.h"

int my_str_isupper(char const *str)
{
    int i = 0;

    if (my_strlen(str) == 0)
        return 1;
    while (i <= my_strlen(str)) {
        if (str[i] >= 65 && str[i] <= 90 || str[i] == '\0')
            i++;
        else
            return 0;
    }
    return 1;
}
