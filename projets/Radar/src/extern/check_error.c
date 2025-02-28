/*
** EPITECH PROJECT, 2025
** help.c
** File description:
** help
*/

#include "../../include/my.h"

void print_help(void)
{
    my_printf("Air traffic simulation panel\nUSAGE\n  ./my_radar "
    "[OPTIONS] path_to_script\n   path_to_script\tThe path"
    " to the script file.\nOPTIONS\n -h\t\tprint the usage and quit.\n"
    "USER INTERACTIONS\n 'L' key\tenable/disable hitboxes"
    " and areas.\n 'S' key\tenable/disable sprites.\n");
}

void print_wrong_args(void)
{
    my_printf("./my_radar: bad arguments: 0 given but 84 is"
    " required\nretry with -h\n");
}

int check_error(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        print_help();
        return 1;
    } else if (argc != 2 || my_strstr(argv[1], ".rdr") == NULL) {
        print_wrong_args();
        return 84;
    }
    return 0;
}
