/*
** EPITECH PROJECT, 2025
** get_path.c
** File description:
** get_path
*/

#include "../include/mysh.h"

static char *absolut_command(char *command)
{
    if (access(command, F_OK) == 0)
        return command;
    else
        return NULL;
}

static int dir_command(shell_t *shell, char *command)
{
    struct stat st = {0};
    int fd = 0;
    uint8_t elf_file[4];

    lstat(command, &st);
    if (S_ISDIR(st.st_mode)) {
        shell->check_path = 2;
        return -1;
    }
    if (S_ISREG(st.st_mode)) {
        fd = open(command, O_RDONLY);
        read(fd, elf_file, 4);
        if (!(elf_file[0] == 0x7F && elf_file[1] ==
            'E' && elf_file[2] == 'L' && elf_file[3] == 'F')) {
                shell->check_path = 3;
                return -1;
            }
    }
    return 1;
}

static char *get_the_path(char **all_paths, char *command, int i)
{
    char *path = NULL;
    char *temp = NULL;

    temp = my_strcat(all_paths[i], "/");
    path = my_strcat(temp, command);
    free(temp);
    return path;
}

char *get_path(shell_t *shell, char **all_paths, char *command,
    int *direct_path)
{
    char *path = NULL;

    shell->check_path = 1;
    if (command == NULL)
        return NULL;
    if (dir_command(shell, command) == -1)
        return NULL;
    if (*command == '/')
        return absolut_command(command);
    if (access(command, F_OK) == 0) {
        *direct_path = 1;
        return command;
    }
    for (int i = 0; all_paths[i] != NULL; i++) {
        path = get_the_path(all_paths, command, i);
        if (access(path, F_OK) == 0)
            return path;
        free_path(path);
    }
    return NULL;
}

char *get_command_path(shell_t *shell, int *direct_path)
{
    char **all_paths = NULL;
    char *path = NULL;
    int ind_path = get_index(shell->my_env, "PATH=");

    all_paths = my_str_to_word_array((shell->my_env)[ind_path] + 5, ':');
    if (all_paths != NULL) {
        path = get_path(shell, all_paths, (shell->args)[0], direct_path);
        free_array(all_paths);
    }
    return path;
}
