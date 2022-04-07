/*
** EPITECH PROJECT, 2021
** define subshell command
** File description:
** define the command between parentheses
*/

#include "include/my.h"

int find_position_left_parenthese(char *command)
{
    int k = 0;
    int quotation = 0;

    for (; command[k]; k++) {
        if (command[k] == '"')
            quotation = change_quotation_status(quotation);
        if (command[k] == ')' && quotation == 0)
            break;
    }
    for (; k >= 0; k--) {
        if (command[k] == '"')
            quotation = change_quotation_status(quotation);
        if (command[k] == '(' && quotation == 0)
            break;
    }
    return (k);
}

int define_size_subshell_command(char *command, int k)
{
    int size = 0;
    int quotation = 0;

    k += 1;
    for (; command[k]; k++) {
        if (command[k] == '"')
            quotation = change_quotation_status(quotation);
        if (command[k] == ')' && quotation == 0)
            break;
        size++;
    }
    return (size);
}

char *define_subshell_command(char *command)
{
    int k = find_position_left_parenthese(command);
    int size = define_size_subshell_command(command, k);
    char *subshell_command = malloc(sizeof(char) * (size + 2));

    k += 1;
    for (int i = 0; i < size; i++, k++)
        subshell_command[i] = command[k];
    subshell_command[size] = '\n';
    subshell_command[size + 1] = '\0';
    return (subshell_command);
}