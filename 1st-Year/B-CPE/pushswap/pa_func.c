/*
** EPITECH PROJECT, 2020
** pa_func.c
** File description:
** pushswap
*/

#include "pushswap.h"

void pa_func(l_list **l_a, l_list **l_b, list **gbl, list **gbl_b)
{
    int sck = (*gbl_b)->first->nb;

    *l_a = add_first(gbl, l_a, sck);
    *l_b = del_to_list(gbl_b, l_b, 0);
}