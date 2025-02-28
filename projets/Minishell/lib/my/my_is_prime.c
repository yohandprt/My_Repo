/*
** EPITECH PROJECT, 2024
** my_is_prime.c
** File description:
** my_is_prime
*/

#include "my.h"

int divi(int nb, int divisible)
{
    for (int i = 1; i <= nb; i++){
        if (nb % i == 0)
            divisible++;
    }
}

int my_is_prime(int nb)
{
    int divisible = 0;

    if (nb <= 1 || nb % 2 == 0 && nb != 2)
        return 0;
    else {
        divi(nb, divisible);
    }
    return divisible == 2;
}
