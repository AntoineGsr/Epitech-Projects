/*
** EPITECH PROJECT, 2021
** save_to_word_array.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

static char *decale_pointer(char *av, char sep)
{
    if (!(*av))
        return NULL;
    for (; *av != sep && *av; ++av);
    return (av);
}

char **save_to_word_array(char *av, char sep)
{
    char **arg = NULL;
    int k = 0;
    int l = 0;

    av = decale_pointer(av, sep);
    av = av + 1;
    arg = my_memset_dchar(148, 13);
    for (; *av; ++av) {
        if (*av != '\n') {
            arg[k][l] = *av;
            l++;
        } else {
            arg[k][l] = '\0';
            av = decale_pointer(av, sep);
            k++;
            l = 0;
        }
    }
    return (arg);
}