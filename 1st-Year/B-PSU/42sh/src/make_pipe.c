/*
** EPITECH PROJECT, 2021
** make_pipe
** File description:
** execute the commands with the pipes
*/

#include "include/my.h"

char *define_first_command(char *command, int nbr_of_pipes)
{
    int size = 0;
    char *first_command;
    int k = 0;

    for (int pipes_crossed = 0; pipes_crossed < nbr_of_pipes; k++) {
        if (command[k] == '|')
            pipes_crossed++;
    }
    k--;
    for (int i = 0; i < k; i++)
        size++;
    first_command = malloc(sizeof(char) * (size + 2));
    for (int i = 0; i < k; i++)
        first_command[i] = command[i];
    first_command[size] = '\n';
    first_command[size + 1] = '\0';
    return (first_command);
}

char *define_second_command(char *command, int nbr_of_pipes)
{
    int size = 0;
    char *second_command;
    int k = 0;

    for (int pipes_crossed = 0; pipes_crossed < nbr_of_pipes; k++) {
        if (command[k] == '|')
            pipes_crossed++;
    }
    for (int i = k; command[i]; i++)
        size++;
    second_command = malloc(sizeof(char) * (size + 1));
    for (int i = k, j = 0; command[i]; i++, j++)
        second_command[j] = command[i];
    second_command[size] = '\0';
    return (second_command);
}

int define_nbr_of_pipes(char *command)
{
    int nbr_of_pipes = 0;

    for (int i = 0; command[i]; i++) {
        if (command[i] == '|')
            nbr_of_pipes++;
    }
    return (nbr_of_pipes);
}

void make_pipe(char *command, storage_t *storage)
{
    int nbr_of_pipes = define_nbr_of_pipes(command);
    char *first_command = define_first_command(command, nbr_of_pipes);
    char *second_command = define_second_command(command, nbr_of_pipes);

    free(command);
    exec_pipe(first_command, second_command, storage);
    free(first_command);
    free(second_command);
}