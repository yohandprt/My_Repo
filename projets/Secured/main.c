/*
** EPITECH PROJECT, 2025
** secured.c
** File description:
** secured
*/

#include "include/my.h"
#include "include/hashtable.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    hashtable_t *ht = new_hashtable(&hash, 4);

    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "Kratos", "./Trash/Hollidays_Pics/.secret_folder/kratos.ai");
    ht_insert(ht, "<3", "+33 6 31 45 61 23 71");
    ht_insert(ht, "</3", "+33 7 84 62 48 21 35");
    ht_delete(ht, "Vision");
    ht_dump(ht);
    delete_hashtable(ht);
    return 0;
}
