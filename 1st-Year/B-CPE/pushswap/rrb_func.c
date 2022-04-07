/*
** EPITECH PROJECT, 2020
** rrb_func.c
** File description:
** pushswap
*/

#include "pushswap.h"

l_list *rrb_func(l_list **l_a, list **gbl)
{
    int sck_nb = 0;
    int max = 0;
    int i = 0;

    if ((*gbl)->nb_count > 1) {
        sck_nb = (*gbl)->last->nb;
        max = (*gbl)->max;
        *l_a = (*gbl)->first;
        *l_a = del_to_list(gbl, l_a, max);
        *l_a = add_first(gbl, l_a, sck_nb);
    }
    return (*l_a);
}