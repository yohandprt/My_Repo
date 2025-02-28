/*
** EPITECH PROJECT, 2025
** my_puterr.c
** File description:
** my_puterr
*/

#include <unistd.h>

int my_puterr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        write(2, &(str[i]), 1);
        i = i + 1;
    }
    return i;
}
