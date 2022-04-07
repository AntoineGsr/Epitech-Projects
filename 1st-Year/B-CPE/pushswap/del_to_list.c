/*
** EPITECH PROJECT, 2020
** del_to_list.c
** File description:
** pushswap
*/

#include "pushswap.h"

l_list *del_last_first(list **gbl, l_list **l_a)
{
    (*gbl)->first = NULL;
    (*gbl)->last = NULL;
    (*l_a) = (*gbl)->first;
    return (*l_a);
}

l_list *del_to_list(list **gbl, l_list **l_a, int nb)
{
    if ((*gbl)->first->next == NULL) {
        del_last_first(gbl, l_a);
        return (*l_a);
    }
    if (nb == 0) {
        (*gbl)->first = (*gbl)->first->next;
        (*gbl)->first->previous = NULL;
    } else if (nb == (*gbl)->max) {
        (*gbl)->last = (*gbl)->last->previous;
        (*gbl)->last->next = NULL;
    } else {
        for (int i = 0; i < nb; i++)
            (*l_a) = (*l_a)->next;
        (*l_a)->previous->next = (*l_a)->next;
        (*l_a)->next = NULL;
    }
    (*gbl)->max -= 1;
    (*gbl)->nb_count -= 1;
    (*l_a) = (*gbl)->first;
    return (*l_a);
}