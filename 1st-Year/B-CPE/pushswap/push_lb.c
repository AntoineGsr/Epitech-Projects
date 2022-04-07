/*
** EPITECH PROJECT, 2020
** push_lb.c
** File description:
** pushswap
*/

#include "pushswap.h"

l_list push_lb(l_list **l_a, l_list **l_b, list **gbl, list **gbl_b)
{
    if ((*gbl_b)->first != NULL) {
        pa_func(l_a, l_b, gbl, gbl_b);
        (*gbl) = print_action(gbl, " pa");
        push_lb(l_a, l_b, gbl, gbl_b);
    }
}