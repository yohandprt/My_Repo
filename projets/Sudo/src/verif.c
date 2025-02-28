/*
** EPITECH PROJECT, 2025
** handling_error.c
** File description:
** handling_error
*/

#include "../include/my.h"
#include "../include/my_sudo.h"
#include <stdlib.h>

list_users_t *get_users(void)
{
    char *buffer = get_open("/etc/passwd");
    char **users = my_str_to_word_array(buffer, '\n');
    char **list_users = malloc(sizeof(char *) * (my_arraylen(users) + 1));
    list_users_t *list = malloc(sizeof(list_users_t));

    for (int i = 0; users[i] != NULL; i++)
        list_users[i] = my_str_to_word_array(users[i], ':')[0];
    list->users = users;
    list->list_users = list_users;
    return list;
}

char *get_user(char *usr, int s)
{
    list_users_t *list = get_users();

    for (int j = 0; list->list_users[j] != NULL; j++) {
        if (my_strcmp(list->list_users[j], usr) == 0 && s == 1) {
            my_printf("changing user: %s\n", usr);
            change_uid(usr, list->users, list->list_users, 1);
            return usr;
        }
        if (my_strcmp(list->list_users[j], usr) == 0 && s == 0) {
            my_printf("no changing\n");
            return usr;
        }
    }
    return "user not found";
}

char *get_group(char *grp, char *usr, int s)
{
    char *buffer = get_open("/etc/group");
    char **groups = my_str_to_word_array(buffer, '\n');
    char **list_groups = malloc(sizeof(char *) * (my_arraylen(groups) + 1));

    for (int i = 0; groups[i] != NULL; i++)
        list_groups[i] = my_str_to_word_array(groups[i], ':')[0];
    for (int j = 0; list_groups[j] != NULL; j++) {
        if (my_strcmp(list_groups[j], grp) == 0 && s == 1) {
            change_gid(grp, usr, groups, list_groups);
            return grp;
        }
        if (my_strcmp(list_groups[j], grp) == 0 && s == 0)
            return grp;
    }
    return "group not found";
}
