/*
** EPITECH PROJECT, 2021
** sig_handlers.c
** File description:
** minishell1
*/

#include "../include/minishell.h"

void handler_sigint(int sig)
{
    my_putstr_fast_zero("\n");
    print_prompt();
}

int verif_ctrl_d(global_list **father, int line_size)
{
    if (line_size == -1) {
        my_putstr_fast_zero("exit\n");
        (*father)->exit_null = 1;
        return (1);
    }
    return (0);
}