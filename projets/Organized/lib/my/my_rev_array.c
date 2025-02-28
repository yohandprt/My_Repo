/*
** EPITECH PROJECT, 2024
** my_rev_array.c
** File description:
** my_rev_array
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int len_array(char **array)
{
    int i = 0;

    while (array[i] != NULL)
        i++;
    return i;
}

void fill_array(char **array, char **temp)
{
    for (int i = 0; temp[i] != NULL; i++)
        array[i] = temp[i];
}

void my_rev_array(char **array)
{
    int len = len_array(array);
    char **temp = malloc(sizeof(char *) * (len + 1));
    int i = 0;

    for (i = 0; array[i] != NULL; i++) {
        temp[len - i - 1] = array[i];
    }
    temp[i] = NULL;
    fill_array(array, temp);
}
