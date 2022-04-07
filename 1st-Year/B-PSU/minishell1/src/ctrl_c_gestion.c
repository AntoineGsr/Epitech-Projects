/*
** EPITECH PROJECT, 2021
** ctrl_c_gestion.c
** File description:
** minishell1
*/

#include "../include/minishell.h"

void able_unable_ctrl_c(int i, char **av, char **env)
{
    if (i == 0)
        execve("./src/ctrl_c_enable.sh", av, env);
    if (i == 1)
        execve("./src/ctrl_c_able.sh", av, env);
    exit(0);
}

void ctrl_c_gestion(int i, char **av, char **env)
{
    int child_pid = fork();

    switch(child_pid) {
        case -1: exit (84);
            break;
        case 0: able_unable_ctrl_c(i, av, env);
            break;
        default: while (wait(NULL) >= 0);
            break;
    }
}