/*
** EPITECH PROJECT, 2024
** my_getnbr.c
** File description:
** my_getnbr
*/

#include <stdio.h>
#include <limits.h>

int negatif(char c, int sign_before)
{
    if (sign_before == 1)
        return 1;
    if (c == '-')
        return 1;
    return 0;
}

int my_getnbr(char const *str)
{
    int nb = 0;
    int find_nbr = 0;
    int sign = 0;
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 48 && str[i] <= 57) {
            len++;
            sign = negatif(str[i - 1], sign);
            find_nbr = 1;
            if (nb > (INT_MAX - (str[i] - '0')) / 10)
                return 0;
            if (nb < (INT_MIN + (str[i] - '0')) / 10)
                return 0;
            nb *= 10;
            nb += (str[i] - '0');
        }
        if ((str[i] < 48 || str[i] > 57) && find_nbr == 1) {
            break;
        }
    }
    if (sign == 1)
        return -nb;
    else
        return nb;
}
