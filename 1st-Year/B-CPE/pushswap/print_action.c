/*
** EPITECH PROJECT, 2020
** print_action.c
** File description:
** pushswap
*/

#include "pushswap.h"

list *print_action(list **gbl, char *action)
{
    if ((*gbl)->print == 0) {
        my_putstr_fast(action + 1);
    } else
        my_putstr_fast(action);
    (*gbl)->print = 1;
    return (*gbl);
}