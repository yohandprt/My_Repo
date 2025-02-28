/*
** EPITECH PROJECT, 2024
** organized.c
** File description:
** organized
*/

#include "../../include/bootstrap.h"
#include "../../include/shell.h"
#include "../../include/my.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../include/organized.h"

void last_del(list_arg_t *cp, list_arg_t *prev, list_arg_t **base,
    int to_delete)
{
    if (cp->id == to_delete) {
        if (prev != NULL) {
            my_printf("%s n°%d - %s deleted\n", cp->type, cp->id, cp->name);
            prev->next = NULL;
        }
        if (prev == NULL) {
            my_printf("%s n°%d - %s deleted\n", cp->type, cp->id, cp->name);
            *base = NULL;
        }
    }
}

void del_middle_arg(list_arg_t **base, list_arg_t *copy,
    list_arg_t *prev, int to_delete)
{
    if (copy->id == to_delete && prev != NULL) {
        my_printf("%s n°%d - %s deleted\n", copy->type, copy->id, copy->name);
        prev->next = copy->next;
        copy->next->prev = prev;
    }
}
