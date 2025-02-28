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

void create_planes(info_plane_t **p_info)
{
    int i = 0;
    int nb_planes = count_planes(p_info);
    sfIntRect textureRect;

    while (p_info[i] != NULL) {
        sfSprite_setTexture(p_info[i]->sprite, p_info[i]->texture, sfTrue);
        textureRect = sfSprite_getTextureRect(p_info[i]->sprite);
        sfSprite_setScale(p_info[i]->sprite, (sfVector2f){0.07, 0.07});
        sfSprite_setOrigin(p_info[i]->sprite,
            (sfVector2f){textureRect.width / 2, textureRect.height / 2});
        sfSprite_setPosition(p_info[i]->sprite,
            (sfVector2f){p_info[i]->start_x, p_info[i]->start_y});
        i++;
    }
}

void create_towers(info_tower_t **t_info)
{
    int i = 0;
    int nb_towers = count_towers(t_info);
    sfIntRect textureRect;

    while (t_info[i] != NULL) {
        sfSprite_setTexture(t_info[i]->sprite, t_info[i]->texture, sfTrue);
        textureRect = sfSprite_getTextureRect(t_info[i]->sprite);
        sfSprite_setScale(t_info[i]->sprite, (sfVector2f){0.1, 0.1});
        sfSprite_setOrigin(t_info[i]->sprite,
            (sfVector2f){textureRect.width / 2, textureRect.height / 2});
        sfSprite_setPosition(t_info[i]->sprite,
            (sfVector2f){t_info[i]->x, t_info[i]->y});
        i++;
    }
}
