/*
** EPITECH PROJECT, 2020
** bubble_sort.c
** File description:
** pushswap
*/

#include "pushswap.h"

l_list *bubble_sort(l_list **l_a, l_list **l_b, list **gbl, list **gbl_b)
{
    if ((*gbl)->first != NULL && verif_sort(l_a, l_b, gbl, gbl_b) == 1) {
        (*gbl)->sck_min = (*l_a)->nb;
        (*l_a) = find_minimum(l_a, l_b, gbl, gbl_b);
        (*l_a) = rotate_la(l_a, l_b, gbl, gbl_b);
        (*l_a) = (*gbl)->first;
        if (verif_sort(l_a, l_b, gbl, gbl_b) == 0 && (*gbl_b)->first == NULL) {
            (*l_a) = (*gbl)->first;
            return (*l_a);
        }
        (*gbl) = print_action(gbl, " pb");
        pb_func(l_a, l_b, gbl, gbl_b);
        bubble_sort(l_a, l_b, gbl, gbl_b);
    } else {
        (*l_a) = (*gbl)->first;
        push_lb(l_a, l_b, gbl, gbl_b);
    }
    return (*l_a);
}
