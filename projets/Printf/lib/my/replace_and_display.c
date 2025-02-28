/*
** EPITECH PROJECT, 2024
** replace_and_display.c
** File description:
** replace_and_display
*/

#include "my.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void display(char **map, int lines, int columns)
{
    for (int i = 0; i < lines - 1; i++) {
        for (int j = 0; j < columns; j++)
            my_putchar(map[i][j]);
        my_putchar('\n');
    }
}

void replace(char **map, int start_i, int start_j, int side_size)
{
    for (int i = start_i; i < start_i + side_size; i++) {
        for (int j = start_j; j < start_j + side_size; j++) {
            map[i][j] = 'x';
        }
    }
}
