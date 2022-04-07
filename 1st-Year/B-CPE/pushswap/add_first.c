/*
** EPITECH PROJECT, 2020
** add_position.c
** File description:
** pushswap
*/

#include "pushswap.h"

l_list *add_first(list **gbl, l_list **l_a, int nb)
{
    l_list *new = malloc(sizeof(l_list));

    if (new == NULL)
        return NULL;
    if ((*gbl)->first == NULL && (*gbl)->last == NULL) {
        (*gbl)->first = new;
        (*gbl)->last = new;
        new->previous = NULL;
        new->next = NULL;
    } else {
        (*gbl)->first = new;
        new->next = *l_a;
        new->previous = NULL;
        (*l_a)->previous = new;
        new->next->next = (*l_a)->next;
    }
    (*gbl)->nb_count += 1;
    new->nb = nb;
    return (new);
}