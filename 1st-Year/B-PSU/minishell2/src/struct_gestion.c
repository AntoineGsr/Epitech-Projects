/*
** EPITECH PROJECT, 2021
** struct_gestion.c
** File description:
** antman
*/

#include "../include/minishell.h"

l_list *add_last(list **gbl, l_list **l_a, char *str)
{
    l_list *new = malloc(sizeof(l_list));

    if (new == NULL)
        return NULL;
    if ((*gbl)->first == NULL) {
        (*gbl)->first = new;
        (*gbl)->last = new;
        new->previous = NULL;
    } else {
        if (verif_env_exist(gbl, l_a, str) == NULL)
            return NULL;
        new->previous = *l_a;
        (*l_a)->next = new;
        (*gbl)->last = new;
    }
    new->next = NULL;
    new->value_env = str;
    (*gbl)->total_env += 1;
    return (new);
}

l_list *add_first(list **gbl, l_list **l_a, char *str)
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
    new->value_env = str;
    (*gbl)->total_env += 1;
    return (new);
}

l_list *add_to_list(list **gbl, l_list **l_a, char *str)
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
    new->next = NULL;
    new->value_env = str;
    (*gbl)->total_env += 1;
    return (new);
}

void destroy_node(list **gbl, l_list **elem)
{
    (*gbl)->first = (*elem)->next;
    (*elem)->next = NULL;
    (*elem)->previous = NULL;
    free(*elem);
    (*elem) = (*gbl)->first;
}

void destroy_list(list **gbl, l_list **elem)
{
    while ((*gbl)->first != NULL) {
        destroy_node(gbl, elem);
    }
    free(*gbl);
}