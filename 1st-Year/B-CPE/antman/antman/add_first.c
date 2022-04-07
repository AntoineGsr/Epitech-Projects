/*
** EPITECH PROJECT, 2020
** add_position.c
** File description:
** pushswap
*/

#include "../include/antman.h"

int stock_code(list **gbl, l_list **l_a, char *value)
{
    int code = 0;

    (*gbl)->max_code += 1;
    code = (*gbl)->max_code;
    return (code);
}

char *stock_value(list **gbl, l_list **l_a, char *value)
{
    char *val = my_memset_char(my_strlen(value) + 1);

    val = my_strcpy(val, value);
    return (val);
}

l_list *add_first(list **gbl, l_list **l_a, char *value)
{
    l_list *new = malloc(sizeof(l_list));

    if (new == NULL) return NULL;
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
    (*gbl)->total_dico += 1;
    new->frequency = 1;
    new->value = stock_value(gbl, l_a, value);
    new->code = stock_code(gbl, l_a, value);
    return (new);
}