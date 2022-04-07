/*
** EPITECH PROJECT, 2021
** store command
** File description:
** store the command (job)
*/

#include "include/my.h"

char *define_command_to_store(char *command, int k)
{
    int size = 0;
    char *command_to_store;

    for (int i = 0; i < k; i++)
        size++;
    if (size == 0) {
        free(command);
        return (NULL);
    }
    command_to_store = malloc(sizeof(char) * (size + 2));
    for (int i = 0; i < k; i++)
        command_to_store[i] = command[i];
    command_to_store[size] = '\n';
    command_to_store[size + 1] = '\0';
    free(command);
    return (command_to_store);
}

void store_command(storage_t *st, char *command, int k)
{
    char *command_to_store = define_command_to_store(command, k);

    if (!command_to_store)
        return;
    st->jobs = add_at(st->jobs, command_to_store, st->stored_nbr);
    st->stored_nbr++;
    printf("[%d]\n", st->stored_nbr);
}