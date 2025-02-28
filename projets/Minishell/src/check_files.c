/*
** EPITECH PROJECT, 2025
** check_files.c
** File description:
** check_files
*/

#include "../include/mysh.h"

int is_file_exist(char const *path)
{
    return access(path, F_OK);
}

int have_file_permissions(char const *path)
{
    return access(path, R_OK);
}

int is_dir(char const *path)
{
    struct stat st;

    lstat(path, &st);
    if (S_ISDIR(st.st_mode))
        return 1;
    return -1;
}
