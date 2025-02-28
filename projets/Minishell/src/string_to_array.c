/*
** EPITECH PROJECT, 2025
** string_to_array.c
** File description:
** string_to_array
*/

#include "../include/mysh.h"

int comp_char_str(char c, char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (c == str[i])
            return 1;
    }
    return 0;
}

int count_nb_words(char *buffer, char *separator)
{
    int cpt = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (comp_char_str(buffer[i], separator))
            cpt++;
    }
    return cpt + 1;
}

char **string_to_array(char *buffer, char *separator)
{
    int i = 0;
    int size = count_nb_words(buffer, separator);
    char **array = malloc(sizeof(char *) * (size + 1));
    char *token;
    char *saveptr;

    token = strtok_r(buffer, separator, &saveptr);
    while (token != NULL) {
        array[i] = my_strdup(token);
        i++;
        token = strtok_r(NULL, separator, &saveptr);
    }
    array[i] = NULL;
    return array;
}
