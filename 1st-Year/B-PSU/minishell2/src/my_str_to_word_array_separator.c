/*
** EPITECH PROJECT, 2021
** my_str_to_word_array_separator.c
** File description:
** minishell2
*/

#include "../include/minishell.h"

int count_separator_struct(char *av, char sep)
{
    int count = 2;

    if (av == NULL) return (0);
    for (int i = 0; av[i] != '\0'; i++) {
        if (av[i] == sep)
            count++;
    }
    return (count);
}

char **my_str_to_word_array_separator_struct(char *av, char sep, list **my_env)
{
    char **arg = NULL;
    int k = 0;
    int l = 0;
    int count = count_separator_struct(av, sep);

    if (count - 2 >= my_strlen(av) - 1) return NULL;
    arg = my_memset_dchar(count, my_strlen(av) - count + 3);
    for (int j = 0; av[j] != '\0'; j++) {
        if (av[j] != sep) {
            arg[k][l] = av[j];
            l++;
        } else if (arg[k][0] != '\0') {
            arg[k][l] = '\0';
            k++;
            l = 0;
        }
    }
    arg[count - 1] = NULL;
    (*my_env)->nb_path = count - 1;
    return (arg);
}