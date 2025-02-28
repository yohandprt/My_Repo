/*
** EPITECH PROJECT, 2025
** error_env.c
** File description:
** error_env
*/

#include "../../include/mysh.h"

int unsetenv_no_args(void)
{
    my_puterr("unsetenv: Too few arguments.\n");
    return 1;
}

int setenv_many_args(void)
{
    my_puterr("setenv: Too many arguments.\n");
    return 1;
}
