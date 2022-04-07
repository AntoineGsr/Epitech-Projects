/*
** EPITECH PROJECT, 2021
** redefine command
** File description:
** redefine the command
*/

#include "include/my.h"

int define_size_command(char *command, char *file_name, char c)
{
    int size = 0;
    int i = 0;

    while (command[i] != c) {
        i++;
        size++;
    }
    while (command[i] == ' ' || command[i] == '\t' || command[i] == c)
        i++;
    for (int j = 0; file_name[j]; j++, i++);
    while (command[i]) {
        size++;
        i++;
    }
    return (size);
}

char *redefine_command(char *command, char *file_name, char c)
{
    int size = define_size_command(command, file_name, c);
    char *new_command = malloc(sizeof(char) * (size + 2));
    int i = 0;
    int k = 0;

    for (; command[i] != c; i++, k++)
        new_command[k] = command[i];
    while (command[i] == ' ' || command[i] == '\t' || command[i] == c)
        i++;
    for (int j = 0; file_name[j]; j++, i++);
    for (; command[i]; i++, k++)
        new_command[k] = command[i];
    new_command[size] = '\n';
    new_command[size + 1] = '\0';
    free(command);
    return (new_command);
}