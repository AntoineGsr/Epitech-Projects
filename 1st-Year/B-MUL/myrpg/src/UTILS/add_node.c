/*
** EPITECH PROJECT, 2021
** add_node.c
** File description:
** rpg
*/

#include "../../include/rpg.h"

node_t *add_node_firstpos(list_t **list, node_t **node)
{
    node_t *new = malloc(sizeof(node_t));

    if (new == NULL) return NULL;
    if ((*list)->first == NULL) {
        (*list)->first = new;
        new->next = NULL;
        new->previous = NULL;
    } else {
        (*list)->first = new;
        new->next = *node;
        new->previous = NULL;
        (*node)->previous = new;
    }
    (*list)->nb_node += 1;
    return (new);
}

void destroy_node_noloop(list_t **list, node_t **node, int *pos)
{
    if (*pos == 0 && (*list)->nb_node > 1) {
        (*list)->first = (*node)->next;
        (*node)->next->previous = NULL;
    } else if (*pos == 0 && (*list)->nb_node == 1) {
        (*list)->first = NULL;
        (*node)->next = NULL;
    } else {
        if (*pos == (*list)->nb_node - 1) {
            (*node)->previous->next = NULL;
        } else {
            (*node)->next->previous = (*node)->previous;
            (*node)->previous->next = (*node)->next;
        }
    }
    (*list)->nb_node -= 1;
    *pos -= 1;
}