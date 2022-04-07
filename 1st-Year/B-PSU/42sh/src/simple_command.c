/*
** EPITECH PROJECT, 2021
** simple command
** File description:
** execute a simple command
*/

#include "include/my.h"

void simple_command(char *command, storage_t *storage)
{
    char **inputs = define_inputs(command);

    inputs = aplly_alias(storage, inputs);
    if (storage->alias->alias_error == 1) {
        storage->status = 1;
        free_dbtab(inputs);
        return;
    }
    if (inputs) {
        find_builtins(inputs, storage);
        free_dbtab(inputs);
    }
    else storage->status = 139;
}