/*
** EPITECH PROJECT, 2025
** mysh.c
** File description:
** mysh
*/

#include "include/mysh.h"

void free_path(char *path)
{
    if (path != NULL) {
        free(path);
        path = NULL;
    }
}

static void display_error_status(int *status, int direct_path, char *path)
{
    if (!direct_path)
        free_path(path);
    if (WIFEXITED(*status))
        *status = WEXITSTATUS(*status);
    if (WIFSIGNALED(*status)) {
        my_puterr(strsignal(WTERMSIG(*status)));
        if (WCOREDUMP(*status) && WTERMSIG(*status) != SIGSEGV)
            my_puterr(" (core dumped)\n");
        else
            my_puterr("\n");
        *status = (WTERMSIG(*status) + 128);
    } else if (WIFSIGNALED(*status))
        *status = (WTERMSIG(*status) + 128);
}

static int check_path(shell_t *shell)
{
    if (shell->check_path == 1)
        return error_not_found(shell->args);
    if (shell->check_path == 2)
        return cd_no_perm(shell->args[0]);
    if (shell->check_path == 3)
        return error_wrong_binary(shell->args[0]);
}

int exec_command(shell_t *shell)
{
    pid_t pid = 0;
    int status = 0;
    int direct_path = 0;

    shell->path = get_command_path(shell, &direct_path);
    if (shell->path == NULL)
        return check_path(shell);
    if (access(shell->path, F_OK) == -1)
        return cd_no_perm(shell->path);
    pid = fork();
    if (pid == 0) {
        if (execve(shell->path, shell->args, shell->my_env) == -1) {
            free(shell->path);
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
        display_error_status(&status, direct_path, shell->path);
    }
    return status;
}

void commands(shell_t *shell, int *status)
{
    shell->args = string_to_array(shell->buffer, " \n\t\"");
    *status = check_commands(shell);
    if (*status == -1)
        *status = exec_command(shell);
    free_array(shell->args);
}

static int process(shell_t *shell, size_t size)
{
    int status = 0;

    while (1) {
        if (isatty(STDIN_FILENO))
            my_printf("$> ");
        if (getline(&(shell->buffer), &size, stdin) == -1)
            return status;
        if (my_strcmp(shell->buffer, "\n") == 0)
            continue;
        if (my_strcmp(shell->buffer, "exit\n") == 0) {
            my_printf("exit\n");
            break;
        }
        commands(shell, &status);
    }
    return 0;
}

int minishell1(shell_t *shell)
{
    size_t size = 100;
    int status = 0;

    shell->buffer = malloc(sizeof(char) * size);
    if (shell->buffer == NULL)
        return 84;
    status = process(shell, size);
    return status;
}

static void free_shell(shell_t *shell)
{
    free(shell->buffer);
    free_array(shell->my_env);
    if (shell->oldpwd != NULL)
        free(shell->oldpwd);
    free(shell);
}

int main(int argc, char **argv, char **env)
{
    shell_t *shell = malloc(sizeof(shell_t));
    int status = 0;

    if (env == NULL)
        return 84;
    shell->my_env = cp_array(env);
    if (shell->my_env == NULL)
        return 84;
    shell->oldpwd = NULL;
    status = minishell1(shell);
    free_shell(shell);
    return status;
}
