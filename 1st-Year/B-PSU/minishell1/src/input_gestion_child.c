/*
** EPITECH PROJECT, 2021
** read_input.c
** File description:
** minishell1
*/

#include "../include/minishell.h"

int null_input(global_list **father, list **my_env, l_list **node_env)
{
    if ((*father)->sort == NULL) {
        (*father)->input_modif = my_memset_char(2);
        (*father)->input_modif = my_strcat((*father)->input_modif, " ");
        return (1);
    }
    return (0);
}

int random_input(global_list **father, list **my_env, l_list **node_env)
{
    (*father)->input_modif = my_memset_char(my_strlen((*father)->sort[0]) + 1);
    (*father)->input_modif = my_strcat((*father)->input_modif,
    (*father)->sort[0]);
    return (1);
}

int compare_notexec_child(global_list **father, list **my_env,
l_list **node_env)
{
    if (my_strcmp((*father)->sort[0], "setenv") == 0 && (*father)->ac != 1)
        return (1);
    if (my_strcmp((*father)->sort[0], "unsetenv") == 0)
        return (1);
    if (my_strcmp((*father)->sort[0], "cd") == 0)
        return (1);
    return (0);
}

int command_input(global_list **father, list **my_env, l_list **node_env)
{
    if (compare_env(father, my_env, node_env) == 1)
        return (1);
    if (compare_notexec_child(father, my_env, node_env) == 1)
        return (1);
    if (compare_exit(father, my_env, node_env) == 1)
        return (1);
    if (compare_cmd_system(father, my_env, node_env) == 1)
        return (1);
    return (0);
}

int exec_input_child(global_list **father, list **my_env, l_list **node_env)
{
    if (null_input(father, my_env, node_env) == 1) return (0);
    if (command_input(father, my_env, node_env) == 1) return (0);
    return (random_input(father, my_env, node_env));
}