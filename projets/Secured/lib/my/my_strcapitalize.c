/*
** EPITECH PROJECT, 2024
** my_strcapitalize.c
** File description:
** my_strcapitalize
*/

#include "my.h"
#include <stdio.h>

void verif(char *str, int i)
{
    if (str[(i + 1)] >= 'a' && str[(i + 1)] <= 'z')
        str[(i + 1)] -= 32;
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ') {
            verif(str, i);
        }
        i++;
    }
    return str;
}
