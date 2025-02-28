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

void *sorting(void *data, type_t type, int size)
{
    int *id;
    char **string;

    if (type == STRING) {
        string = *(char ***)data;
        my_sort_str_array(string);
        return string;
    }
    if (type == INTEGER) {
        id = *(int **)data;
        my_sort_int_array(id, size);
        return id;
    }
}

int get_list_size(list_arg_t *copy)
{
    int size = 0;

    while (copy != NULL) {
        size++;
        copy = copy->next;
    }
    return size;
}

void alloc_and_free(sort_args_t *sort, int size, int method)
{
    if (method == 0) {
        sort->types = malloc(sizeof(char *) * (size + 1));
        sort->names = malloc(sizeof(char *) * (size + 1));
        sort->ids = malloc(sizeof(int) * (size + 1));
    }
    if (method == 1) {
        free(sort->types);
        free(sort->names);
        free(sort->ids);
    }
}

void fill_tabs(list_arg_t *base, sort_args_t *sort, int size)
{
    list_arg_t *copy = base;
    int i = 0;

    alloc_and_free(sort, size, 0);
    while (copy != NULL) {
        sort->types[i] = my_strdup(copy->type);
        sort->names[i] = my_strdup(copy->name);
        sort->ids[i] = copy->id;
        i++;
        copy = copy->next;
    }
}

void fill_result(list_arg_t *base, sort_args_t *sort, char *method)
{
    list_arg_t *copy = base;
    int i = 0;

    while (copy != NULL) {
        copy->type = (sort->types)[i];
        copy->name = (sort->names)[i];
        copy->id = (sort->ids)[i];
        i++;
        copy = copy->next;
    }
}
