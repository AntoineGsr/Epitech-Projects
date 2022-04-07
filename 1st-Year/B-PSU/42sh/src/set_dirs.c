/*
** EPITECH PROJECT, 2021
** set_dirs
** File description:
** minishell1
*/

#include "include/my.h"

int find_path_str(char **env)
{
    int len = set_str_nbr(env);
    char *path = "PATH=";

    for (int i = 0, j = 0; i < len; i++) {
        for (j = 0; j < 5; j++) {
            if (env[i][j] != path[j]) {
                break;
            }
        }
        if (j == 5) {
            return (i);
        }
    }
    return (-1);
}

int count_paths_nbr(char *str)
{
    int paths_nbr = 1;

    if (my_strlen(str) <= 5)
        return (0);
    for (int i = 5; str[i] != '\0'; i++) {
        if (str[i] == ':') {
            paths_nbr++;
        }
    }
    return (paths_nbr);
}

int *set_sizes(char *str, int paths_nbr)
{
    int *sizes = malloc(sizeof(int) * paths_nbr);

    if (!sizes)
        return (NULL);
    for (int i = 0, s = 0, j = 5; i < paths_nbr; i++) {
        for (; str[j] != ':' && str[j] != '\0'; j++) {
            s++;
        }
        sizes[i] = s;
        s = 0;
        j++;
    }
    return (sizes);
}

char **set_dirs(char **env)
{
    int k = find_path_str(env);
    int paths_nbr = 0;
    int *sizes;
    char **path;
    if (k == -1)
        return (NULL);
    paths_nbr = count_paths_nbr(env[k]);
    if ((sizes = set_sizes(env[k], paths_nbr)) == NULL ||
        (path = malloc(sizeof(char *) * (paths_nbr + 1))) == NULL)
        return (NULL);
    for (int i = 0, j = 5, n = 0; i < paths_nbr; i++) {
        if ((path[i] = malloc(sizeof(char **) * (sizes[i] + 1))) == NULL)
            return (NULL);
        for (n = 0; env[k][j] != ':' && env[k][j] != '\0'; j++, n++)
            path[i][n] = env[k][j];
        path[i][n] = '\0';
        j++;
    }
    path[paths_nbr] = NULL;
    free(sizes);
    return (path);
}