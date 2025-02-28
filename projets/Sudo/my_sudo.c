/*
** EPITECH PROJECT, 2025
** my_sudo.c
** File description:
** my_sudo
*/

#include "include/my.h"
#include "include/my_sudo.h"
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    sudo_args_t *args;
    int err = handling_error(argc, argv);

    if (err == 84)
        return 84;
    if (err == 1)
        return 0;
    args = get_args(argc, argv);
    if (check_not_found(args) == 84)
        return 84;
    system(args->env);
    return 0;
}
