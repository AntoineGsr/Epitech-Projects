/*
** EPITECH PROJECT, 2021
** destroy_list.c
** File description:
** lib_antoine_gasser
*/

#include "../include/sokoban.h"

void destroy_first_node(list **gbl, l_list **node)
{
    (*gbl)->first = (*node)->next;
    (*node)->next = NULL;
    (*node)->previous = NULL;
    free(*node);
    *node = (*gbl)->first;
}

void destroy_list(list **gbl, l_list **node)
{
    while ((*gbl)->first != NULL) {
        destroy_first_node(gbl, node);
    }
    free(*node);
    free(*gbl);
}