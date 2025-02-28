/*
** EPITECH PROJECT, 2024
** organized.c
** File description:
** organized
*/

#include "../include/bootstrap.h"
#include "../include/shell.h"
#include <stdlib.h>

void delete(linked_list_t **begin, linked_list_t *prev, linked_list_t *now)
{
    if (prev == NULL)
        *begin = now->next;
    else {
        prev->next = now->next;
    }
}

void delete_in_list(linked_list_t **begin, void const *ref, int (*cmp_fct)())
{
    linked_list_t *now = *begin;
    linked_list_t *prev = NULL;

    if (now == NULL)
        return;
    while (now != NULL) {
        if (cmp_fct(now->data, ref) == 1) {
            delete(begin, prev, now);
            now = now->next;
        } else {
            prev = now;
            now = now->next;
        }
    }
    return;
}
