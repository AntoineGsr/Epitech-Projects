/*
** EPITECH PROJECT, 2021
** compare_command.c
** File description:
** minishell1
*/

#include "../include/minishell.h"

char *path_cmd(global_list **father, list **my_env, int i)
{
    char *path = my_memset_char(300);

    path = my_strcat(path, (*my_env)->paths[i]);
    path = my_strcat(path, "/");
    path = my_strcat(path, (*father)->sort[0]);
    return (path);
}

int verif_exec_access(global_list **father, char *path)
{
    int error = 0;

    if (access(path, F_OK) == 0) {
        register_input(father, path);
        if (access(path, X_OK) != 0) {
            my_putstr_fast_error((*father)->sort[0]);
            my_putstr_fast_error(": Permission denied.\n");
            return (1);
        }
        error = execve(path, (*father)->sort, (*father)->env);
        return (1);
    }
    return (0);
}

int compare_cmd_system(global_list **father, list **my_env, l_list **node_env)
{
    char *path = NULL;
    int error = 0;
    int access_right = 0;

    if (((*father)->sort[0][0] == '.' && (*father)->sort[0][1] == '/')
        || (*father)->sort[0][0] == '/') {
        access_right = verif_exec_access(father, (*father)->sort[0]);
        if (access_right == 0)
            return (access_right);
        error = execve((*father)->sort[0], (*father)->sort, (*father)->env);
        return (1);
    }
    if (my_strcmp((*father)->input, "echo $?\n") == 0) return (1);
    for (int i = 0; i < (*my_env)->nb_path; i++) {
        path = path_cmd(father, my_env, i);
        access_right = verif_exec_access(father, path);
        if (access_right != 0) return (access_right);
        free(path);
    }
    return (0);
}

int compare_exit(global_list **father, list **my_env, l_list **node_env)
{
    if (my_strcmp((*father)->sort[0], "exit") == 0) {
        register_input(father, "exit");
        if (error_arguments(father, "exit: Expression Syntax.\n", 2) == 1)
            return (1);
        my_putstr_fast_zero("exit\n");
        return (1);
    }
    return (0);
}

int compare_env(global_list **father, list **my_env, l_list **node_env)
{
    if ((my_strcmp((*father)->sort[0], "env") == 0 ||
        my_strcmp((*father)->sort[0], "setenv") == 0) && (*father)->ac == 1) {
        register_input(father, "env");
        if ((*father)->ac != 1)
            return (0);
        display(*node_env);
        *node_env = (*my_env)->first;
        return (1);
    }
    return (0);
}