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

list_arg_t *create_new_arg(char **args)
{
    list_arg_t *new_arg = malloc(sizeof(char *) * 2 +
        sizeof(int) + sizeof(list_arg_t *) * 2);

    new_arg->type = my_strdup(args[0]);
    new_arg->name = my_strdup(args[1]);
    new_arg->id = 0;
    new_arg->prev = NULL;
    new_arg->next = NULL;
    return new_arg;
}

void print_added(char *type, int id, char *name)
{
    my_printf("%s n°%d - \"%s\" added\n", type, id, name);
}

void increment_id(list_arg_t *copy, list_arg_t *new_arg)
{
    if (my_strcmp(copy->type, new_arg->type) == 0)
        new_arg->id++;
}
