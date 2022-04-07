/*
** EPITECH PROJECT, 2021
** def new env
** File description:
** add a line to the env or replace existant one
*/

#include "include/my.h"

int does_variable_already_exist(char *variable, char **env)
{
    for (int i = 0; env[i]; i++) {
        for (int j = 0; env[i][j]; j++) {
            if (env[i][j] == '=' && variable[j] == '\0')
                return (i);
            if (env[i][j] != variable[j])
                break;
        }
    }
    return (-1);
}

void add_a_line_to_env(storage_t *storage, char *n_arg)
{
    int len = set_str_nbr(storage->env);
    char **n_env = malloc(sizeof(char *) * (len + 2));
    int i = 0;

    if (!n_env) {
        my_puterr("Segmentation fault\n");
        return;
    }
    for (; storage->env[i]; i++)
        n_env[i] = my_strdup(storage->env[i]);
    n_env[i] = my_strdup(n_arg);
    n_env[i + 1] = NULL;
    for (int i = 0; i <= len; i++)
        free(storage->env[i]);
    free(storage->env);
    free(n_arg);
    storage->env = n_env;
}

void replace_a_line_of_env(storage_t *storage, char *n_arg, int line)
{
    free(storage->env[line]);
    storage->env[line] = my_strdup(n_arg);
    free(n_arg);
}

void def_new_env(storage_t *storage, char *variable, char *n_arg)
{
    int line = does_variable_already_exist(variable, storage->env);

    if (line == -1)
        add_a_line_to_env(storage, n_arg);
    else
        replace_a_line_of_env(storage, n_arg, line);
}