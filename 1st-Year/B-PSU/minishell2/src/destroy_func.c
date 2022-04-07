/*
** EPITECH PROJECT, 2021
** destroy_func.c
** File description:
** minishell1
*/

#include "../include/minishell.h"

void destroy_func(global_list **father)
{
    free((*father)->input_modif);
    free((*father)->input);
    if ((*father)->sort != NULL) {
        free((*father)->sort[0]);
        free((*father)->sort);
    }
}