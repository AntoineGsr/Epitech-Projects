/*
** EPITECH PROJECT, 2021
** main
** File description:
** mysh
*/

#include "include/my.h"

static void free_local_var(storage_t *storage)
{
    local_var_t *tmp = storage->local_var;
    local_var_t *old = NULL;

    while (tmp->next != NULL) {
        old = tmp;
        free(tmp->var_name);
        free(tmp->content);
        tmp = tmp->next;
        free(old);
    }
    free(tmp);
}

void free_history(storage_t *storage)
{
    history_node_t *tmp;
    storage->history->history_ll = storage->history->history_ll_last_ptr;

    while (storage->history->history_ll->next != NULL) {
        tmp = storage->history->history_ll;
        storage->history->history_ll = storage->history->history_ll->next;
        free(tmp->command);
        free(tmp);
    }
    free(storage->history->history_ll);
    free(storage->history);
}

void free_alias(storage_t *storage)
{
    alias_node_t *tmp;
    storage->alias->alias_ll = storage->alias->alias_ll_last_ptr;

    while (storage->alias->alias_ll->next != NULL) {
        tmp = storage->alias->alias_ll;
        storage->alias->alias_ll = storage->alias->alias_ll->next;
        free(tmp->arg_one);
        free(tmp->arg_two);
        free(tmp);
    }
    free(storage->alias->alias_ll);
    free(storage->alias);
}

static void free_prompt(storage_t *storage)
{
    if (storage->prompt_color != NULL)
        free(storage->prompt_color);
    if (storage->prompt_text != NULL)
        free(storage->prompt_text);
}

void free_all(storage_t *storage)
{
    free_history(storage);
    free_alias(storage);
    free_dbtab(storage->env);
    free_local_var(storage);
    free(storage->oldpwd);
    free_list(storage->jobs);
    free_list(storage->commands);
    free_prompt(storage);
}