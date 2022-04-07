/*
** EPITECH PROJECT, 2021
** make_set_no_arg
** File description:
** make_set_no_arg
*/

#include "../../include/my.h"

void make_set_no_arg(storage_t *storage)
{
    local_var_t *tmp = storage->local_var;

    while (tmp->next != NULL) {
        printf("%s\t%s\n", tmp->var_name, tmp->content);
        tmp = tmp->next;
    }
}