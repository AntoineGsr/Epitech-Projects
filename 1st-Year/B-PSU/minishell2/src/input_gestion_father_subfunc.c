/*
** EPITECH PROJECT, 2021
** input_gestion_father_subfunc.c
** File description:
** minishell1
*/

#include "../include/minishell.h"

void create_value_env(global_list **father, list **my_env, l_list **node_env,
int total_size)
{
    (*node_env)->value_env = my_memset_char(total_size);
    (*node_env)->value_env = my_strcat((*node_env)->value_env,
    (*father)->sort[1]);
    (*node_env)->value_env = my_strcat((*node_env)->value_env, "=");
    if ((*father)->ac == 3) {
        (*node_env)->value_env = my_strcat((*node_env)->value_env,
        (*father)->sort[2]);
    }
}

void unsetenv_del_node(global_list **father, list **my_env, l_list **node_env)
{
    if ((*node_env)->next != NULL) {
        (*node_env)->previous->next = (*node_env)->next;
        (*node_env)->next->previous = (*node_env)->previous;
        (*node_env)->previous = NULL;
        (*node_env)->next = NULL;
        *node_env = NULL;
        free(*node_env);
    } else {
        (*my_env)->last = (*my_env)->last->previous;
        if ((*node_env)->previous != NULL)
            (*node_env)->previous->next = NULL;
        (*node_env)->previous = NULL;
        *node_env = NULL;
        free(*node_env);
    }
}

void unsetenv_fth_last_var(global_list **father, list **my_env,
l_list **node_env)
{
    if (*node_env != NULL) {
        if (my_strcmp((*father)->sort[1], "*") == 0
            || my_strncmp((*father)->sort[1],
            (*node_env)->value_env, my_strlen((*father)->sort[1])) == 0) {
            (*my_env)->first = NULL;
            (*my_env)->last = NULL;
            *node_env = NULL;
            free(*node_env);
            (*my_env)->total_env -= 1;
        }
    }
}

int compare_unsetenv_fth_loop(global_list **father, list **my_env,
l_list **node_env)
{
    while (*node_env != NULL && (*my_env)->total_env > 1) {
        if (my_strcmp((*father)->sort[1], "*") == 0) {
            (*node_env)->previous = NULL;
            (*my_env)->first = *node_env;
            free((*node_env)->previous);
            (*my_env)->total_env = 0;
        } else if (my_strncmp((*father)->sort[1], (*node_env)->value_env,
            my_strlen((*father)->sort[1])) == 0) {
            unsetenv_del_node(father, my_env, node_env);
            (*my_env)->total_env -= 1;
            return (1);
        }
        *node_env = (*node_env)->next;
    }
    unsetenv_fth_last_var(father, my_env, node_env);
    return (0);
}