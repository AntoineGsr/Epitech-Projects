/*
** EPITECH PROJECT, 2021
** delete file path
** File description:
** delete the file path from the command
*/

#include "include/my.h"

int find_position_file_path(char *command, char *file_path)
{
    int k = -1;
    int j = 0;

    for (int i = 0; command[i]; i++, j = 0) {
        for (int n = i; file_path[j], command[n]; n++, j++)
            if (file_path[j] != command[n])
                break;
        if (file_path[j] == '\0') {
            k = i;
            break;
        }
    }
    return (k);
}

char *delete_file_path(char *command, char *file_path)
{
    int len = my_strlen(command) - my_strlen(file_path);
    char *new_command = malloc(sizeof(char) * (len + 1));
    int j = 0;
    int k = find_position_file_path(command, file_path);

    if (k == -1)
        return (command);
    for (j = 0; j < k; j++)
        new_command[j] = command[j];
    k = j;
    j += my_strlen(file_path);
    for (; command[j]; j++, k++)
        new_command[k] = command[j];
    new_command[len] = '\0';
    free(command);
    return (new_command);
}