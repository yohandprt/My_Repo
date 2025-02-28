/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my header
*/

#ifndef _MY_SUDO_
    #define _MY_SUDO_

typedef struct sudo_args_s {
    char *user;
    char *group;
    char *env;
    int E;
    int s;
    char *command;
    char *file;
} sudo_args_t;
typedef struct list_users_s {
    char **users;
    char **list_users;
} list_users_t;
int handling_error(int argc, char **argv);
sudo_args_t *get_args(int argc, char **argv);
int check_not_found(sudo_args_t *args);
char *get_user(char *usr, int s);
char *get_group(char *grp, char *usr, int s);
char *get_open(char *FILE);
void change_uid(char *usr, char **users, char **list_users, int tests);
void change_gid(char *grp, char *usr, char **groups, char **list_groups);
char *get_passwd(const char *usr, char **list_users);
char *ask_pass(const char *usr);
char *get_sel(char *mdp);
char *hash(char *mdp, char *mdp_given);
char *check_sudoers(char *usr);
void command(sudo_args_t *args, int tests);
list_users_t *get_users(void);
#endif
