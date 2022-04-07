/*
** EPITECH PROJECT, 2021
** simple left redirect
** File description:
** handle simple left redirection
*/

#include "include/my.h"

void null_redirect(char **inputs, char **inputs_with_redirect, char *command)
{
    my_puterr("Invalid null command.\n");
    free_dbtab(inputs);
    free_dbtab(inputs_with_redirect);
    free(command);
}

void no_file_error(char *file_path, char **inputs,
char **inputs_with_redirect, char *command)
{
    my_puterr(file_path);
    my_puterr(": No such file or directory.\n");
    free(file_path);
    free_dbtab(inputs);
    free_dbtab(inputs_with_redirect);
    free(command);
}

void directory_error(char **inputs, char *file_path,
char **inputs_with_redirect, char *command)
{
    int i = 0;

    for (; inputs[i]; i++)
        if (is_same_str(inputs[i], file_path))
            break;
    my_puterr(inputs[i + 1]);
    my_puterr(": 'standard input': read error: Is a directory\n0000000\n");
    free(file_path);
    free_dbtab(inputs);
    free_dbtab(inputs_with_redirect);
    free(command);
}

char *check_position_file_and_modify_command(char **inputs,
char *file_path, char *command, char **redirect_inputs)
{
    if (is_same_str(inputs[0], file_path) == 0)
        command = delete_file_path(command, file_path);
    else {
        command = add_cat_and_pipe(command, file_path);
        free(command);
    }
    free(file_path);
    free_dbtab(inputs);
    free_dbtab(redirect_inputs);
    return (command);
}

void simple_left_redirect(char *command, storage_t *storage)
{
    int fd = 0;
    char **inputs;
    char **redirect_inputs = define_inputs(my_strdup(command));
    char *file_path;
    DIR *dir;

    storage->status = 1;
    command = delete_first_redirect(command);
    if (set_str_nbr(inputs = define_inputs(my_strdup(command))) <= 1)
        return (null_redirect(inputs, redirect_inputs, command));
    file_path = find_file_to_redirect(redirect_inputs);
    if ((fd = open(file_path, O_RDONLY)) == -1)
        return (no_file_error(file_path, inputs, redirect_inputs, command));
    if (dir = opendir(file_path)) {
        closedir(dir);
        return (directory_error(inputs, file_path, redirect_inputs, command));
    } storage->status = 0;
    command = check_position_file_and_modify_command(inputs,
    file_path, command, redirect_inputs);
    execute_command(command, storage);
}