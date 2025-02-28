/*
** EPITECH PROJECT, 2024
** getting_infos.c
** File description:
** getting_infos
*/

#include "../../include/my.h"
#include "../../include/my_radar.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>

sfCircleShape *create_circle(sfVector2f position,
    float radius)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setOrigin(circle, (sfVector2f){radius, radius});
    sfCircleShape_setPosition(circle, position);
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineColor(circle, (sfColor){255, 255, 255, 255});
    sfCircleShape_setOutlineThickness(circle, 1.0);
    return circle;
}

static sfRectangleShape *create_hitbox(info_plane_t *plane)
{
    sfRectangleShape *hitbox = sfRectangleShape_create();
    sfVector2f position = (sfVector2f){plane->start_x - 10,
        plane->start_y - 10};
    sfVector2u size = sfTexture_getSize(plane->texture);
    sfVector2f origin_plane = sfSprite_getOrigin(plane->sprite);

    sfRectangleShape_setOrigin(hitbox, origin_plane);
    sfRectangleShape_setPosition(hitbox, position);
    sfRectangleShape_setSize(hitbox, (sfVector2f){20, 20});
    sfRectangleShape_setFillColor(hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(hitbox, (sfColor){255, 0, 0, 255});
    sfRectangleShape_setOutlineThickness(hitbox, 1.0);
    return hitbox;
}

info_tower_t *info_tower(char **line)
{
    info_tower_t *info = malloc(sizeof(info_tower_t));

    info->type = *(line[0]);
    info->x = my_str_to_int(line[1]);
    info->y = my_str_to_int(line[2]);
    info->radius = my_str_to_int(line[3]);
    info->texture = sfTexture_createFromFile("src/textures/tower.png", NULL);
    info->sprite = sfSprite_create();
    info->circle = create_circle((sfVector2f){info->x, info->y}, info->radius);
    return info;
}

info_plane_t *info_plane(char **line)
{
    info_plane_t *info = malloc(sizeof(info_plane_t));

    info->type = *(line[0]);
    info->start_x = my_str_to_int(line[1]);
    info->start_y = my_str_to_int(line[2]);
    info->finish_x = my_str_to_int(line[3]);
    info->finish_y = my_str_to_int(line[4]);
    info->speed = my_str_to_int(line[5]);
    info->delay = my_str_to_int(line[6]);
    info->arrived = 0;
    info->texture = sfTexture_createFromFile("src/textures/plane.png", NULL);
    info->sprite = sfSprite_create();
    info->hitbox = create_hitbox(info);
    return info;
}

info_entities_t *filling_info_entities(info_plane_t **p_info,
    info_tower_t **t_info, int nb_p, int nb_t)
{
    info_entities_t *infos = malloc(sizeof(info_entities_t));

    infos->p_info = p_info;
    infos->t_info = t_info;
    infos->nb_planes = nb_p;
    infos->nb_towers = nb_t;
    return infos;
}

info_entities_t *filling_infos(char ***all_values, char **lines)
{
    int ind_p = 0;
    int ind_t = 0;
    info_plane_t **p_inf = malloc(sizeof(info_plane_t *) * my_arraylen(lines));
    info_tower_t **t_inf = malloc(sizeof(info_tower_t *) * my_arraylen(lines));

    for (int i = 0; all_values[i] != NULL; i++) {
        if (*(all_values[i][0]) == 'A') {
            p_inf[ind_p] = info_plane(all_values[i]);
            ind_p++;
        }
        if (*(all_values[i][0]) == 'T') {
            t_inf[ind_t] = info_tower(all_values[i]);
            ind_t++;
        }
    }
    p_inf[ind_p] = NULL;
    t_inf[ind_t] = NULL;
    return filling_info_entities(p_inf, t_inf, ind_p, ind_t);
}
