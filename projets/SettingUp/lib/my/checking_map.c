/*
** EPITECH PROJECT, 2024
** checking_map.c
** File description:
** checking_map
*/

#include "my.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int check_o(char **map, int side_size, int start_j, int i)
{
    int retour = 0;

    for (int j = start_j; j < start_j + side_size - 1; j++) {
        if (map[i][j] == 'o') {
            retour = 1;
        }
    }
    return retour;
}

int check_square(char **map, int start_i, int start_j, int side_size)
{
    int retour = 0;

    for (int i = start_i; i < start_i + side_size - 1; i++) {
        retour = check_o(map, side_size, start_j, i);
        if (retour == 1)
            break;
    }
    return retour;
}
