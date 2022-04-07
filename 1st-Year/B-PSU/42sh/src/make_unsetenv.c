/*
** EPITECH PROJECT, 2021
** make_unsetenv
** File description:
** mysh
*/

#include "include/my.h"

char **redef_env(char **env, int k, int len_env)
{
    char **n_env = malloc(sizeof(char *) * len_env);
    int len_n_env = len_env - 1;
    int i = 0;
    int n = 0;

    if (!n_env) {
        my_puterr("Segmentation fault\n");
        return (env);
    }
    for (; i < k; i++, n++)
        n_env[n] = my_strdup(env[i]);
    i++;
    for (; n < len_n_env; i++, n++) {
        n_env[n] = my_strdup(env[i]);
    }
    n_env[n] = NULL;
    for (int j = 0; j <= len_env; j++) {
        free(env[j]);
    } free(env);
    return (n_env);
}

char **find_arg_and_delete(char *arg, char **env)
{
    int len = set_str_nbr(env);
    int i = 0;

    for (int j = 0; i < len; i++) {
        for (j = 0; arg[j] != '\0'; j++) {
            if (arg[j] != env[i][j]) {
                break;
            }
        }
        if (arg[j] == '\0') {
            break;
        }
    }
    if (env[i] == NULL) {
        return (env);
    }
    env = redef_env(env, i, len);
    return (env);
}

void make_unsetenv(storage_t *storage, char **inputs)
{
    char *n_arg;
    int str_nbr = set_str_nbr(inputs) - 1;

    if (str_nbr < 1) {
        storage->status = 1;
        my_puterr("unsetenv: Too few arguments.\n");
        return;
    }
    storage->env = find_arg_and_delete(inputs[1], storage->env);
}