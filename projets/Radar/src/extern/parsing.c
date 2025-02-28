/*
** EPITECH PROJECT, 2024
** parsing.c
** File description:
** parsing
*/

#include "../../include/my.h"
#include "../../include/my_radar.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char **parsing(char *file)
{
    struct stat st;
    int fd = 0;
    int rd = 0;
    int i = 0;
    char *readding;
    char **array;

    stat(file, &st);
    readding = malloc(st.st_size);
    fd = open(file, O_RDONLY);
    rd = read(fd, readding, st.st_size);
    array = malloc(sizeof(char *) * (my_strlen(readding) + 1));
    array = my_str_to_word_array(readding, '\n');
    free(readding);
    return array;
}

char ***get_all_values(char **lines)
{
    char ***all_values = malloc(sizeof(char **) * (my_arraylen(lines) + 1));
    int i = 0;

    for (int a = 0; lines[a] != NULL; a++)
        all_values[a] = malloc(sizeof(char *) * (my_strlen(lines[a]) + 1));
    while (lines[i] != NULL) {
        all_values[i] = my_str_to_word_array(lines[i], ' ');
        i++;
    }
    all_values[i] = NULL;
    return all_values;
}
