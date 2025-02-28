/*
** EPITECH PROJECT, 2024
** my_charlowcase.c
** File description:
** my_charlowcase
*/

#include "my.h"

char my_charlowcase(char c)
{
    if (c >= 'A' && c <= 'Z')
        c += 32;
    return c;
}
