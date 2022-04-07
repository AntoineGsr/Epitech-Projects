/*
** EPITECH PROJECT, 2021
** pipe command
** File description:
** execute a pipe command
*/

#include "include/my.h"

void pipe_command(char *command, storage_t *storage)
{
    int check_return = is_pipe_correct(command, storage);

    if (check_return == 1) {
        make_pipe(command, storage);
    }
    else if (check_return == 0) {
        storage->status = 1;
        my_puterr("Invalid null command.\n");
        free(command);
    }
}