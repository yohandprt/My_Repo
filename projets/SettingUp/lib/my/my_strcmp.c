/*
** EPITECH PROJECT, 2024
** my_strcmp.c
** File description:
** my_strcmp
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int len_s1 = my_strlen(s1);
    int len_s2 = my_strlen(s2);

    if (len_s1 > len_s2)
        return 1;
    if (len_s1 < len_s2)
        return -1;
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
    }
    return 0;
}
