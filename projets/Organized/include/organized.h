/*
** EPITECH PROJECT, 2024
** organized.h
** File description:
** organized
*/

#ifndef ORGANIZED_H_
    #define ORGANIZED_H_
    #include <stdlib.h>
    #include "bootstrap.h"
    #include "shell.h"
    #include "my.h"

typedef struct list_arg_s {
    char *type;
    char *name;
    int id;
    struct list_arg_s *prev;
    struct list_arg_s *next;
} list_arg_t;
typedef struct sort_args_s {
    char **types;
    char **names;
    int *ids;
} sort_args_t;
list_arg_t *create_new_arg(char **args);
void print_added(char *type, int id, char *name);
void increment_id(list_arg_t *copy, list_arg_t *new_arg);
void last_del(list_arg_t *cp, list_arg_t *prev, list_arg_t **base,
    int to_delete);
void del_middle_arg(list_arg_t **base, list_arg_t *copy, list_arg_t *prev,
    int to_delete);
void *sorting(void *data, type_t type, int size);
int get_list_size(list_arg_t *copy);
void alloc_and_free(sort_args_t *sort, int size, int method);
void fill_tabs(list_arg_t *base, sort_args_t *sort, int size);
void fill_result(list_arg_t *base, sort_args_t *sort, char *method);
#endif
