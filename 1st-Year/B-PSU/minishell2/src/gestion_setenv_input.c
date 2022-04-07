/*
** EPITECH PROJECT, 2021
** gestion_setenv_input.c
** File description:
** minishell1
*/

#include "../include/minishell.h"

int unvalid_setenv_val(global_list **father, list **my_env, l_list **node_env)
{
    int k = 0;

    for (int i = 0; (*father)->sort[1][i] != '\0'; i++) {
        if (((*father)->sort[1][i] >= 48 && (*father)->sort[1][i] <= 58)
            || ((*father)->sort[1][i] >= 65 && (*father)->sort[1][i] <= 90)
            || ((*father)->sort[1][i] >= 97 && (*father)->sort[1][i] <= 122)) {
            k = 1;
        } else {
            my_putstr_fast_error("setenv: Variable name ");
            my_putstr_fast_error("must contain alphanumeric characters.\n");
            return (1);
        }
    }
    return (0);
}

int unvalid_unsetenv_val(global_list **father, list **my_env,
l_list **node_env)
{
    int k = 0;

    for (int i = 0; (*father)->sort[1][i] != '\0'; i++) {
        if (((*father)->sort[1][i] >= 48 && (*father)->sort[1][i] <= 58)
            || ((*father)->sort[1][i] >= 65 && (*father)->sort[1][i] <= 90)
            || ((*father)->sort[1][i] >= 97 && (*father)->sort[1][i] <= 122)) {
            k = 1;
        } else {
            my_putstr_fast_error("unsetenv: Variable name ");
            my_putstr_fast_error("must contain alphanumeric characters.\n");
            return (1);
        }
    }
    return (0);
}