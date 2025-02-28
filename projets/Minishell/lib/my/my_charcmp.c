/*
** EPITECH PROJECT, 2025
** my_charcmp.c
** File description:
** my_charcmp
*/

int my_charcmp(char a, char b)
{
    if (a == b)
        return 0;
    if (a > b)
        return 1;
    if (a < b)
        return -1;
}
