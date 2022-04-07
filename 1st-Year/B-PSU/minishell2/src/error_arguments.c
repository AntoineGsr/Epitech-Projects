/*
** EPITECH PROJECT, 2021
** error_arguments.c
** File description:
** minishell1
*/

#include "../include/minishell.h"

int error_arguments(global_list **father, char *str, int nb)
{
    int i = 0;
    int error = 0;

    (*father)->exit_child = 1;
    if ((*father)->ac > nb) {
        my_putstr_fast_error(str);
        return (1);
    }
    if (my_strncmp("exit", str, 3) == 0 && (*father)->ac == 2) {
        if ((*father)->sort[1][0] < '1' || (*father)->sort[1][0] > '9') {
            my_putstr_fast_error(str);
            return (1);
        }
    }
    (*father)->exit_child = 0;
    return (0);
}