/*
** EPITECH PROJECT, 2020
** rotate_la.c
** File description:
** pushswap
*/

#include "pushswap.h"

l_list *rotate_la(l_list **l_a, l_list **l_b, list **gbl, list **gbl_b)
{
    if ((*gbl)->pos > 0) {
        ra_func(l_a, gbl);
        (*gbl)->pos -= 1;
        (*gbl) = print_action(gbl, " ra");
        rotate_la(l_a, l_b, gbl, gbl_b);
    }
    (*gbl)->nb_rotate = 0;
    (*l_a) = (*gbl)->first;
    return (*l_a);
}