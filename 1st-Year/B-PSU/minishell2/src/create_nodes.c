/*
** EPITECH PROJECT, 2021
** create_nodes.c
** File description:
** minishell1
*/

#include "../include/minishell.h"

void create_nodes(list **my_env, l_list **node_env, char **env)
{
    for (int i = 0; env != NULL && *(env + i) != 0; i++) {
        if (verif_env_major_var(my_env, env, i) == 0) {
            *node_env = add_to_list(my_env, node_env, *(env + i));
        }
    }
    if (env != NULL)
        verif_env_created(my_env, node_env);
    *node_env = (*my_env)->first;
}

void create_shell(global_list **father, list **my_env,
l_list **node_env, char **env)
{
    create_nodes(my_env, node_env, env);
    (*father)->env = malloc(sizeof(char *) * ((*my_env)->total_env + 1));
    create_array_env(father, my_env, node_env);
}