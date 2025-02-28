/*
** EPITECH PROJECT, 2025
** commands.c
** File description:
** commands
*/

#include "../../include/mysh.h"

int handle_cd(shell_t *shell, int len_args)
{
    if (len_args < 2)
        return go_home(shell);
    if (len_args == 2)
        return special_cd(shell);
    if (len_args > 2)
        return cd_too_many_args();
}

int handle_unsetenv(shell_t *shell, int len_args)
{
    if (len_args < 2)
        return unsetenv_no_args();
    else
        return my_unsetenv(shell);
}

int handle_setenv(shell_t *shell, int len_args)
{
    if (len_args < 2)
        return display_env(shell);
    if (len_args == 2)
        return my_setenv(shell, shell->args[1], NULL);
    if (len_args == 3)
        return my_setenv(shell, shell->args[1], shell->args[2]);
    if (len_args > 3)
        return setenv_many_args();
}

int comp_in_array(char *s1, char **array)
{
    int find = 1;

    for (int i = 0; array[i]; i++) {
        if (my_strcmp(s1, array[i]) == 0)
            find = 0;
    }
    return find;
}

static int check_commands2(shell_t *shell, int len_args)
{
    int re = 0;

    if (my_strcmp((shell->args)[0], "setenv") == 0) {
        re = handle_setenv(shell, len_args);
        return re;
    }
    return -1;
}

int check_commands(shell_t *shell)
{
    int len_args = my_arraylen(shell->args);
    char *all_env[] = {"env", "/usr/bin/env", "/bin/env", NULL};
    int re = 0;

    if (comp_in_array(shell->args[0], all_env) == 0) {
        re = display_env(shell);
        return re;
    }
    if (my_strcmp((shell->args)[0], "cd") == 0) {
        re = handle_cd(shell, len_args);
        return re;
    }
    if (my_strcmp((shell->args)[0], "unsetenv") == 0) {
        re = handle_unsetenv(shell, len_args);
        return re;
    }
    return check_commands2(shell, len_args);
}
