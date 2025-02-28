/*
** EPITECH PROJECT, 2025
** handling_error.c
** File description:
** handling_error
*/

#include "../include/my.h"
#include "../include/my_sudo.h"

void help(void)
{
    my_printf("usage: ./my_sudo -h\n");
    my_printf("usage: ./my_sudo [-ugEs] [command [args ...]]\n");
}

int handling_error(int argc, char **argv)
{
    if (argc == 1) {
        help();
        return 84;
    }
    if (my_strcmp(argv[1], "-h") == 0) {
        help();
        return 1;
    }
    return 0;
}

int check_not_found(sudo_args_t *args)
{
    if (my_strcmp(args->group, "group not found") == 0)
        return 84;
    if (my_strcmp(args->user, "user not found") == 0)
        return 84;
    if (args->s == 0 && args->command == "\0")
        return 84;
}
