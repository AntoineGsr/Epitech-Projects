/*
** EPITECH PROJECT, 2021
** save_to_word_array.c
** File description:
** my_rpg
*/

#include "../include/n4s.h"

static char *decale_pointer(char *av, char sep, int nb_sep)
{
    if (!(*av))
        return NULL;
    for (int i = 0; i < nb_sep && *av; ++av) {
        if (*av == sep)
            i += 1;
    }
    return (av);
}

char *parse_end_game(char *av, char sep, int nb_sep)
{
    char *arg = my_memset_char(50);
    int k = 0;

    av = decale_pointer(av, sep, nb_sep);
    for (; *av; ++av) {
        if (*av != '\0' || *av != sep) {
            arg[k] = *av;
            k++;
        } else {
            arg[k] = '\0';
            return (arg);
        }
    }
    return (arg);
}