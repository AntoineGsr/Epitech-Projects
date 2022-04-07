/*
** EPITECH PROJECT, 2021
** gestion_input_exit.c
** File description:
** minishell1
*/

#include "../include/minishell.h"

int ex_to_ret(global_list **father, list **my_env, l_list **node_env)
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

void value_ex_ret(global_list **father, list **my_env, l_list **node_env)
{
    if ((*father)->sort[1] != NULL) {
        if ((*father)->ac > 2)
            return;
        if (ex_to_ret(father, my_env, node_env) == 1)
            return;
        (*father)->exit = my_getnbr((*father)->sort[1]);
    }
    (*father)->exit_child = 0;
    (*father)->exit_null = 1;
}