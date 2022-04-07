/*
** EPITECH PROJECT, 2020
** verif_sort.c
** File description:
** pushswap
*/

#include "pushswap.h"

int verif_sort(l_list **l_a, l_list **l_b, list **gbl, list **gbl_b)
{
    while ((*l_a)->next != NULL) {
        if ((*l_a)->nb <= (*l_a)->next->nb) {
            (*l_a) = (*l_a)->next;
        } else {
            (*l_a) = (*gbl)->first;
            return (1);
        }
    }
    return (0);
}