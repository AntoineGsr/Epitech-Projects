/*
** EPITECH PROJECT, 2020
** display_l.c
** File description:
** pushswap
*/

#include "../include/minishell.h"

char *display(l_list *l_a)
{
    if (l_a == NULL) {
        return NULL;
    }
    while (l_a != NULL) {
        my_putstr(l_a->value_env);
        my_putchar('\n');
        l_a = l_a->next;
    }
    return NULL;
}
