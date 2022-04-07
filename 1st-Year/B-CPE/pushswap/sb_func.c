/*
** EPITECH PROJECT, 2020
** sb_func.c
** File description:
** pushswap
*/

#include "pushswap.h"

void sb_func(l_list **l_b, list **gbl_b)
{
    int stock = 0;

    if ((*gbl_b)->max > 0 && (*gbl_b)->first->next != NULL) {
        stock = (*l_b)->nb;
        (*l_b)->nb = (*l_b)->next->nb;
        (*l_b)->next->nb = stock;
    }
}