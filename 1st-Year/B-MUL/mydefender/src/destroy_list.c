/*
** EPITECH PROJECT, 2021
** destroy_list.c
** File description:
** lib_antoine_gasser
*/

#include "../include/../include/my_defender.h"

void destroy_first_node(list **gbl, l_list **node)
{
    (*gbl)->first = (*node)->next;
    (*node)->next = NULL;
    (*node)->previous = NULL;
    free(*node);
    *node = (*gbl)->first;
}

void destroy_node_noloop_pos(list **gbl, l_list **node, int *pos)
{
    if (*pos == (*gbl)->max_node - 1) {
        (*gbl)->last = (*node)->previous;
    } else {
        (*node)->previous->next = (*node)->next;
        (*node)->next->previous = (*node)->previous;
    }
    free(*node);
    (*gbl)->max_node -= 1;
    *pos -= 1;
}

void destroy_node_noloop(list **gbl, l_list **node, int *pos)
{
    if (*pos == 0 && (*gbl)->max_node > 1) {
        (*gbl)->first = (*node)->next;
        free(*node);
        (*gbl)->max_node -= 1;
        *pos -= 1;
    } else if (*pos == 0 && (*gbl)->max_node == 1) {
        (*gbl)->first = NULL;
        (*gbl)->last = NULL;
        (*node)->next = NULL;
        (*node)->previous = NULL;
        free(*node);
        (*gbl)->max_node -= 1;
        *pos -= 1;
    } else {
        if (*pos < (*gbl)->max_node)
            destroy_node_noloop_pos(gbl, node, pos);
    }
}

void destroy_list(list **gbl, l_list **node)
{
    while ((*gbl)->first != NULL) {
        destroy_first_node(gbl, node);
    }
    free(*node);
    free(*gbl);
}