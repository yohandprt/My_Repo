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
#include <fcntl.h>
#include <sys/stat.h>

char *get_open(char *FILE)
{
    struct stat st;
    int size;
    char *buffer;
    int fd = open(FILE, O_RDONLY);
    int rd;

    if (fd == -1)
        return NULL;
    stat(FILE, &st);
    size = st.st_size;
    buffer = malloc(sizeof(char) * size);
    rd = read(fd, buffer, size);
    return buffer;
}

static char *is_file(int argc, char **argv, int i)
{
    if (argc == i + 1)
        return "\0";
    return argv[i + 1];
}

static int check_command(sudo_args_t *args, int argc, char **argv)
{
    char *main_path = "/usr/bin/";
    char *path = "\0";
    int find_command = 0;

    for (int i = 0; i < argc; i++) {
        path = my_strcat(main_path, argv[i]);
        if (get_open(path) != NULL) {
            find_command = 1;
            args->command = argv[i];
            args->file = is_file(argc, argv, i);
            break;
        }
    }
    if (find_command == 0)
        return 84;
    else
        command(args, 1);
    return 0;
}

void check_args(sudo_args_t *args, int argc, char **argv)
{
    if (args->group != "\0")
        args->group = get_group(args->group, args->user, args->s);
    if (args->user != "\0")
        args->user = get_user(args->user, args->s);
    if (args->s == 1 && args->user == "\0" && args->group == "\0") {
        args->user = get_user("root", args->s);
        args->group = get_group("root", "root", args->s);
    }
    if (args->E == 1)
        args->env = "bash";
    if (args->s == 0) {
        if (check_command(args, argc, argv) == 84)
            exit(84);
    }
}

void set_args(sudo_args_t *args, char **argv, char arg, int i)
{
    if (arg == 'u')
        args->user = argv[i + 1];
    if (arg == 'g')
        args->group = argv[i + 1];
    if (arg == 'E')
        args->E = 1;
    if (arg == 's')
        args->s = 1;
}

sudo_args_t *init_args(void)
{
    sudo_args_t *args = malloc(sizeof(sudo_args_t));

    args->user = "\0";
    args->group = "\0";
    args->env = "sh";
    args->E = 0;
    args->s = 0;
    args->command = "\0";
    args->file = "\0";
    return args;
}

sudo_args_t *get_args(int argc, char **argv)
{
    sudo_args_t *args = init_args();

    for (int i = 0; i < argc; i++) {
        if (argv[i][0] == '-')
            set_args(args, argv, argv[i][1], i);
    }
    check_args(args, argc, argv);
    return args;
}
