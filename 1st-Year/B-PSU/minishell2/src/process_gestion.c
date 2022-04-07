/*
** EPITECH PROJECT, 2021
** process_gestion.c
** File description:
** minishell1
*/

#include "../include/minishell.h"

void child_gestion(global_list **father, list **my_env, l_list **node_env)
{
    int return_exec = exec_input_child(father, my_env, node_env);

    if (return_exec == 1) {
        if (my_strcmp((*father)->sort[0], "echo") != 0) {
            my_putstr_fast_error((*father)->input_modif);
            my_putstr_fast_error(": Command not found.\n");
        } else {
            my_putstr_fast_error((*father)->input_modif);
            my_putstr_fast_error(": Undefined variable.\n");
        }
    }
    destroy_func(father);
    if ((*father)->sort == NULL)
        exit(0);
    exit(1);
}

void father_gestion(global_list **father, list **my_env, l_list **node_env)
{
    int state = 0;

    while (wait(&state) >= 0);
    analyse_exit_child(father, state);
    if ((*father)->sort != NULL) {
        exec_input_father(father, my_env, node_env);
        free((*father)->sort[0]);
    }
    (*father)->ac = 0;
    (*father)->exit = (*father)->exit_child;
    free((*father)->sort);
    if ((*father)->exit == 0) {
        if ((*father)->input[0] != '\n'
            && (*father)->input_sort[(*father)->step + 1] != NULL
            && (*father)->input_sort[(*father)->step + 1][0] != '\0') {
            (*father)->exit_null == 0;
            (*father)->step += 1;
        } else
            (*father)->step = 0;
    } else
        (*father)->step = 0;
}