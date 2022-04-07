/*
** EPITECH PROJECT, 2021
** my_sh
** File description:
** mysh
*/

#include "../include/my.h"

static void init_local_var(storage_t *storage)
{
    storage->local_var = malloc(sizeof(local_var_t));
    storage->local_var->next = NULL;
    for (int i = 0; storage->env[i] != NULL; i++) {
        if (strncmp("TERM=", storage->env[i], 5) == 0)
            add_local_var(storage->env[i] + 5, "term", storage);
        if (strncmp("PATH=", storage->env[i], 5) == 0)
            add_local_var(storage->env[i] + 5, "path", storage);
        if (strncmp("USER=", storage->env[i], 5) == 0)
            add_local_var(storage->env[i] + 5, "user", storage);
    }
    add_local_var(storage->oldpwd, "cwd", storage);
    add_local_var("1", "ignoreeof", storage);
    storage->ignoreeof = 0;
}

static void init_alias(storage_t *storage)
{
    storage->alias = malloc(sizeof(alias_t));
    storage->alias->alias_ll = malloc(sizeof(alias_node_t));
    storage->alias->alias_ll->previous = NULL;
    storage->alias->alias_ll->next = NULL;
    storage->alias->alias_ll_first_ptr = storage->alias->alias_ll;
    storage->alias->alias_ll_last_ptr = storage->alias->alias_ll;
    storage->alias->total_alias_nbr = 0;
    storage->alias->alias_loop = 0;
    storage->alias->alias_error = 0;
}

static void init_history(storage_t *storage)
{
    storage->history = malloc(sizeof(history_t));
    storage->history->history_ll = malloc(sizeof(history_node_t));
    storage->history->history_ll->previous = NULL;
    storage->history->history_ll->next = NULL;
    storage->history->history_ll_first_ptr = storage->history->history_ll;
    storage->history->history_ll_last_ptr = storage->history->history_ll;
    storage->history->total_command_nbr = 0;
}

static void init_prompt(storage_t *storage)
{
    storage->prompt_change = 0;
    storage->prompt_color = NULL;
    storage->prompt_text = NULL;
}

void init_all(storage_t *storage)
{
    init_history(storage);
    init_alias(storage);
    init_local_var(storage);
    storage->jobs = NULL;
    storage->stored_nbr = 0;
    storage->commands = NULL;
    init_prompt(storage);
}