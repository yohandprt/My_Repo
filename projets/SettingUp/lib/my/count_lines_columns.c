/*
** EPITECH PROJECT, 2024
** count_lines_columns.c
** File description:
** count_lines_columns
*/

#include "my.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int count_lines(char *str_map)
{
    int lines = 0;

    for (int i = 0; str_map[i] != '\0'; i++) {
        if (str_map[i] == '\n' || str_map[i] == '\0')
            lines++;
    }
    return lines;
}

int count_columns(char *str_map, int nb)
{
    int columns = 0;

    for (int i = nb; str_map[i] != '\0'; i++) {
        if (str_map[i] == '\n')
            break;
        columns++;
    }
    return columns;
}
