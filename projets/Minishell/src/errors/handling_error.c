/*
** EPITECH PROJECT, 2025
** handling_error.c
** File description:
** handling_error
*/

#include "../../include/mysh.h"

int error_not_found(char **args)
{
    my_puterr(args[0]);
    my_puterr(": Command not found.\n");
    return 1;
}

int error_wrong_binary(char *command)
{
    my_puterr(command);
    my_puterr(": 1: Syntax error: \"(\" unexpected\n");
    return 2;
}
