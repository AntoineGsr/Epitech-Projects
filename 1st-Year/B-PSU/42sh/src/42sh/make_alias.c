/*
** EPITECH PROJECT, 2021
** add_path
** File description:
** minishell1
*/

#include "../../include/my.h"

void display_aliases(storage_t *storage, char **inputs)
{
    while (storage->alias->alias_ll->next != NULL) {
        printf("%s\t", storage->alias->alias_ll->arg_one);
        printf("%s\n", storage->alias->alias_ll->arg_two);
        storage->alias->alias_ll = storage->alias->alias_ll->next;
    } storage->alias->alias_ll = storage->alias->alias_ll_last_ptr;
}

void search_alias(storage_t *storage, char **inputs)
{
    while (storage->alias->alias_ll->next != NULL) {
        if (strcmp(storage->alias->alias_ll->arg_one, inputs[1]) == 0) {
            printf("%s\n", storage->alias->alias_ll->arg_two);
            return;
        }
        storage->alias->alias_ll = storage->alias->alias_ll->next;
    } storage->alias->alias_ll = storage->alias->alias_ll_last_ptr;
}

alias_node_t *add_alias(storage_t *storage, char **inputs,
alias_node_t *to_put)
{
    alias_node_t *tmp = malloc(sizeof(alias_node_t));
    tmp->arg_one = my_strdup(inputs[1]);
    tmp->arg_two = my_strdup(inputs[2]);
    storage->alias->total_alias_nbr++;
    tmp->next = to_put;
    tmp->previous = NULL;
    tmp->next->previous = tmp;
    storage->alias->alias_ll_last_ptr = tmp;
    return (tmp);
}

void set_alias(storage_t *storage, char **inputs)
{
    while (storage->alias->alias_ll->next != NULL) {
        if (strcmp(storage->alias->alias_ll->arg_one, inputs[1]) == 0) {
            free(storage->alias->alias_ll->arg_two);
            storage->alias->alias_ll->arg_two = my_strdup(inputs[2]);
            return;
        }
        storage->alias->alias_ll = storage->alias->alias_ll->next;
    } storage->alias->alias_ll = storage->alias->alias_ll_last_ptr;
    if (strcmp(inputs[1], "alias") == 0) {
        fprintf(stderr, "alias: Too dangerous to alias that.\n");
        storage->status = 1;
        return;
    }
    storage->alias->alias_ll = add_alias(storage, inputs,
    storage->alias->alias_ll);
}

void make_alias(char **inputs, storage_t *storage)
{
    char *concatenate;
    int str_nbr = set_str_nbr(inputs) - 1;
    if (str_nbr == 0) {
        display_aliases(storage, inputs);
    }
    if (str_nbr == 1) {
        search_alias(storage, inputs);
    }
    if (str_nbr >= 2) {
        if (str_nbr >= 3) {
            for (int i = 3; inputs[i] != NULL; i++) {
                concatenate = my_strcat(inputs[2], " ");
                free(inputs[2]);
                inputs[2] = my_strcat(concatenate, inputs[i]);
                free(concatenate);
            }
        }
        set_alias(storage, inputs);
    } storage->alias->alias_ll = storage->alias->alias_ll_last_ptr;
}