/*
** EPITECH PROJECT, 2024
** myRadar.c
** File description:
** myRadar
*/

#include "include/my_radar.h"
#include "include/my.h"
#include <SFML/Graphics.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

norm_t *get_norm(int vdx, int vdy)
{
    norm_t *norms = malloc(sizeof(norm_t));
    float lenght = sqrt(pow(vdx, 2) + pow(vdy, 2));

    norms->x = vdx / lenght;
    norms->y = vdy / lenght;
    return norms;
}

static void movement(info_plane_t **p_info, int i, int seconds)
{
    sfVector2f pos = sfSprite_getPosition(p_info[i]->sprite);
    float vdx = p_info[i]->finish_x - pos.x;
    float vdy = p_info[i]->finish_y - pos.y;
    float vnx = (get_norm(vdx, vdy)->x) * (p_info[i]->speed / 35);
    float vny = (get_norm(vdx, vdy)->y) * (p_info[i]->speed / 35);
    double distance = sqrt(pow(vdx, 2) + pow(vdy, 2));

    if (p_info[i]->delay <= seconds &&
    (pos.x != p_info[i]->finish_x && pos.y != p_info[i]->finish_y)) {
        sfSprite_move(p_info[i]->sprite, (sfVector2f){vnx, vny});
        sfRectangleShape_move(p_info[i]->hitbox, (sfVector2f){vnx, vny});
    }
    if (distance < (p_info[i]->speed / 35)) {
        sfSprite_setPosition(p_info[i]->sprite,
            (sfVector2f){p_info[i]->finish_x, p_info[i]->finish_y});
        p_info[i]->arrived = 1;
    }
    if (pos.x == p_info[i]->finish_x && pos.y == p_info[i]->finish_y)
        p_info[i]->arrived = 1;
}

static int move_planes(sfRenderWindow *window, info_entities_t *infos,
    int seconds)
{
    int i = 0;
    int nb_p_arrived = 0;
    sfVector2f pos;

    while (i < infos->nb_planes) {
        if (infos->p_info[i]->sprite == NULL) {
            continue;
        }
        if (infos->p_info[i]->arrived == 1) {
            sfSprite_destroy(infos->p_info[i]->sprite);
            nb_p_arrived++;
        } else
            movement(infos->p_info, i, seconds);
        if (nb_p_arrived == infos->nb_planes)
            return 1;
        i++;
    }
    return 0;
}

void delay_display(sfRenderWindow *window, info_plane_t **p_info, int seconds,
    int i)
{
    if (p_info[i]->delay <= seconds) {
        sfRenderWindow_drawSprite(window, p_info[i]->sprite, NULL);
        sfRenderWindow_drawRectangleShape(window, p_info[i]->hitbox, NULL);
    }
}

void display_hitboxs_areas(sfRenderWindow *window, info_plane_t **p_info,
    int i, int display)
{
    if (display == 1)
        sfRenderWindow_drawRectangleShape(window, p_info[i]->hitbox, NULL);
}

static void display_sprites(sfRenderWindow *window, info_entities_t *infos,
    int seconds, int display)
{
    sfTexture *bg_t = sfTexture_createFromFile("src/textures/map.jpg", NULL);
    sfSprite *background = sfSprite_create();

    sfSprite_setTexture(background, bg_t, sfTrue);
    sfSprite_setPosition(background, (sfVector2f){0, 0});
    sfRenderWindow_drawSprite(window, background, NULL);
    for (int i = 0; infos->p_info[i] != NULL; i++) {
        if (infos->p_info[i] != NULL && infos->p_info[i]->arrived == 0 &&
        infos->p_info[i]->delay <= seconds) {
            sfRenderWindow_drawSprite(window, infos->p_info[i]->sprite, NULL);
            display_hitboxs_areas(window, infos->p_info, i, display);
        }
    }
    for (int j = 0; infos->t_info[j] != NULL; j++) {
        if (infos->t_info[j] != NULL) {
            sfRenderWindow_drawSprite(window, infos->t_info[j]->sprite, NULL);
            sfRenderWindow_drawCircleShape(window, infos->t_info[j]->circle,
                NULL);
        }
    }
}

static void print_time(int first)
{
    sfClock *clock;
    sfTime time;

    if (first == 1) {
        clock = sfClock_create();
        first = 0;
    }
    time = sfClock_getElapsedTime(clock);
    my_printf("time: %f\n", sfTime_asSeconds(time));
}

int run(sfRenderWindow *window, info_entities_t *infos,
    sfClock *clock, int display)
{
    sfEvent event;
    sfTime time;
    int seconds = 0;
    int finish = 0;

    sfRenderWindow_setFramerateLimit(window, 30);
    display = manage_event(window, event, display);
    time = sfClock_getElapsedTime(clock);
    seconds = (int)sfTime_asSeconds(time);
    sfRenderWindow_clear(window, sfBlack);
    finish = move_planes(window, infos, seconds);
    display_sprites(window, infos, seconds, display);
    sfRenderWindow_display(window);
    if (finish == 1)
        return 1;
}

static void csfml(char ***all_values, info_entities_t *infos)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    sfTexture *texture;
    sfIntRect rect;
    int collision = 0;
    int nb_towers = count_towers(infos->t_info);
    int finish = 0;
    int display = 1;
    sfClock *clock;

    create_planes(infos->p_info);
    create_towers(infos->t_info);
    clock = sfClock_create();
    window = sfRenderWindow_create(mode, "My Radar", sfResize | sfClose, NULL);
    while (sfRenderWindow_isOpen(window)) {
        finish = run(window, infos, clock, display);
        if (finish == 1)
            break;
    }
    sfRenderWindow_destroy(window);
}

int main(int argc, char **argv)
{
    char **lines;
    char ***all_values;
    int i = 0;
    int error = 0;
    info_plane_t **p_info;
    info_tower_t **t_info;
    info_entities_t *infos;

    error = check_error(argc, argv);
    if (error == 84)
        return 84;
    if (error == 1)
        return 0;
    lines = parsing(argv[1]);
    all_values = get_all_values(lines);
    infos = filling_infos(all_values, lines);
    csfml(all_values, infos);
    free(infos->p_info);
    free(infos->t_info);
    return 0;
}
