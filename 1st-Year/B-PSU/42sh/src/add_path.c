/*
** EPITECH PROJECT, 2021
** add_path
** File description:
** minishell1
*/

#include "include/my.h"

int read_directory(DIR *dir, char *command, int i)
{
    struct dirent *sd;

    while ((sd = readdir(dir)) != NULL) {
        if (is_same_str(sd->d_name, command)) {
            closedir(dir);
            return (i);
        }
    }
    closedir(dir);
    return (-1);
}

int find_path_pos(char *command, char **path)
{
    int paths_nbr = set_str_nbr(path);
    DIR *dir;

    for (int i = 0; i < paths_nbr; i++) {
        dir = opendir(path[i]);
        if (dir)
            if (read_directory(dir, command, i) != -1)
                return (i);
    }
    return (-1);
}

void free_path_line(char **path_line)
{
    int paths_nbr = set_str_nbr(path_line);

    for (int i = 0; i < paths_nbr; i++) {
        free(path_line[i]);
    }
    free(path_line);
}

char *add_path(char *command, char **env)
{
    char **path_line = set_dirs(env);
    int pos = find_path_pos(command, path_line);
    int len_path = my_strlen(path_line[pos]);
    int len_command = my_strlen(command);
    int len = len_path + len_command;
    char *n_command = malloc(sizeof(char) * (len + 2));
    int i = 0;

    if (!n_command)
        return (NULL);
    for (int j = 0; j < len_path; j++, i++) {
        n_command[i] = path_line[pos][j];
    } n_command[i] = '/';
    i++;
    for (int k = 0; k < len_command; k++, i++) {
        n_command[i] = command[k];
    }
    n_command[len + 1] = '\0';
    free_path_line(path_line);
    return (n_command);
}