/*
** EPITECH PROJECT, 2021
** is_pipe_correct
** File description:
** return 1 if pipe is well used. Else return 0.
*/

#include "include/my.h"

int are_three_pipes_in_a_row(char *command)
{
    int pipes_in_a_row = 1;
    int last_char_is_pipe = 0;

    for (int i = 0; command[i]; i++) {
        if (command[i] == '|' && last_char_is_pipe)
            pipes_in_a_row++;
        else
            pipes_in_a_row = 1;
        if (pipes_in_a_row >= 3)
            return (1);
        if (command[i] == '|')
            last_char_is_pipe = 1;
        else
            last_char_is_pipe = 0;
    }
    return (0);
}

int are_two_pipes_in_a_row(char *command)
{
    int pipes_in_a_row = 1;
    int last_char_is_pipe = 0;

    for (int i = 0; command[i]; i++) {
        if (command[i] == '|' && last_char_is_pipe)
            pipes_in_a_row++;
        else
            pipes_in_a_row = 1;
        if (pipes_in_a_row >= 2)
            return (i);
        if (command[i] == '|')
            last_char_is_pipe = 1;
        else
            last_char_is_pipe = 0;
    }
    return (0);
}

void redefine_command_and_restart(char *command, int k, storage_t *storage)
{
    int limit = k - 1;
    int size = 0;
    char *new_command;

    for (int i = 0; i < limit; i++)
        size++;
    new_command = malloc(sizeof(char) * (size + 2));
    for (int i = 0; i < limit; i++)
        new_command[i] = command[i];
    new_command[size] = '\n';
    new_command[size + 1] = '\0';
    free(command);
    execute_command(new_command, storage);
}

int is_pipe_correct(char *command, storage_t *storage)
{
    int k = 0;

    while (command[k] == ' ' || command[k] == '\t')
        k++;
    if (command[k] == '|')
        return (0);
    k = my_strlen(command) - 2;
    while (k >= 1 && (command[k] == ' ' ||
        command[k] == '\t' || command[k] == '\n'))
        k--;
    if (k == 0 || command[k] == '|')
        return (0);
    if (are_three_pipes_in_a_row(command))
        return (0);
    if (k = are_two_pipes_in_a_row(command)) {
        redefine_command_and_restart(command, k, storage);
        return (2);
    }
    return (1);
}