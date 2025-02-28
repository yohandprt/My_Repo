/*
** EPITECH PROJECT, 2024
** my_strswap.c
** File description:
** my_strswap
*/

#include "my.h"

void my_strswap(char **a, char **b)
{
    char *temp = *a;

    *a = *b;
    *b = temp;
}
