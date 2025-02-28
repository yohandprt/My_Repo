/*
** EPITECH PROJECT, 2025
** hash.c
** File description:
** hash
*/

#include "../../include/my.h"
#include "../../include/hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int hash(char *key, int len)
{
    int hash = 1;
    int multi = 31;

    for (int i = 0; i < my_strlen(key); i++)
        hash += (key[i] * (i + 1)) * multi;
    return hash;
}
