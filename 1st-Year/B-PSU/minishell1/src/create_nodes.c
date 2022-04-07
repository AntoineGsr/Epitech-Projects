/*
** EPITECH PROJECT, 2021
** create_nodes.c
** File description:
** minishell1
*/

#include "../include/minishell.h"

int count_separator(char *av, char sep)
{
    int count = 2;

    if (av == NULL) return (0);
    for (int i = 0; av[i] != '\0'; i++) {
        if (av[i] == sep)
            count++;
    }
    return (count);
}

char **my_str_to_word_array_separator(char *av, char sep, list **my_env)
{
    char **arg = NULL;
    int k = 0;
    int l = 0;
    int count = count_separator(av, sep);

    if (count - 2 >= my_strlen(av) - 1) return NULL;
    arg = my_memset_dchar(count, my_strlen(av) - count + 3);
    for (int j = 0; av[j] != '\0'; j++) {
        if (av[j] != sep) {
            arg[k][l] = av[j];
            l++;
        } else if (arg[k][0] != '\0') {
            arg[k][l] = '\0';
            k++;
            l = 0;
        }
    }
    arg[count - 1] = NULL;
    (*my_env)->nb_path = count - 1;
    return (arg);
}

void create_nodes(list **my_env, l_list **node_env, char **env)
{
    for (int i = 0; env != NULL && *(env + i) != 0; i++) {
        *node_env = add_to_list(my_env, node_env, *(env + i));
        if (my_strncmp("PATH=", *(env + i), 5) == 0)
            (*my_env)->paths = my_str_to_word_array_separator
            (*(env + i) + 5, ':', my_env);
        if (my_strncmp("HOME=", *(env + i), 5) == 0) {
            (*my_env)->home = my_memset_char(my_strlen(*(env + i)));
            (*my_env)->home = my_strcpy((*my_env)->home, *(env + i) + 5);
        }
    }
    *node_env = (*my_env)->first;
}

void create_shell(global_list **father, list **my_env,
l_list **node_env, char **env)
{
    create_nodes(my_env, node_env, env);
    (*father)->env = malloc(sizeof(char *) * ((*my_env)->total_env + 1));
    create_array_env(father, my_env, node_env);
}