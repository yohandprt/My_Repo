/*
** EPITECH PROJECT, 2024
** display_perm.c
** File description:
** display_perm
*/

#include "my.h"
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

char *get_uid_name(int uid)
{
    struct passwd *user = getpwuid(uid);

    return user->pw_name;
}

char *get_gid_name(int gid)
{
    struct group *gr = getgrgid(gid);

    return gr->gr_name;
}

void display_perm3(struct stat *st)
{
    if (st->st_mode & S_IROTH)
        my_printf("r");
    else
        my_printf("-");
    if (st->st_mode & S_IWOTH)
        my_printf("w");
    else
        my_printf("-");
    if (st->st_mode & S_IXOTH)
        my_printf("x");
    else
        my_printf("-");
}

void display_perm2(struct stat *st)
{
    if (st->st_mode & S_IWUSR)
        my_printf("w");
    else
        my_printf("-");
    if (st->st_mode & S_IXUSR)
        my_printf("x");
    else
        my_printf("-");
    if (st->st_mode & S_IRGRP)
        my_printf("r");
    else
        my_printf("-");
    if (st->st_mode & S_IWGRP)
        my_printf("w");
    else
        my_printf("-");
    if (st->st_mode & S_IXGRP)
        my_printf("x");
    else
        my_printf("-");
}

void display_perm(char *path_file, char *file)
{
    int len_file = my_strlen(file);
    struct stat *st = malloc(sizeof(struct stat) * sizeof(FILE *) + 1);
    char *username;
    char *groupname;

    stat(path_file, st);
    if (S_ISDIR(st->st_mode))
        my_printf("d");
    else
        my_printf("-");
    if (st->st_mode & S_IRUSR)
        my_printf("r");
    else
        my_printf("-");
    display_perm2(st);
    display_perm3(st);
    username = get_uid_name(st->st_uid);
    groupname = get_gid_name(st->st_gid);
    my_printf(" %d %s %s", st->st_nlink, username, groupname);
    my_printf(" %d %s\n", st->st_size, file);
}
