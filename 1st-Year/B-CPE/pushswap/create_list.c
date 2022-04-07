/*
** EPITECH PROJECT, 2020
** create_list.c
** File description:
** pushswap
*/

#include "pushswap.h"

list *create_list(int ac, char **av)
{
    list *gbl = malloc(sizeof(list));

    if (gbl == NULL)
        return NULL;
    gbl->print = 0;
    gbl->nb_ac = ac - 1;
    gbl->max = count_nb_args(ac, av) - 1;
    gbl->nb_count = 0;
    gbl->sck_min = 0;
    gbl->nb_rotate = 0;
    gbl->pos = 0;
    gbl->t_rotate = 0;
    gbl->ra_rra = 0;
    gbl->first = malloc(sizeof(l_list));
    gbl->last = malloc(sizeof(l_list));
    gbl->first = NULL;
    gbl->last = NULL;
    return (gbl);
}