/*
** EPITECH PROJECT, 2020
** rrr_func.c
** File description:
** pushswap
*/

#include "pushswap.h"

void rrr_func(l_list **l_a, l_list **l_b, list **gbl, list **gbl_b)
{
    *l_a = rra_func(l_a, gbl);
    *l_b = rrb_func(l_b, gbl_b);
}