/*
** EPITECH PROJECT, 2021
** subshell
** File description:
** subshell
*/

#include "include/my.h"

void subshell_sh(storage_t *storage, char *line)
{
    storage->line = line;
    storage->history->history_ll = save_command_into_history(storage,
    line, storage->history->history_ll);
    if (my_strlen(line) > 1 && is_line_valid(line) &&
        are_quotations_valid(line, storage) &&
        are_parentheses_valid(line, storage) &&
        handle_variable(line, storage) != NULL) {
            line = handle_variable(line, storage);
            define_commands(line, storage);
    }
}

int subshell_main(char **env, char *line)
{
    storage_t storage = {NULL, 0, 0};

    storage.oldpwd = getcwd(NULL, 0);
    if ((storage.env = alloc_env(env, env)) == NULL)
        storage.env = alloc_env(env, env);
    init_all(&storage);
    subshell_sh(&storage, line);
    free_all(&storage);
    return (storage.status);
}