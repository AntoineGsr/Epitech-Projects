/*
** EPITECH PROJECT, 2020
** rb_func.c
** File description:
** pushswap
*/

#include "pushswap.h"

l_list *rb_func(l_list **l_a, list **gbl)
{
    int sck_nb = 0;

    if ((*gbl)->first->next->next != NULL) {
        sck_nb = (*l_a)->nb;
        *l_a = (*gbl)->last;
        *l_a = add_to_list(gbl, l_a, sck_nb);
        *l_a = (*gbl)->first;
        *l_a = del_to_list(gbl, l_a, 0);
    }
    *l_a = (*gbl)->first;
    return (*l_a);
}