/*
** EPITECH PROJECT, 2021
** redirection_command
** File description:
** check if redirection is valid. If it is, execute redirection
*/

#include "include/my.h"

int are_three_redirect_in_a_row(char *command)
{
    int redirect_in_a_row = 1;
    int last_char_is_redirect = 0;

    for (int i = 0; command[i]; i++) {
        if ((command[i] == '>' || command[i] == '<') && last_char_is_redirect)
            redirect_in_a_row++;
        else
            redirect_in_a_row = 1;
        if (redirect_in_a_row >= 3)
            return (1);
        if (command[i] == '>' || command[i] == '<')
            last_char_is_redirect = 1;
        else
            last_char_is_redirect = 0;
    }
    return (0);
}

int is_missing_name_error(char *command)
{
    if (are_three_redirect_in_a_row(command))
        return (1);
    for (int i = 0; command[i]; i++)
        if (command[i] == '>' || command[i] == '<') {
            while (command[i] == '>' || command[i] == '<')
                i++;
            while (command[i] == ' ' || command[i] == '\t')
                i++;
            if (command[i] == '\0' || command[i] == '\n' ||
                command[i] == '>' || command[i] == '<')
                return (1);
        }
    return (0);
}

int is_ambiguous_output_error(char *command)
{
    int r_redirect = 0;
    int l_redirect = 0;
    char c = 0;

    for (int i = 0; command[i]; i++) {
        c = command[i];
        if ((c == '>' || c == '|') && r_redirect == 1)
            return (1);
        if (c == '<' && l_redirect == 1)
            return (1);
        if (c == '>')
            r_redirect = 1;
        if (c == '<')
            l_redirect = 1;
        if (r_redirect == 1 && c == '>')
            i++;
        if (l_redirect == 1 && c == '<')
            i++;
    }
    return (0);
}

int is_redirection_valid(char *command)
{
    if (is_missing_name_error(command))
        return (0);
    if (is_ambiguous_output_error(command))
        return (-1);
    return (1);
}

void redirection_command(char *command, storage_t *storage)
{
    int check_return = is_redirection_valid(command);

    if (check_return == 1) {
        make_redirection(command, storage);
        return;
    }
    storage->status = 1;
    if (check_return == 0)
        my_puterr("Missing name for redirect.\n");
    else
        my_puterr("Ambiguous output redirect.\n");
    free(command);
}