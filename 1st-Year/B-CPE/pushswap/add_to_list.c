/*
** EPITECH PROJECT, 2020
** add_to_list.c
** File description:
** pushswap
*/

#include "pushswap.h"

l_list *add_to_list(list **gbl, l_list **l_a, int nb)
{
    l_list *new = malloc(sizeof(l_list));

    if (new == NULL)
        return NULL;
    if ((*gbl)->first == NULL) {
        (*gbl)->first = new;
        (*gbl)->last = new;
        new->previous = NULL;
    } else {
        new->previous = *l_a;
        (*l_a)->next = new;
        (*gbl)->last = new;
    }
    (*gbl)->nb_count += 1;
    new->nb = nb;
    new->next = NULL;
    return (new);
}