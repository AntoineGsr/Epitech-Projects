/*
** EPITECH PROJECT, 2021
** find_builtins
** File description:
** mysh
*/

#include "include/my.h"

int is_exe_file(char *file)
{
    struct stat st;

    if (stat(file, &st) == -1) {
        return (0);
    }
    if (S_ISDIR(st.st_mode) || access(file, X_OK) != 0) {
        return (0);
    }
    return (1);
}

int is_command_found(char **path, int i, char *command)
{
    DIR *dir;
    struct dirent *sd;
    int is = 0;

    dir = opendir(path[i]);
    if (dir)
        while ((sd = readdir(dir)) != NULL)
            if (is_same_str(sd->d_name, command)) {
                is = 1;
                break;
            }
    closedir(dir);
    return (is);
}

int is_bin_command(char *command, char **env)
{
    char **path;
    int paths_nbr = 0;
    int is = 0;

    if ((path = set_dirs(env)) == NULL)
        return (0);
    paths_nbr = set_str_nbr(path);
    for (int i = 0; i < paths_nbr && is == 0; i++) {
        if (is_command_found(path, i, command)) {
            is = 1;
        }
    }
    for (int i = 0; i < paths_nbr; i++)
        free(path[i]);
    free(path);
    return (is);
}

void unknown_command(char *command, storage_t *storage)
{
    struct stat st;

    storage->status = 1;
    if (stat(command, &st) == 0 && check_try_execute(command) == 1) {
        my_puterr(command);
        my_puterr(": Permission denied.\n");
        return;
    }
    my_puterr(command);
    my_puterr(": Command not found.\n");
}