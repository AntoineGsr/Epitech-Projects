/*
** EPITECH PROJECT, 2021
** gestion_array_env.c
** File description:
** minishell1
*/

#include "../include/minishell.h"

int create_array_env(global_list **father, list **my_env, l_list **node_env)
{
    for (int i = 0; *node_env != NULL && (*node_env)->next != NULL;
        *node_env = (*node_env)->next, i++) {
        (*father)->env[i] = my_memset_char(
        my_strlen((*node_env)->value_env) + 1);
        (*father)->env[i] = (*node_env)->value_env;
    }
    if ((*my_env)->total_env > 0)
        (*father)->env[(*my_env)->total_env - 1] = NULL;
    *node_env = (*my_env)->first;
}