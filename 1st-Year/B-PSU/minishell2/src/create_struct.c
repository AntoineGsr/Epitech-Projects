/*
** EPITECH PROJECT, 2021
** create_struct.c
** File description:
** minishell1
*/

#include "../include/minishell.h"

list *create_env(char **av, char **env)
{
    list *gbl = malloc(sizeof(list));

    if (gbl == NULL)
        return NULL;
    gbl->first = NULL;
    gbl->last = NULL;
    gbl->pwd = NULL;
    gbl->total_env = 0;
    gbl->pwd_create = 0;
    gbl->home_create = 0;
    gbl->path_create = 0;
    return (gbl);
}

global_list *create_father(char **av, char **env)
{
    global_list *gbl = malloc(sizeof(global_list));

    if (gbl == NULL) return NULL;
    gbl->input = NULL;
    gbl->input_sort = NULL;
    gbl->sort = NULL;
    gbl->input_modif = NULL;
    gbl->history = NULL;
    gbl->ac = 0;
    gbl->pid = getpid();
    gbl->child_pid = 0;
    gbl->exit = 0;
    gbl->exit_null = 0;
    gbl->exit_child = 0;
    gbl->old_cd = 0;
    gbl->env = NULL;
    gbl->memory_pwd = NULL;
    gbl->oldpwd = NULL;
    gbl->step = 0;
    return (gbl);
}