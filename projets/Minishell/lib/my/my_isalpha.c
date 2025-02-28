/*
** EPITECH PROJECT, 2024
** my_isalpha.c
** File description:
** my_isalpha
*/

#include "my.h"

int my_isalpha(char str)
{
    return 65 <= str && str <= 90 || 97 <= str && str <= 122;
}
