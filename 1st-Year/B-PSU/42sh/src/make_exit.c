/*
** EPITECH PROJECT, 2021
** make_exit
** File description:
** mysh
*/

#include "include/my.h"

int leave_the_program(storage_t *storage, int exit_value)
{
    storage->exit = 1;
    return (exit_value);
}

int make_exit(char *command, char **inputs, storage_t *storage)
{
    int exit_value = 0;

    if (set_str_nbr(inputs) > 2) {
        my_puterr("exit: Expression Syntax.\n");
        return (1);
    }
    if (set_str_nbr(inputs) == 1) {
        return (leave_the_program(storage, 0));
    }
    for (int i = 0, len = my_strlen(inputs[1]); i < len; i++) {
        if (inputs[1][i] < '0' || inputs[1][i] > '9') {
            my_puterr("exit: Expression Syntax.\n");
            return (1);
        }
    }
    exit_value = my_getnbr(inputs[1]);
    return (leave_the_program(storage, exit_value));
}
