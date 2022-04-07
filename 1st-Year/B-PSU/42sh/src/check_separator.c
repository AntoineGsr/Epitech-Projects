/*
** EPITECH PROJECT, 2021
** separate command
** File description:
** check if there is not error with the separator
*/

#include "include/my.h"

int are_there_three_separators_in_a_row(char *command, char c)
{
    int separators = 0;

    for (int i = 0; command[i]; i++) {
        if (command[i] == c)
            separators++;
        else if (command[i] != ' ' && command[i] != '\t')
            separators = 0;
        if (separators > 2)
            return (1);
    }
    return (0);
}

int does_command_ends_by_separator(char *command, char c)
{
    int separator = 0;

    for (int i = 1; command[i]; i++) {
        if (command[i] == c && command[i - 1] == c)
            separator = 1;
        else
            separator = 0;
        if (separator && (command[i + 1] == '\n' || command[i + 1] == '\0'))
            return (1);
    }
    return (0);
}

int is_valid_separator_command(char *command, char c)
{
    int i = 0;

    while (command[i] == ' ' || command[i] == '\t')
        i++;
    if (command[i] == '|')
        return (0);
    if (are_there_three_separators_in_a_row(command, c))
        return (0);
    if (does_command_ends_by_separator(command, c))
        return (0);
    return (1);
}

void check_separator(char *command, storage_t *storage, char c)
{
    if (is_valid_separator_command(command, c)) {
        separate_command(command, storage, c);
    }
    else {
        storage->status = 1;
        my_puterr("Invalid null command.\n");
        free(command);
    }
}