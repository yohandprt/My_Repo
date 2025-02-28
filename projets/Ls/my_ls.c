/*
** EPITECH PROJECT, 2024
** my_ls.c
** File description:
** my_ls
*/

#include "include/my.h"
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

static int count_files(struct dirent *dossier, char *path)
{
    DIR *doss_actu = opendir(path);
    int cpt = 0;

    dossier = readdir(doss_actu);
    while (dossier != NULL) {
        cpt++;
        dossier = readdir(doss_actu);
    }
    closedir(doss_actu);
    return cpt;
}

static int in_args(char *args, char a)
{
    for (int i = 0; args[i] != '\0'; i++) {
        if (args[i] == a)
            return 1;
    }
    return 0;
}

static void perm(char **paths_file_names, char **file_names)
{
    for (int i = 0; file_names[i] != NULL; i++)
        display_perm(paths_file_names[i], file_names[i]);
}

static void display_ls(char **file_names)
{
    for (int a = 0; file_names[a] != NULL; a++) {
        my_putstr(file_names[a]);
        my_putstr("  ");
    }
    my_putchar('\n');
}

static int add_files(struct doss *doss, char *args, struct names *names,
    char *path)
{
    int i = 0;

    while (doss->dossier != NULL) {
        if (*doss->dossier->d_name != '.' || in_args(args, 'a') == 1 &&
        in_args(args, 'd') == 0) {
            names->files[i] = doss->dossier->d_name;
            names->paths_files[i] = my_strcat(path, doss->dossier->d_name);
            i++;
        }
        if (in_args(args, 'd') == 1) {
            names->files[0] = path;
            i++;
            break;
        }
        doss->dossier = readdir(doss->actu);
    }
    return i;
}

void after(struct doss *doss, struct names *names, char *args, int i)
{
    names->files[i] = NULL;
    names->paths_files[i] = NULL;
    my_sort_str_array(names->files);
    my_sort_str_array(names->paths_files);
    if (in_args(args, 'r') == 1)
        my_rev_array(names->files);
    if (in_args(args, 'l') == 1)
        perm(names->paths_files, names->files);
    else
        display_ls(names->files);
    closedir(doss->actu);
}

char *init_path(char **argv, char *args, int argc, char *path)
{
    char **paths = malloc(sizeof(argv) + 1);

    paths[0] = "./";
    add_arguments(argv, paths, args, argc);
    path = paths[0];
    return path;
}

struct names *fill_names(struct names *names, char **files, char **paths_files)
{
    names->files = files;
    names->paths_files = paths_files;
    return names;
}

void my_ls(int argc, char **argv)
{
    char *path;
    struct dirent *dossier;
    int nb_files;
    char **files;
    char **paths_files;
    DIR *doss_actu;
    char *args = malloc(sizeof(char) * argc + 1);
    int i = 0;
    struct doss *doss = malloc(sizeof(DIR *) + sizeof(struct dirent *) + 1);
    struct names *names = malloc(sizeof(char **) * 2 + 1);

    names = fill_names(names, files, paths_files);
    path = init_path(argv, args, argc, path);
    nb_files = count_files(doss->dossier, path);
    names->files = malloc(sizeof(struct dirent) * nb_files + 1);
    names->paths_files = malloc(sizeof(struct dirent) * nb_files + 1);
    doss->actu = opendir(path);
    doss->dossier = readdir(doss->actu);
    i = add_files(doss, args, names, path);
    after(doss, names, args, i);
}

int main(int argc, char **argv)
{
    my_ls(argc, argv);
    return 0;
}
