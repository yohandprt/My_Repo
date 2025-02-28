/*
** EPITECH PROJECT, 2024
** my_sort_str_array.c
** File description:
** my_sort_str_array
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

void replace(char **array, int mini, int i, int j)
{
    char *temp;

    if (mini > 0) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void my_sort_str_array(char **array)
{
    char *temp;
    int mini;
    char first_mini;
    char first_j;
    int j;

    for (int i = 0; array[i] != NULL; i++) {
        mini = i;
        for (j = i + 1; array[j] != NULL; j++) {
            mini = my_strcmp(array[i], array[j]);
            replace(array, mini, i, j);
        }
    }
}
