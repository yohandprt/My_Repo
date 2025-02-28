/*
** EPITECH PROJECT, 2024
** add_arguments.c
** File description:
** add_arguments
*/

#include "my.h"
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

void adding(char **argv, char **paths, char *args, int i)
{
    int ind_args = 0;
    int ind_path = 0;

    for (int j = 0; j < my_strlen(argv[i]); j++) {
        if (*argv[i] == '-') {
            args[ind_args] = argv[i][j];
            ind_args++;
        } else {
            paths[ind_path] = argv[i];
            ind_path++;
            break;
        }
    }
}

char *add_arguments(char **argv, char **paths, char *args, int argc)
{
    for (int i = 1; i < argc; i++) {
        adding(argv, paths, args, i);
    }
}
