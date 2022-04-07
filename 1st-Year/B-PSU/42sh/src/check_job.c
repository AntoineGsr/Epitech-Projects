/*
** EPITECH PROJECT, 2021
** check job
** File description:
** check if the job is well-used
*/

#include "include/my.h"

int find_position_job(char *command)
{
    int k = 0;

    if (command[0] == '&' && command[1] != '&')
        return (0);
    for (k = 1; command[k]; k++)
        if (command[k] == '&' && command[k + 1] != '&' && command[k - 1] != '&')
            return (k);
    return (0);
}

void check_job(char *command, storage_t *storage)
{
    int k = find_position_job(command);

    for (int i = k + 1; command[i] && command[i] != '\n'; i++) {
        if (command[i] != ' ' && command[i] != '\t') {
            my_puterr("Badly placed &.\n");
            storage->status = 1;
            free(command);
            return;
        }
    }
    store_command(storage, command, k);
}