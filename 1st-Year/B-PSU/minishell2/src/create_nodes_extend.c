/*
** EPITECH PROJECT, 2021
** create_nodes_extend.c
** File description:
** minishell2
*/

#include "../include/minishell.h"

static int create_path_env(list **my_env, char **env, int i)
{
    (*my_env)->paths = my_str_to_word_array_separator_struct
    (*(env + i) + 5, ':', my_env);
    (*my_env)->path_create = 1;
    return (0);
}

static int create_home_env(list **my_env, char **env, int i)
{
    (*my_env)->home = my_memset_char(my_strlen(*(env + i)));
    (*my_env)->home = my_strcpy((*my_env)->home, *(env + i) + 5);
    (*my_env)->home_create = 1;
    return (0);
}

static int create_pwd_env(list **my_env, char **env, int i)
{
    (*my_env)->pwd = my_memset_char(my_strlen(*(env + i)));
    (*my_env)->pwd = my_strcpy((*my_env)->pwd, *(env + i) + 4);
    (*my_env)->pwd_create = 1;
    return (0);
}

int verif_env_major_var(list **my_env, char **env, int i)
{
    if (my_strncmp("PATH=", *(env + i), 5) == 0)
        return (create_path_env(my_env, env, i));
    if (my_strncmp("HOME=", *(env + i), 5) == 0)
        return (create_home_env(my_env, env, i));
    if (my_strncmp("PWD=", *(env + i), 4) == 0)
        return (create_pwd_env(my_env, env, i));
    return (0);
}