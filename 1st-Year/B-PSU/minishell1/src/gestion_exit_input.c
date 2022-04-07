/*
** EPITECH PROJECT, 2021
** gestion_input_exit.c
** File description:
** minishell1
*/

#include "../include/minishell.h"

int exit_to_return(global_list **father, list **my_env, l_list **node_env)
{
    for (int i = 0; (*father)->sort[1][i] != '\0'; i++) {
        if (((*father)->sort[1][0] < '1' || (*father)->sort[1][0] > '9')
            && (*father)->ac >= 2) {
            (*father)->exit_child = 1;
            return (1);
        }
    }
    return (0);
}

void value_exit_return(global_list **father, list **my_env, l_list **node_env)
{
    if ((*father)->sort[1] != NULL) {
        if ((*father)->ac > 2)
            return;
        if (exit_to_return(father, my_env, node_env) == 1)
            return;
        (*father)->exit = my_getnbr((*father)->sort[1]);
    }
    (*father)->exit_child = 0;
    (*father)->exit_null = 1;
}