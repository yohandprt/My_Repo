/*
** EPITECH PROJECT, 2024
** organized.c
** File description:
** organized
*/

#include "include/bootstrap.h"
#include "include/shell.h"
#include "include/my.h"
#include "include/organized.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int add(void *data, char **args)
{
    list_arg_t **base = (list_arg_t **)data;
    list_arg_t *new_arg = create_new_arg(args);
    list_arg_t *copy = *base;

    if (*base != NULL) {
        while (copy->next != NULL) {
            increment_id(copy, new_arg);
            copy = copy->next;
        }
        increment_id(copy, new_arg);
        new_arg->prev = copy;
        copy->next = new_arg;
        print_added(new_arg->type, new_arg->id, new_arg->name);
        return 0;
    } else
        *base = new_arg;
    print_added((*base)->type, (*base)->id, (*base)->name);
    return 0;
}

int del(void *data, char **args)
{
    list_arg_t **base = (list_arg_t **)data;
    list_arg_t *cp = *base;
    list_arg_t *prev = NULL;
    int to_delete = my_str_to_int(my_strdup(args[0]));

    while (cp->next != NULL) {
        if (cp->id == to_delete && prev == NULL) {
            my_printf("%s n°%d - %s deleted\n", cp->type, cp->id, cp->name);
            *base = cp->next;
            cp->next->prev = NULL;
        }
        del_middle_arg(base, cp, prev, to_delete);
        prev = cp;
        cp = cp->next;
    }
    last_del(cp, prev, base, to_delete);
    return 0;
}

int disp(void *data, char **args)
{
    list_arg_t *base = *(list_arg_t **)data;
    list_arg_t *copy = base;

    if (copy != NULL) {
        while (copy != NULL) {
            my_printf("%s n°%d - %s\n", copy->type, copy->id, copy->name);
            copy = copy->next;
        }
    }
    return 0;
}

int sort(void *data, char **args)
{
    list_arg_t *base = *(list_arg_t **)data;
    char *method = args[0];
    int size = get_list_size(base);
    sort_args_t *sort = malloc(sizeof(char **) * 2 + sizeof(int *) + 1);

    fill_tabs(base, sort, size);
    if (my_strcmp(method, "TYPE") == 0)
        sorting(&(sort->types), STRING, size);
    if (my_strcmp(method, "NAME") == 0)
        sorting(&(sort->names), STRING, size);
    if (my_strcmp(method, "ID") == 0)
        sorting(&(sort->ids), INTEGER, size);
    fill_result(base, sort, method);
    alloc_and_free(sort, size, 1);
    return 0;
}

int main(void)
{
    list_arg_t *list = NULL;

    if (workshop_shell(&list) == 84)
        return 84;
    return 0;
}
