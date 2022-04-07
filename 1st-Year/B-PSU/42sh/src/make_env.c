/*
** EPITECH PROJECT, 2021
** make_env
** File description:
** mysh
*/

#include "include/my.h"

int make_env(char **env, char **inputs)
{
    if (set_str_nbr(inputs) > 1) {
        my_puterr("env: '");
        my_puterr(inputs[1]);
        my_puterr("': No such file or directory\n");
        return (127);
    }
    while (*env) {
        my_putstr(*env);
        my_putchar('\n');
        env++;
    }
    return (0);
}