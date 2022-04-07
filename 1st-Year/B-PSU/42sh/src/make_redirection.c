/*
** EPITECH PROJECT, 2021
** make_redirection
** File description:
** handle redirection
*/

#include "include/my.h"

int define_redirection(char *command)
{
    int right_redirect = 0;
    int left_redirect = 0;

    for (int i = 0; command[i]; i++) {
        if (command[i] == '>')
            right_redirect++;
        if (command[i] == '<')
            left_redirect++;
    }
    if (left_redirect == 2)
        return (-2);
    if (right_redirect == 1)
        return (1);
    if (right_redirect == 2)
        return (2);
    if (left_redirect == 1)
        return (-1);
    return (0);
}

void make_redirection(char *command, storage_t *storage)
{
    switch (define_redirection(command)) {
        case 1: simple_right_redirect(command, storage);
            break;
        case 2: double_right_redirect(command, storage);
            break;
        case -1: simple_left_redirect(command, storage);
            break;
        case -2: double_left_redirect(command, storage);
            break;
        default: break;
    }
}