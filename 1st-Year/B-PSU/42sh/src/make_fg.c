/*
** EPITECH PROJECT, 2021
** make fg
** File description:
** execute fg
*/

#include "include/my.h"

void make_fg(storage_t *storage)
{
    int len_list = length_list(storage->jobs);
    char *last_command;

    if (storage->stored_nbr == 0) {
        storage->status = 1;
        return (my_puterr("fg: No current job.\n"));
    }
    last_command = my_strdup(get_at(storage->jobs, len_list -1));
    storage->jobs = free_at(storage->jobs, len_list -1);
    storage->stored_nbr--;
    execute_command(last_command, storage);
}