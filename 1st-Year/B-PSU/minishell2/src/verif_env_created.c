/*
** EPITECH PROJECT, 2021
** verif_env_created.c
** File description:
** minishell2
*/

#include "../include/minishell.h"

static void create_path(list **my_env, l_list **node_env)
{
    *node_env = add_to_list(my_env, node_env,
    "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin");
    (*my_env)->paths = my_str_to_word_array_separator_struct(
    "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin", ':', my_env);
}

static void create_pwd(list **my_env, l_list **node_env)
{
    char buff[500];

    (*my_env)->pwd = my_memset_char(500);
    getcwd(buff, 500);
    (*my_env)->pwd = my_strcpy((*my_env)->pwd, "PWD=");
    (*my_env)->pwd = my_strcat((*my_env)->pwd, buff);
    *node_env = add_to_list(my_env, node_env, (*my_env)->pwd);
}

static void create_home(list **my_env, l_list **node_env)
{
    (*my_env)->home = my_memset_char(10);
    (*my_env)->home = my_strcpy((*my_env)->home, "HOME=/home");
    *node_env = add_to_list(my_env, node_env, (*my_env)->home);
}

void verif_env_created(list **my_env, l_list **node_env)
{
    if ((*my_env)->path_create == 0)
        create_path(my_env, node_env);
    if ((*my_env)->pwd_create == 0)
        create_pwd(my_env, node_env);
    if ((*my_env)->home_create == 0)
        create_home(my_env, node_env);
}