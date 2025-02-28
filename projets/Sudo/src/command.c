/*
** EPITECH PROJECT, 2025
** handling_error.c
** File description:
** handling_error
*/

#include "../include/my.h"
#include "../include/my_sudo.h"
#include <stdlib.h>
#include <unistd.h>

void exec_command(sudo_args_t *args)
{
    if (args->file == "\0") {
        execlp(args->command, args->command, NULL);
    } else {
        execlp(args->command, args->command, args->file, NULL);
    }
}

void command(sudo_args_t *args, int tests)
{
    list_users_t *list = get_users();
    char *user_actu = getenv("USER");
    char *mdp = get_passwd(user_actu, list->list_users);
    char *mdp_given = ask_pass(user_actu);
    char *hashed_mdp = hash(mdp, mdp_given);
    int no_mdp = 0;

    if (my_strcmp(mdp, "no mdp") == 0)
        no_mdp = 1;
    if ((my_strcmp(mdp, hashed_mdp) == 0 || no_mdp == 1) &&
        my_strcmp(mdp, "root mdp") != 0) {
            exec_command(args);
    } else if (tests < 3) {
        my_puterr("Sorry, try again.\n");
        return command(args, tests + 1);
    } else {
        my_puterr("my_sudo: 3 incorrect password attemps\n");
        exit(84);
    }
}
