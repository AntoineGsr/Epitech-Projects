/*
** EPITECH PROJECT, 2020
** rr_func.c
** File description:
** pushswap
*/

#include "pushswap.h"

void rr_func(l_list **l_a, l_list **l_b, list **gbl, list **gbl_b)
{
    *l_a = ra_func(l_a, gbl);
    *l_b = rb_func(l_b, gbl_b);
}