/*
** EPITECH PROJECT, 2020
** add_position.c
** File description:
** lib_antoine_gasser
*/

#include "../include/../include/my_defender.h"

l_list *add_first(list **gbl, l_list **node, int nb)
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
        new->next = *node;
        new->previous = NULL;
        (*node)->previous = new;
        new->next->next = (*node)->next;
    }
    (*gbl)->max_node += 1;
    return (new);
}
