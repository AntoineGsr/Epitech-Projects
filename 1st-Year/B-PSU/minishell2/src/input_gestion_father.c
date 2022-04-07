/*
** EPITECH PROJECT, 2021
** input_gestion_father.c
** File description:
** minishell1
*/

#include "../include/minishell.h"

int compare_exit_fth(global_list **father, list **my_env, l_list **node_env)
{
    if ((*father)->sort != NULL) {
        if (my_strcmp((*father)->sort[0], "exit") == 0) {
            value_ex_ret(father, my_env, node_env);
            return (1);
        }
    }
    return (0);
}

int compare_cd_fth(global_list **father, list **my_env, l_list **node_env)
{
    int dir = 0;

    if (my_strcmp((*father)->sort[0], "cd") == 0) {
        register_input(father, "cd");
        if (error_arguments(father, "cd: Too many arguments.\n", 2) == 1)
            return (0);
        if ((*father)->sort[1] != NULL && my_strcmp((*father)->sort[1], ".")
            == 0)
            return (0);
        save_pwd(father);
        dir = compare_cd_arg(father, my_env, node_env);
        compare_cd_oldpwd(father, my_env, node_env, dir);
        return (1);
    }
    return (0);
}

int compare_setenv_fth(global_list **father, list **my_env, l_list **node_env)
{
    int total_size = 0;

    if (my_strcmp((*father)->sort[0], "setenv") == 0) {
        register_input(father, "setenv");
        if ((*father)->ac == 1) return (0);
        if ((*father)->ac > 3) {
            my_putstr_fast_error("setenv: Too many arguments.\n");
            return (0);
        }
        total_size = my_strlen((*father)->input + 2);
        if (unvalid_setenv_val(father, my_env, node_env) == 1)
            return (0);
        *node_env = add_last(my_env, node_env, (*father)->sort[1]);
        if (*node_env != NULL)
            create_value_env(father, my_env, node_env, total_size);
        *node_env = (*my_env)->first;
        return (1);
    }
    return (0);
}

int compare_unsetenv_fth(global_list **father, list **my_env,
l_list **node_env)
{
    int total_size = 0;

    if (my_strcmp((*father)->sort[0], "unsetenv") == 0) {
        register_input(father, "unsetenv");
        if ((*father)->ac == 1) {
            my_putstr_fast_error("unsetenv: Too few arguments.\n");
            return (0);
        }
        if (unvalid_unsetenv_val(father, my_env, node_env) == 1)
            return (0);
        if ((*father)->ac != 2) return (0);
        if (*node_env == NULL)
            return (1);
        compare_unsetenv_fth_loop(father, my_env, node_env);
        *node_env = (*my_env)->first;
    }
    return (0);
}

int exec_input_father(global_list **father, list **my_env, l_list **node_env)
{
    if (compare_echo_dollar(father, my_env, node_env) == 1)
        return (1);
    if (compare_exit_fth(father, my_env, node_env) == 1)
        return (1);
    if (compare_cd_fth(father, my_env, node_env) == 1)
        return (1);
    if (compare_setenv_fth(father, my_env, node_env) == 1)
        return (1);
    if (compare_unsetenv_fth(father, my_env, node_env) == 1)
        return (1);
    return (0);
}