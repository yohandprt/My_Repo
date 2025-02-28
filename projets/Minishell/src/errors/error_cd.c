/*
** EPITECH PROJECT, 2025
** error_cd.c
** File description:
** error_cd
*/

#include "../../include/mysh.h"

int cd_too_many_args(void)
{
    my_puterr("cd: Too many arguments.\n");
    return 1;
}

int cd_no_exist_directory(char *dir)
{
    my_puterr(dir);
    my_puterr(": No such file or directory.\n");
    return 1;
}

int cd_no_perm(char *dir)
{
    my_puterr(dir);
    my_puterr(": Permission denied.\n");
    return 1;
}

int cd_no_dir(char *file)
{
    my_puterr(file);
    my_puterr(": Not a directory.\n");
    return 1;
}

int undefined_variable(char *var, char *pwd)
{
    if (pwd != NULL)
        free(pwd);
    my_puterr(var);
    my_puterr(": Undefined variable.\n");
    return 1;
}
