/*
** EPITECH PROJECT, 2025
** test_secured.c
** File description:
** test_secured
*/

#include <criterion/criterion.h>
#include "../include/hashtable.h"
#include <stdio.h>

Test(ht_insert, test_insert)
{
    hashtable_t *ht = new_hashtable(&hash, 4);
    char *key1 = "key1";
    char *value1 = "value1";

    ht_insert(ht, key1, value1);
    cr_assert_eq(ht->hashtable[0]->key, key1);
    cr_assert_eq(ht->hashtable[0]->value, value1);
}

Test(ht_delete, test_delete)
{
    hashtable_t *ht = new_hashtable(&hash, 4);
    char *key1 = "key1";
    char *value1 = "value1";
    char *key2 = "key2";
    char *value2 = "value2";

    ht_insert(ht, key1, value1);
    ht_insert(ht, key2, value2);
    ht_delete(ht, key1);
    cr_assert_eq(ht->hashtable[0]->null, 1);
}

Test(ht_search, test_search)
{
    hashtable_t *ht = new_hashtable(&hash, 4);
    char *key1 = "key1";
    char *value1 = "value1";

    ht_insert(ht, key1, value1);
    cr_assert_eq(ht_search(ht, key1), value1);
}

Test(hash, test_hash)
{
    char *key1 = "key1";
    int len = 4;
    int hash_value = hash(key1, len);
    int ind = hash_value % len;

    cr_assert(hash_value > 0);
    cr_assert(ind >= 0);
    cr_assert(ind < len);
}
