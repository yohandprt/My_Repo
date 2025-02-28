/*
** EPITECH PROJECT, 2024
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

int count_words(char const *str, char separator)
{
    int nb_words = 0;

    for (int i = 0; i <= my_strlen(str); i++) {
        if (str[i] == separator || str[i] == '\0')
            nb_words++;
    }
    return nb_words + 1;
}

char *append(char const *str, int i, int j)
{
    char *word = malloc(sizeof(char) * (i - j + 1));
    int k = 0;

    if (word == NULL)
        return NULL;
    for (; j < i; j++) {
        word[k] = str[j];
        k++;
    }
    word[k] = '\0';
    return word;
}

char **my_str_to_word_array(char const *str, char separator)
{
    int i = 0;
    int j = 0;
    int len = my_strlen(str);
    int nb_words = count_words(str, separator);
    char **words = malloc(sizeof(char *) * (nb_words + 1));
    int len_words = 0;

    if (words == NULL)
        return NULL;
    while (i <= len) {
        if (str[i] == separator || str[i] == '\0') {
            words[len_words] = append(str, i, j);
            len_words++;
            j = i + 1;
        }
        i++;
    }
    words[len_words] = NULL;
    return words;
}
