/*
** EPITECH PROJECT, 2021
** echo_gestion.c
** File description:
** minishell1.h
*/

#include "../include/minishell.h"

void analyse_exit_child(global_list **father, int state)
{
    if (my_strcmp((*father)->input, "echo $?\n") == 0)
        return;
    if (state == 0)
        (*father)->exit_child = 0;
    if (state == 139) {
        (*father)->exit_child = 139;
        my_putstr_fast_error("Segmentation fault (core dumped)\n");
    }
    if (state == 256)
        (*father)->exit_child = 1;
    if (state == 512)
        (*father)->exit_child = 2;
}

int compare_echo_dollar(global_list **father, list **my_env, l_list **node_env)
{
    if ((*father)->input != NULL) {
        if (my_strcmp((*father)->input, "echo $?\n") == 0) {
            my_putstr_fast(my_getstr((*father)->exit_child));
            my_putchar('\n');
            return (1);
        }
    }
    return (0);
}
