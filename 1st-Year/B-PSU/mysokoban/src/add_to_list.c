/*
** EPITECH PROJECT, 2020
** add_to_list.c
** File description:
** lib_antoine_gasser
*/

#include "../include/sokoban.h"

l_list *add_to_list(list **gbl, l_list **node, int i, int j)
{
    l_list *new = malloc(sizeof(l_list));

    if (new == NULL)
        return NULL;
    if ((*gbl)->first == NULL) {
        (*gbl)->first = new;
        (*gbl)->last = new;
        new->previous = NULL;
    } else {
        new->previous = *node;
        (*node)->next = new;
        (*gbl)->last = new;
    }
    new->next = NULL;
    new->pos_x = i;
    new->pos_y = j;
    (*gbl)->max_node += 1;
    return (new);
}
