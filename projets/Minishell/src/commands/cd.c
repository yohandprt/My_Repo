/*
** EPITECH PROJECT, 2025
** cd.c
** File description:
** cd
*/

#include "../../include/mysh.h"

int go_home(shell_t *shell)
{
    char *pwd = getcwd(NULL, 100);
    int ind_home = get_index(shell->my_env, "HOME=");

    if (ind_home != -1) {
        chdir(shell->my_env[ind_home] + 5);
        my_setenv(shell, "OLDPWD", pwd);
        shell->oldpwd = my_strdup(pwd);
    } else {
        my_puterr("HOME: Undefined variable.\n");
        free(pwd);
        return 1;
    }
    free(pwd);
    return 0;
}

static void free_oldpwd(char *oldpwd)
{
    if (oldpwd != NULL) {
        free(oldpwd);
        oldpwd = NULL;
    }
}

int tilde(shell_t *shell)
{
    char *pwd = getcwd(NULL, 100);
    int ind_home = get_index(shell->my_env, "HOME=");
    char *path;

    if (ind_home == -1)
        return undefined_variable("HOME", pwd);
    if (my_strlen(shell->args[1]) == 1)
        path = my_strdup(shell->my_env[ind_home] + 5);
    else
        path = my_strcat(shell->my_env[ind_home] + 5, shell->args[1] + 1);
    chdir(path);
    my_setenv(shell, "OLDPWD", pwd);
    free_oldpwd(shell->oldpwd);
    shell->oldpwd = my_strdup(pwd);
    free(path);
    free(pwd);
    return 0;
}

static int change_directory(shell_t *shell, char *pwd, int ind_oldpwd)
{
    int retour = 0;

    if (ind_oldpwd != -1) {
        chdir(shell->my_env[ind_oldpwd] + 7);
        my_setenv(shell, "OLDPWD", pwd);
        free_oldpwd(shell->oldpwd);
        shell->oldpwd = my_strdup(pwd);
        retour = 1;
    } else if (shell->oldpwd != NULL) {
        chdir(shell->oldpwd);
        my_setenv(shell, "OLDPWD", pwd);
        free_oldpwd(shell->oldpwd);
        shell->oldpwd = my_strdup(pwd);
        retour = 1;
    }
    return retour;
}

int dash(shell_t *shell)
{
    char *pwd = getcwd(NULL, 100);
    int ind_oldpwd = get_index(shell->my_env, "OLDPWD=");

    if (!change_directory(shell, pwd, ind_oldpwd)) {
        my_puterr(": No such file or directory.\n");
        free(pwd);
        return 1;
    }
    free(pwd);
    return 0;
}

static int tests_cd(shell_t *shell)
{
    if (my_charcmp(*(shell->args[1]), '~') == 0)
        return tilde(shell);
    if (my_strcmp(shell->args[1], "-") == 0)
        return dash(shell);
    if (is_file_exist(shell->args[1]) == -1)
        return cd_no_exist_directory(shell->args[1]);
    if (is_dir(shell->args[1]) == -1)
        return cd_no_dir(shell->args[1]);
    if (have_file_permissions(shell->args[1]) == -1)
        return cd_no_perm(shell->args[1]);
    return -1;
}

int special_cd(shell_t *shell)
{
    char *pwd = getcwd(NULL, 100);
    int retour = tests_cd(shell);

    if (retour != -1) {
        free(pwd);
        return retour;
    }
    chdir(shell->args[1]);
    retour = my_setenv(shell, "OLDPWD", pwd);
    free_oldpwd(shell->oldpwd);
    shell->oldpwd = my_strdup(pwd);
    free(pwd);
    return retour;
}
