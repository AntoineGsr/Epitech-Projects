/*
** EPITECH PROJECT, 2021
** update_env.c
** File description:
** minishell2
*/

#include "../include/minishell.h"

void update_env(list **my_env, l_list **node_env)
{
    change_pwd_env(my_env, node_env, "PWD");
    *node_env = (*my_env)->first;
}