/*
** EPITECH PROJECT, 2020
** find_minimum.c
** File description:
** pushswap
*/

#include "pushswap.h"

l_list *find_minimum(l_list **l_a, l_list **l_b, list **gbl, list **gbl_b)
{
    if ((*l_a) != NULL) {
        if ((*gbl)->sck_min > (*l_a)->nb) {
            (*gbl)->sck_min = (*l_a)->nb;
            (*gbl)->pos = (*gbl)->nb_rotate;
        }
        (*gbl)->nb_rotate += 1;
        (*l_a) = (*l_a)->next;
        find_minimum(l_a, l_b, gbl, gbl_b);
    }
    (*l_a) = (*gbl)->first;
    return (*l_a);
}