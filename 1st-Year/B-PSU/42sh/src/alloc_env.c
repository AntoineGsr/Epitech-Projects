/*
** EPITECH PROJECT, 2021
** alloc_env
** File description:
** mysh
*/

#include "include/my.h"

char **add_line_to_env(char **env, char *line)
{
    int lines_nbr = set_str_nbr(env);
    char **n_env = malloc(sizeof(char *) * (lines_nbr + 2));

    for (int i = 0; env[i]; i++)
        n_env[i] = my_strdup(env[i]);
    n_env[lines_nbr] = my_strdup(line);
    n_env[lines_nbr + 1] = NULL;
    free_dbtab(env);
    free(line);
    return (n_env);
}

char **check_path_pwd_home(char **a_env)
{
    char *path = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin";
    char *cur_path = getcwd(NULL, 0);

    if (is_variable_in_env(a_env, "PATH") == 0)
        a_env = add_line_to_env(a_env, my_strdup(path));
    if (is_variable_in_env(a_env, "PWD") == 0)
        a_env = add_line_to_env(a_env, my_strcat("PWD=", cur_path));
    if (is_variable_in_env(a_env, "OLDPWD") == 0)
        a_env = add_line_to_env(a_env, my_strcat("OLDPWD=", cur_path));
    if (is_variable_in_env(a_env, "HOME") == 0)
        a_env = add_line_to_env(a_env, my_strdup("HOME=/home/"));
    free(cur_path);
    return (a_env);
}

char **alloc_env(char **env, char **o_env)
{
    int len = 0;
    char **a_env;

    while (*env) {
        len++;
        env++;
    }
    if ((a_env = malloc(sizeof(char *) * (len + 1))) == NULL)
        return (NULL);
    for (int i = 0; i <= len; i++, o_env++) {
        if (i == len)
            a_env[i] = NULL;
        else
            a_env[i] = my_strdup(*o_env);
    }
    a_env = check_path_pwd_home(a_env);
    return (a_env);
}