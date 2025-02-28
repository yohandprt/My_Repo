/*
** EPITECH PROJECT, 2024
** my_strncmp.c
** File description:
** my_strncmp
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int len_s1 = my_strlen(s1);
    int len_s2 = my_strlen(s2);

    if (len_s1 < n)
        return -1;
    if (len_s2 < n)
        return 1;
    for (int i = 0; s1[i] != s1[n]; i++) {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
    }
    return 0;
}
