/*
** EPITECH PROJECT, 2025
** hashtable.c
** File description:
** hashtable
*/

#include "../../include/my.h"
#include "../../include/hashtable.h"
#include <stdio.h>
#include <stdlib.h>

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ht = malloc(sizeof(hashtable_t) * len);

    ht->len = len;
    ht->hash = hash;
    ht->hashtable = malloc(sizeof(hashtable_list_t) * (len + 1));
    for (int i = 0; i < len; i++) {
        ht->hashtable[i] = malloc(sizeof(hashtable_list_t));
        ht->hashtable[i]->null = 1;
    }
    return ht;
}

void delete_hashtable(hashtable_t *ht)
{
    for (int i = 0; ht->hashtable[i] != NULL; i++)
        free(ht->hashtable[i]);
    free(ht->hashtable);
    free(ht);
}
