/*
** EPITECH PROJECT, 2024
** setting_up.c
** File description:
** setting_up
*/

#include "include/my.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

static char **alloc_map(char **map, int lines, int columns)
{
    int i;

    map = malloc(sizeof(char *) * (lines + 1));
    for (i = 0; i < lines + 1; i++)
        map[i] = malloc(sizeof(char) * (columns + 1));
    map[i] = NULL;
    return map;
}

static struct info_square *replace_info_square(struct info_square *max_square,
    int side_size, int i, int j)
{
    if (side_size > max_square->side_size) {
        max_square->side_size = side_size;
        max_square->start_i = i;
        max_square->start_j = j;
    }
    return max_square;
}

static struct info_square *in_algo(char **map, int i, int j)
{
    int side_size;
    struct info_square *max_square = malloc(sizeof(int) * 3 + 1);

    max_square->start_i = 0;
    max_square->start_j = 0;
    max_square->side_size = 0;
    if (map[i][j] == '.') {
        side_size = 1;
        while (check_square(map, i, j, side_size) == 0 &&
        (i + side_size) <= my_arraylen(map) - 1 &&
        (j + side_size) <= my_strlen(map[0]) - 1) {
            max_square = replace_info_square(max_square, side_size, i, j);
            side_size++;
        }
    }
    return max_square;
}

static struct info_square *test_bigger(struct info_square *temp,
    struct info_square *max_square)
{
    if (temp->side_size > max_square->side_size)
        max_square = temp;
    return max_square;
}

struct info_square *algo(char **map, int lines, int columns)
{
    int max_i = 0;
    int max_j = 0;
    int max_side_size = 0;
    struct info_square *max_square = malloc(sizeof(int) * 3 + 1);
    struct info_square *temp = malloc(sizeof(int) * 3 + 1);
    int side_size;

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            temp = in_algo(map, i, j);
            max_square = test_bigger(temp, max_square);
        }
    }
    return max_square;
}

void replace_and_display(char **map, struct info_square *max_square,
    int lines, int columns)
{
    replace(map, max_square->start_i, max_square->start_j,
    max_square->side_size);
    display(map, lines, columns);
}

void running_algo_replace_display(char **map, struct info_square *max_square,
    int lines, int columns)
{
    max_square = algo(map, lines, columns);
    replace_and_display(map, max_square, lines, columns);
}

void setting_up(char *str_map, int size)
{
    char **map;
    int lines = count_lines(str_map);
    int number_size = count_columns(str_map, 0);
    int columns = count_columns(str_map, number_size + 1) - 1;
    int j = 0;
    struct info_square *max_square;

    if (str_map[my_strlen(str_map) - 1] != '\n')
        lines++;
    map = alloc_map(map, lines, columns);
    str_map += number_size + 1;
    for (int i = 0; *str_map != '\0'; i++) {
        for (j = 0; *str_map != '\n' && *str_map != '\0'; j++) {
            if (*str_map == '\n')
                str_map++;
            map[i][j] = *str_map;
            str_map++;
        }
        map[i][j] = '\0';
        if (*str_map == '\n')
            str_map++;
    }
    running_algo_replace_display(map, max_square, lines, columns);
    free(map);
}


void setting_(char *str_map, int size)
{
    char **map;
    int lines = count_lines(str_map);
    int number_size = count_columns(str_map, 0);
    int columns = count_columns(str_map, number_size + 1) - 1;
    int j = 0;
    struct info_square *max_square;

    map = alloc_map(map, lines, columns);
    str_map += number_size + 1;
    for (int i = 0; *str_map != '\0'; i++) {
        for (j = 0; *str_map != '\n' && *str_map != '\0'; j++) {
            map[i][j] = *str_map;
            str_map++;
        }
        map[i][j] = '\0';
        if (*str_map == '\n')
            str_map++;
    }
    running_algo_replace_display(map, max_square, lines, columns);
    free(map);
}

int main(int argc, char **argv)
{
    int size = 10000;
    int fd;
    char *readding;
    int rd;

    if (argc != 2)
        return 84;
    fd = open(argv[1], O_RDONLY);
    readding = malloc((sizeof(char) * size) + 1);
    rd = read(fd, readding, size);
    readding[rd] = '\0';
    setting_up(readding, size);
    free(readding);
    return 0;
}
