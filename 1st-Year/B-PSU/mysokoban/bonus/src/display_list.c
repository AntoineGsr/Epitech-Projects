/*
** EPITECH PROJECT, 2020
** display_l.c
** File description:
** lib_antoine_gasser
*/

#include "../include/sokoban.h"

char *display(l_list *node)
{
    if (node == NULL) {
        my_putstr("NULL\n");
        return NULL;
    }
    while (node != NULL) {
        my_putstr("[");
        my_put_nbr(node->pos_x);
        my_putstr(", ");
        my_put_nbr(node->pos_y);
        my_putstr("]");
        my_putstr(" -> ");
        node = node->next;
    }
    my_putstr("NULL\n");
    return NULL;
}
