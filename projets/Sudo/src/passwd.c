/*
** EPITECH PROJECT, 2025
** handling_error.c
** File description:
** handling_error
*/

#include "../include/my.h"
#include "../include/my_sudo.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char *get_passwd(const char *usr, char **list_users)
{
    const char *user_actu = getenv("USER");
    char *buffer = get_open("/etc/shadow");
    char **passwds = my_str_to_word_array(buffer, '\n');
    char **list_passwds = malloc(sizeof(char *) * (my_arraylen(passwds) + 1));
    char *mdp;

    for (int i = 0; passwds[i] != NULL; i++)
        list_passwds[i] = my_str_to_word_array(passwds[i], ':')[1];
    for (int j = 0; list_passwds[j] != NULL; j++) {
        if (my_strcmp(list_users[j], user_actu) == 0)
            mdp = list_passwds[j];
    }
    if (my_strcmp(mdp, "") == 0)
        return "no mdp";
    if ((my_strcmp(mdp, "!") == 0) || my_strcmp(mdp, "*") == 0)
        return "root mdp";
    return mdp;
}

char *ask_pass(const char *usr)
{
    char *ask = "[my_sudo] password for ";
    char *mdp;

    ask = my_strcat(ask, usr);
    ask = my_strcat(ask, ": ");
    if (isatty(fileno(stdin)) == 0) {
        my_printf("%s", ask);
        fgets(mdp, 100, stdin);
        mdp[my_strlen(mdp) - 1] = '\0';
    } else
        mdp = getpass(ask);
    return mdp;
}

char *get_sel(char *mdp)
{
    char **sel;

    if (my_strstr(mdp, "$") != NULL) {
        sel = my_str_to_word_array(mdp, '$');
        sel[2] = my_strcat("$6$", sel[2]);
        return sel[2];
    }
    return NULL;
}

char *hash(char *mdp, char *mdp_given)
{
    char *sel = get_sel(mdp);
    char *hashed_mdp = mdp;

    if (sel != NULL && my_strcmp(mdp, "\0") != 0)
        hashed_mdp = crypt(mdp_given, sel);
    return hashed_mdp;
}
