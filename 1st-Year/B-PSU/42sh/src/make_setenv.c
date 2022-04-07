/*
** EPITECH PROJECT, 2021
** make_setenv
** File description:
** mysh
*/

#include "include/my.h"

char *set_env_arg(char **inputs, int str_nbr)
{
    char *tmp = my_strcat(inputs[1], "=");
    char *tmp_value;

    if (str_nbr == 1) {
        return (tmp);
    }
    tmp_value = my_strcat(tmp, inputs[2]);
    free(tmp);
    return (tmp_value);
}

int set_str_nbr(char **env)
{
    int len = 0;

    for (int i = 0; env[i]; i++) {
        len++;
    }
    return (len);
}

int does_begin_by_letter(char *arg)
{
    if ((arg[0] >= 65 && arg[0] <= 90) ||
        (arg[0] >= 97 && arg[0] <= 122) || arg[0] == '_') {
        return (1);
    }
    return (0);
}

int does_contain_alphanumeric_only(char *arg)
{
    for (int i = 0; arg[i]; i++) {
        if ((arg[i] < 'a' || arg[i] > 'z') && (arg[i] < 'A' || arg[i] > 'Z') &&
            (arg[i] < '0' || arg[i] > '9') && arg[i] != '_')
            return (0);
    }
    return (1);
}

void make_setenv(storage_t *storage, char **inputs)
{
    char *n_arg;
    int str_nbr = set_str_nbr(inputs) - 1;
    char *use_make_env[] = {"env", NULL};

    storage->status = 1;
    if (str_nbr > 2)
        return (my_puterr("setenv: Too many arguments.\n"));
    if (str_nbr == 0) {
        storage->status = 0;
        make_env(storage->env, use_make_env);
        return;
    }
    if (does_begin_by_letter(inputs[1]) == 0)
        return (my_puterr("setenv: Variable name must begin with a letter.\n"));
    if (does_contain_alphanumeric_only(inputs[1]) == 0)
        return (my_puterr("setenv: Variable name must contain "
        "alphanumeric characters.\n"));
    n_arg = set_env_arg(inputs, str_nbr);
    def_new_env(storage, inputs[1], n_arg);
    storage->status = 0;
}