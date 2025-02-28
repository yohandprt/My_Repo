/*
** EPITECH PROJECT, 2024
** my_str_isalpha.c
** File description:
** my_str_isalpha
*/

#include "my.h"
#include "isalpha.h"

int my_str_isalpha(char const *str)
{
    int i = 0;

    if (my_strlen(str) == 0)
        return 1;
    while (i <= my_strlen(str)) {
        if (ISALPHA(str[i]) || str[i] == '\0')
            i++;
        else
            return 0;
    }
    return 1;
}
