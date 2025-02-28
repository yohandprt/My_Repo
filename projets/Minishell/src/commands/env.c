/*
** EPITECH PROJECT, 2025
** env.c
** File description:
** env
*/

#include "../../include/mysh.h"

int display_env(shell_t *shell)
{
    for (int i = 0; (shell->my_env)[i]; i++) {
        if (my_strcmp((shell->my_env)[i], "\0") == 0)
            continue;
        my_printf("%s\n", (shell->my_env)[i]);
    }
    return 0;
}

static int comp_in_ints(int a, int *inds, char **args)
{
    int len = my_arraylen(args);

    for (int i = 0; i < len; i++) {
        if (a == inds[i])
            return 0;
    }
    return 1;
}

static int *fill_all_inds(shell_t *shell)
{
    int nb_to_delete = my_arraylen(shell->args);
    int *all_inds = malloc(sizeof(int) * nb_to_delete);
    int ind_sup = 0;

    for (int i = 0; shell->args[i]; i++) {
        ind_sup = get_index(shell->my_env, my_strcat(shell->args[i], "="));
        all_inds[i] = ind_sup;
    }
    return all_inds;
}

int my_unsetenv(shell_t *shell)
{
    char *var_equal = my_strcat(shell->args[1], "=");
    int index = get_index(shell->my_env, var_equal);

    free(var_equal);
    if (index == -1)
        return 1;
    free(shell->my_env[index]);
    for (int i = index; shell->my_env[i] != NULL; i++)
        shell->my_env[i] = shell->my_env[i + 1];
    return 0;
}

int check_if_exist(shell_t *shell, char *var, char *new_line2)
{
    char *var_equal = my_strcat(var, "=");
    int ind_exist = get_index(shell->my_env, var_equal);
    int exist = 0;

    if (ind_exist != -1) {
        free(shell->my_env[ind_exist]);
        shell->my_env[ind_exist] = NULL;
        shell->my_env[ind_exist] = new_line2;
        exist = 1;
    }
    free(var_equal);
    return exist;
}

static int check_correct_var(char *var)
{
    if (!(var[0] > 65 && var[0] < 90 || var[0] > 97 && var[0] < 122 ||
        var[0] == '_')) {
        my_puterr("setenv: Variable name must begin with a letter.\n");
        return -1;
    }
    for (int i = 0; var[i] != '\0'; i++) {
        if ((var[i] < 65 || var[i] > 122 || var[i] == '^') &&
            (var[i] != '_' && var[i] != '.')) {
            my_puterr("setenv: Variable name must contain alphanumeric"
            " characters.\n");
            return -2;
        }
    }
    return 1;
}

static char **setup_new_env(shell_t *shell)
{
    char **new_env = malloc(sizeof(char *) * (my_arraylen(shell->my_env) + 2));
    int i = 0;

    for (; shell->my_env[i]; i++)
        new_env[i] = my_strdup(shell->my_env[i]);
    new_env[i] = NULL;
    return new_env;
}

static char *get_new_line(char *var, char *val)
{
    char *new_line;
    char *new_line2;

    if (val != NULL) {
        new_line = my_strcat(var, "=");
        new_line2 = my_strcat(new_line, val);
        free(new_line);
    } else
        new_line2 = my_strcat(var, "=");
    return new_line2;
}

int my_setenv(shell_t *shell, char *var, char *val)
{
    char **new_env = setup_new_env(shell);
    int ind = my_arraylen(new_env);
    char *new_line2;

    if (check_correct_var(var) != 1)
        return 1;
    new_line2 = get_new_line(var, val);
    if (check_if_exist(shell, var, new_line2) != 1) {
        new_env[ind] = my_strdup(new_line2);
        new_env[ind + 1] = NULL;
        free_array(shell->my_env);
        shell->my_env = NULL;
        shell->my_env = cp_array(new_env);
        free(new_line2);
        free_array(new_env);
    } else
        free_array(new_env);
    return 0;
}
