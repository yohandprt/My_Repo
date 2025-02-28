/*
** EPITECH PROJECT, 2024
** my_isdigit.c
** File description:
** my_isdigit
*/

#include "my.h"

int my_isdigit(char str)
{
    return 48 <= str && str <= 57;
}
