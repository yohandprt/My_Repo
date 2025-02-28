/*
** EPITECH PROJECT, 2024
** my_strcmp.c
** File description:
** my_strcmp
*/

#include "my.h"

int comp(int len_s1, int len_s2)
{
    if (len_s1 > len_s2)
        return 1;
    if (len_s1 < len_s2)
        return -1;
    return 0;
}

int my_strcmp(char const *s1, char const *s2)
{
    int len_s1 = my_strlen(s1);
    int len_s2 = my_strlen(s2);
    int len_min = 0;

    if (len_s1 < len_s2)
        len_min = len_s1;
    else if (len_s1 > len_s2)
        len_min = len_s2;
    else
        len_min = len_s2;
    for (int i = 0; i < len_min; i++) {
        if (my_charlowcase(s1[i]) > my_charlowcase(s2[i]))
            return 1;
        if (my_charlowcase(s1[i]) < my_charlowcase(s2[i]))
            return -1;
    }
    return comp(len_s1, len_s2);
}
