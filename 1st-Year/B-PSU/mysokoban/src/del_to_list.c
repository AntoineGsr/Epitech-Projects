/*
** EPITECH PROJECT, 2020
** del_to_list.c
** File description:
** lib_antoine_gasser
*/

#include "../include/sokoban.h"

void del_last_first(list **gbl, l_list **node)
{
    (*gbl)->first = NULL;
    (*gbl)->last = NULL;
    (*node) = (*gbl)->first;
    (*gbl)->max_node -= 1;
}

void del_to_list(list **gbl, l_list **node, int pos)
{
    if ((*gbl)->first->next == NULL) {
        del_last_first(gbl, node);
        return;
    }
    if (pos == 0) {
        (*gbl)->first = (*node)->next;
        (*node)->next = NULL;
        (*node)->previous = NULL;
        free(*node);
    } else if (pos == (*gbl)->max_node) {
        (*gbl)->last = (*gbl)->last->previous;
        (*gbl)->last->next = NULL;
    } else {
        for (int i = 0; i < pos; i++)
            (*node) = (*node)->next;
        (*node)->previous->next = (*node)->next;
        (*node)->next = NULL;
    }
    (*gbl)->max_node -= 1;
    *node = (*gbl)->first;
}