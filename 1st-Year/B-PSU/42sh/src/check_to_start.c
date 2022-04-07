/*
** EPITECH PROJECT, 2021
** check to start
** File description:
** check if the command is correct. If it is, starts the process.
*/

#include "include/my.h"

void check_to_start(char *line, storage_t *storage)
{
    if (my_strlen(line) > 1 && is_line_valid(line) &&
        are_quotations_valid(line, storage) &&
        are_parentheses_valid(line, storage) &&
        handle_variable(line, storage) != NULL) {
            line = handle_variable(line, storage);
            define_commands(line, storage);
    }
}