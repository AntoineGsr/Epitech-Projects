/*
** EPITECH PROJECT, 2020
** sa_func.c
** File description:
** pushswap
*/

#include "pushswap.h"

void sa_func(l_list **l_a, list **gbl)
{
    int stock = 0;

    if ((*gbl)->max > 0 && (*gbl)->first->next != NULL) {
        stock = (*l_a)->nb;
        (*l_a)->nb = (*l_a)->next->nb;
        (*l_a)->next->nb = stock;
    }
}
