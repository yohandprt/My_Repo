/*
** EPITECH PROJECT, 2024
** my_sort_int_array.c
** File description:
** my_sort_int_array
*/

#include "my.h"

int compa(int *tab, int j, int mini)
{
    if (tab[j] < tab[mini])
        mini = j;
    return mini;
}

void my_sort_int_array(int *tab, int size)
{
    int i;
    int j;
    int mini;
    int temp;

    for (i = 0; i < size - 1; i++) {
        mini = i;
        for (j = i + 1; j < size; j++) {
            mini = compa(tab, j, mini);
        }
        temp = tab[i];
        tab[i] = tab[mini];
        tab[mini] = temp;
    }
}
