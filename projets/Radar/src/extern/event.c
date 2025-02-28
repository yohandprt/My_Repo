/*
** EPITECH PROJECT, 2025
** event.c
** File description:
** event
*/

#include "../../include/my.h"
#include "../../include/my_radar.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>

int key_pressed_l(sfEvent event)
{
    int pressed = 0;

    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyL)
            pressed = 1;
    }
    if (pressed == 1 && event.type == sfEvtKeyReleased)
        return 1;
    return 0;
}

int manage_event(sfRenderWindow *window, sfEvent event, int display)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (key_pressed_l(event) == 1 && display == 1) {
            display = 0;
        }
        if (key_pressed_l(event) == 1 && display == 0)
            display = 1;
    }
    return display;
}
