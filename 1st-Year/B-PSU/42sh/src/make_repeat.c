/*
** EPITECH PROJECT, 2021
** make repeat
** File description:
** execute the repeat command
*/

#include "include/my.h"

int is_there_an_error(char **inputs, storage_t *storage)
{
    if (set_str_nbr(inputs) < 3) {
        storage->status = 1;
        my_puterr("repeat: Too few arguments.\n");
        return (1);
    }
    for (int i = 0; inputs[1][i]; i++) {
        if (inputs[1][i] != '-' && (inputs[1][i] < '0' || inputs[1][i] > '9')) {
            storage->status = 1;
            my_puterr("repeat: Badly formed number.\n");
            return (1);
        }
    }
    return (0);
}

char **move_inputs(char **inputs)
{
    int nbr_of_inputs = set_str_nbr(inputs) - 2;
    char **n_inputs = malloc(sizeof(char *) * (nbr_of_inputs + 1));

    for (int i = 2, j = 0; inputs[i]; i++, j++) {
        n_inputs[j] = my_strdup(inputs[i]);
    }
    n_inputs[nbr_of_inputs] = NULL;
    return (n_inputs);
}

void make_repeat(char **inputs, storage_t *storage)
{
    int nbr_of_repeat = 0;
    char **n_inputs;

    if (is_there_an_error(inputs, storage))
        return;
    nbr_of_repeat = atoi(inputs[1]);
    if (nbr_of_repeat <= 0)
        return;
    n_inputs = move_inputs(inputs);
    while (nbr_of_repeat > 0) {
        find_builtins(n_inputs, storage);
        nbr_of_repeat--;
    }
    free_dbtab(n_inputs);
}