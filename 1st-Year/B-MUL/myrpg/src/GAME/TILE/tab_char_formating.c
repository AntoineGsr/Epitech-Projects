/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../../include/my.h"

char ***map_to_tab(char *str)
{
    int line_nb = count_sep(str, '\n');
    char ***to_return = malloc(sizeof(char **) * (line_nb + 1));
    char **simple_tab = str_to_tab(str, '\n');

    to_return[line_nb] = NULL;
    for (int i = 0; i < line_nb; i++)
        to_return[i] = str_to_tab(simple_tab[i], ';');
    return (to_return);
}