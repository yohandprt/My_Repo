/*
** EPITECH PROJECT, 2025
** handle_args.c
** File description:
** handle_args
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int in_args(char *args, char a)
{
    for (int i = 0; args[i] != '\0'; i++) {
        if (args[i] == a)
            return 1;
    }
    return 0;
}

int is_option(char *arg)
{
    return (arg[0] == '-' && arg[1] != '\0');
}

void set_args(char *args, char *arg, int *ind)
{
    for (int j = 1; j < strlen(arg); j++) {
        if (in_args(args, arg[j]) == 0) {
            args[*ind] = arg[j];
            (*ind)++;
        }
    }
    args[*ind] = '\0';
}

char *get_args(int argc, char **argv)
{
    char *args = malloc(sizeof(char) * 100);
    int ind = 0;

    args[0] = '\0';
    for (int i = 0; i < argc; i++) {
        if (is_option(argv[i]))
            set_args(args, argv[i], &ind);
    }
    return args;
}
