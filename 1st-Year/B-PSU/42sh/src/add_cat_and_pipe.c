/*
** EPITECH PROJECT, 2021
** add cat and pipe
** File description:
** add cat and pipe to command for left redirect
*/

#include "include/my.h"

char *add_cat_and_pipe(char *command, char *file_path)
{
    int len = my_strlen(command) + 4 + 3;
    char *new_command = malloc(sizeof(char) * (len + 1));
    char *cat = "cat ";
    char *pipe = " | ";
    int k = 0;
    int i = 0;
    for (; cat[k]; k++)
        new_command[k] = cat[k];
    for (; command[i] == ' ' || command[i] == '\t'; i++, k++)
        new_command[k] = command[i];
    for (int j = 0; file_path[j]; j++, i++, k++)
        new_command[k] = file_path[j];
    for (int j = 0; pipe[j]; j++, k++)
        new_command[k] = pipe[j];
    for (; command[i] == ' ' || command[i] == '\t'; i++, k++)
        new_command[k] = command[i];
    for (; command[i]; i++, k++)
        new_command[k] = command[i];
    new_command[len] = '\0';
    return (new_command);
}