/*
** EPITECH PROJECT, 2024
** myRadar.c
** File description:
** myRadar
*/

#ifndef _MY_RADAR_H_
    #define _MY_RADAR_H_
    #include <SFML/Graphics.h>

typedef struct norm_s {
    float x;
    float y;
} norm_t;

typedef struct info_plane_s {
    char type;
    int start_x;
    int start_y;
    int finish_x;
    int finish_y;
    int speed;
    int delay;
    int arrived;
    sfTexture *texture;
    sfSprite *sprite;
    sfRectangleShape *hitbox;
} info_plane_t;

typedef struct info_tower_s {
    char type;
    int x;
    int y;
    int radius;
    sfTexture *texture;
    sfSprite *sprite;
    sfCircleShape *circle;
} info_tower_t;

typedef struct info_entities_s {
    info_plane_t **p_info;
    info_tower_t **t_info;
    int nb_planes;
    int nb_towers;
} info_entities_t;

typedef struct circles_s {
    sfCircleShape *circle;
    struct circles_s *next;
} circles_t;
info_tower_t *info_tower(char **line);
info_plane_t *info_plane(char **line);
info_entities_t *filling_info_entities(info_plane_t **p_info,
    info_tower_t **t_info, int nb_p, int nb_t);
info_entities_t *filling_infos(char ***all_values, char **lines);
char **parsing(char *file);
char ***get_all_values(char **lines);
sfCircleShape *create_circle(sfVector2f position,
    float radius);
int count_towers(info_tower_t **t_info);
int count_planes(info_plane_t **p_info);
void create_planes(info_plane_t **p_info);
void create_towers(info_tower_t **t_info);
int check_error(int argc, char **argv);
int manage_event(sfRenderWindow *window, sfEvent event, int display);
#endif
