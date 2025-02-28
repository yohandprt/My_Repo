/*
** EPITECH PROJECT, 2024
** my_find_prime_sup.c
** File description:
** my_find_prime_sup
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int i = nb + 1;

    while (my_is_prime(i) == 0)
        i++;
    return i;
}
