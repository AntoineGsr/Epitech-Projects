/*
** EPITECH PROJECT, 2020
** pb_func.c
** File description:
** pushswap
*/

#include "pushswap.h"

void pb_func(l_list **l_a, l_list **l_b, list **gbl, list **gbl_b)
{
    int sck = (*gbl)->first->nb;

    *l_b = add_first(gbl_b, l_b, sck);
    *l_a = del_to_list(gbl, l_a, 0);
}