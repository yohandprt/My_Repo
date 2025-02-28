/*
** EPITECH PROJECT, 2025
** mysh.h
** File description:
** mysh
*/

#ifndef MYSH_H
    #define MYSH_H
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "my.h"
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include <signal.h>
    #include <errno.h>
    #include <stdint.h>

typedef struct shell_s {
    char **my_env;
    char **args;
    char *buffer;
    char *path;
    int check_path;
    char *oldpwd;
} shell_t;
typedef struct status_s {
    int retour;
    int check;
} status_t;
int error_not_found(char **args);
int error_wrong_binary(char *command);
int cd_too_many_args(void);
int cd_no_exist_directory(char *dir);
int cd_no_perm(char *dir);
int cd_no_dir(char *file);
int unsetenv_no_args(void);
int setenv_many_args(void);
char **string_to_array(char *buffer, char *separator);
char *get_command_path(shell_t *shell, int *direct_path);
char *get_path(shell_t *shell, char **all_paths, char *command,
    int *direct_path);
int check_commands(shell_t *shell);
int special_cd(shell_t *shell);
int dash(shell_t *shell);
int tilde(shell_t *shell);
int go_home(shell_t *shell);
int is_file_exist(char const *path);
int is_dir(char const *path);
int have_file_permissions(char const *path);
int my_unsetenv(shell_t *shell);
int my_setenv(shell_t *shell, char *var, char *val);
int get_index(char **array, char *src);
char **cp_array(char **array);
int display_env(shell_t *shell);
void free_array(char **array);
int undefined_variable(char *var, char *pwd);
void free_path(char *path);
#endif
