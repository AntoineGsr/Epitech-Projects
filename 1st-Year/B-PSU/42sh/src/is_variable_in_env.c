/*
** EPITECH PROJECT, 2021
** is variable in env
** File description:
** check if the variable is in the env
*/

#include "include/my.h"

int is_same_variable(char *line, char *variable)
{
    int len_variable = my_strlen(variable);
    int len_line_variable = 0;

    for (int i = 0; line[i] != '=' && line[i]; i++)
        len_line_variable++;
    if (len_variable != len_line_variable)
        return (0);
    for (int i = 0; variable[i]; i++)
        if (line[i] != variable[i])
            return (0);
    return (1);
}

int is_variable_in_env(char **env, char *variable)
{
    for (int i = 0; env[i]; i++) {
        if (is_same_variable(env[i], variable))
            return (1);
    }
    return (0);
}