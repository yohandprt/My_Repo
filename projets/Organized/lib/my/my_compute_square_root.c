/*
** EPITECH PROJECT, 2024
** my_compute_square_root.c
** File description:
** my_compute_square_root
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    if (nb == 1)
        return 1;
    for (int i = 0; i < nb; i++){
        if (i * i == nb)
            return i;
    }
    return 0;
}
