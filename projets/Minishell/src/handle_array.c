/*
** EPITECH PROJECT, 2025
** handle_array.c
** File description:
** handle_array
*/

#include "../include/mysh.h"

int check_line(char *line, char *src)
{
    if (my_strlen(line) < my_strlen(src))
        return 0;
    for (int i = 0; src[i] != '\0'; i++) {
        if (line[i] != src[i])
            return 0;
    }
    return 1;
}

int get_index(char **array, char *src)
{
    if (array == NULL)
        return -1;
    for (int i = 0; array[i]; i++) {
        if (check_line(array[i], src))
            return i;
    }
    return -1;
}

char **cp_array(char **array)
{
    int len = my_arraylen(array);
    char **new_array = malloc(sizeof(char *) * (len + 1));
    int i = 0;

    if (new_array == NULL)
        return NULL;
    for (; i < len; i++)
        new_array[i] = my_strdup(array[i]);
    new_array[i] = NULL;
    return new_array;
}

void free_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}
