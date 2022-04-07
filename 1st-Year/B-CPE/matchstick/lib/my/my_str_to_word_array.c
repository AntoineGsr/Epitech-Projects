/*
** EPITECH PROJECT, 2021
** my_str_to_to_array.c
** File description:
** minishell1
*/

#include "my.h"

int count_spaces(char *av)
{
    int count = 2;

    if (av == NULL) return (0);
    for (int i = 0; av[i] != '\0'; i++) {
        if (av[i] == ' ' || av[i] == '\t')
            count++;
    }
    return (count);
}

char **my_str_to_word_array(char *av)
{
    char **arg = NULL;
    int k = 0;
    int l = 0;
    int count = count_spaces(av);

    if (count - 2 >= my_strlen(av) - 1) return NULL;
    arg = my_memset_dchar(count, my_strlen(av) - count + 3);
    for (int j = 0; av[j] != '\0'; j++) {
        if (av[j] != ' ' && av[j] != '\n' && av[j] != '\t') {
            arg[k][l] = av[j];
            l++;
        } else if (arg[k][0] != '\0') {
            arg[k][l] = '\0';
            k++;
            l = 0;
        }
    }
    arg[k][l] = '\0';
    arg[k] = NULL;
    return (arg);
}
