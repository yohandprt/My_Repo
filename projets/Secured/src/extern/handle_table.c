/*
** EPITECH PROJECT, 2025
** handle_table.c
** File description:
** handle_table
*/

#include "../../include/my.h"
#include "../../include/hashtable.h"
#include <stdio.h>
#include <stdlib.h>

static void display_ht(hashtable_t *ht, int i, int j)
{
    if (ht->hashtable[j]->null == 0 && ht->hashtable[j]->ind == i)
        my_printf("> %d - %s\n", ht->hashtable[j]->hash,
            ht->hashtable[j]->value);
}

void ht_dump(hashtable_t *ht)
{
    if (ht == NULL) {
        write(2, "Error: Hashtable is NULL\n", 26);
        return;
    }
    for (int i = 0; i < ht->len; i++) {
        my_printf("[%d]:\n", i);
        for (int j = 0; j < ht->len; j++)
            display_ht(ht, i, j);
    }
}

static unsigned int int_to_unsigned(int nb)
{
    if (nb < 0)
        nb = -nb;
    return (unsigned int)nb;
}

static int insert_error(hashtable_t *ht, char *key)
{
    for (int i = 0; i < ht->len; i++) {
        if (ht->hashtable[i]->key == key) {
            write(2, "Error: Key already exist\n", 26);
            return 84;
        }
    }
    return 0;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    unsigned int hash = int_to_unsigned(ht->hash(key, ht->len));
    int ind = hash % ht->len;

    if (insert_error(ht, key) == 84)
        return 84;
    for (int i = 0; i < ht->len; i++) {
        if (ht->hashtable[i]->null == 1) {
            ht->hashtable[i]->key = key;
            ht->hashtable[i]->value = value;
            ht->hashtable[i]->hash = int_to_unsigned(ht->hash(key, ht->len));
            ht->hashtable[i]->ind = ind;
            ht->hashtable[i]->null = 0;
            break;
        }
    }
    return 0;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int find = 0;

    for (int i = 0; i < ht->len; i++) {
        if (ht->hashtable[i]->key == key) {
            ht->hashtable[i]->null = 1;
            find = 1;
        }
    }
    if (find == 0) {
        write(2, "Error: Key not found\n", 21);
        return 84;
    }
    return 0;
}

char *ht_search(hashtable_t *ht, char *key)
{
    int i = 0;

    while (i < ht->len) {
        if (ht->hashtable[i]->key == key)
            break;
        i++;
    }
    if (i < ht->len && ht->hashtable[i]->null == 0)
        return ht->hashtable[i]->value;
    write(2, "Error: Key not found\n", 21);
    return NULL;
}
