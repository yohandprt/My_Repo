/*
** EPITECH PROJECT, 2024
** myRadar.c
** File description:
** myRadar
*/

#include "../../include/my_radar.h"
#include "../../include/my.h"
#include <SFML/Graphics.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count_towers(info_tower_t **t_info)
{
    int count = 0;

    while (t_info[count] != NULL)
        count++;
    return count;
}

int count_planes(info_plane_t **p_info)
{
    int count = 0;

    while (p_info[count] != NULL)
        count++;
    return count;
}
