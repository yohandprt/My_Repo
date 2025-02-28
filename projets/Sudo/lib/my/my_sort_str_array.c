/*
** EPITECH PROJECT, 2024
** my_sort_str_array.c
** File description:
** my_sort_str_array
*/

#include "my.h"
#include <stdlib.h>

char first_letter_mini(char **array, int mini)
{
    char first_mini;

    if (array[mini][0] == '.')
        first_mini = array[mini][1];
    else
        first_mini = array[mini][0];
    return first_mini;
}

char first_letter_j(char **array, int j)
{
    char first_j;

    if (array[j][0] == '.')
        first_j = array[j][1];
    else
        first_j = array[j][0];
    return first_j;
}

int comp(char first_mini, char first_j, int mini, int j)
{
    if (first_j < first_mini)
        mini = j;
    return mini;
}

void my_sort_str_array(char **array)
{
    char *temp;
    int mini;
    char first_mini;
    char first_j;

    for (int i = 0; array[i] != NULL; i++) {
        mini = i;
        for (int j = i + 1; array[j] != NULL; j++) {
            first_mini = first_letter_mini(array, mini);
            first_j = first_letter_j(array, j);
            mini = comp(first_mini, first_j, mini, j);
        }
        if (mini != i) {
            temp = array[i];
            array[i] = array[mini];
            array[mini] = temp;
        }
    }
}
