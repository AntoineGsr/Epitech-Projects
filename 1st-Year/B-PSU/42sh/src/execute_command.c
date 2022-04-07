/*
** EPITECH PROJECT, 2021
** execute_command
** File description:
** execute the command in argument
*/

#include "include/my.h"

int is_a_pipe(char *command)
{
    int quotation = 0;
    int parenthese = 0;

    for (int i = 0; command[i]; i++) {
        if (command[i] == '"' && quotation == 0)
            quotation = 1;
        else if (command[i] == '"' && quotation == 1)
            quotation = 0;
        if (command[i] == '(')
            parenthese++;
        if (command[i] == ')')
            parenthese--;
        if (command[i] == '|' && quotation == 0 && parenthese <= 0)
            return (1);
    }
    return (0);
}

int is_a_redirection(char *command)
{
    int quotation = 0;
    int parenthese = 0;

    for (int i = 0; command[i]; i++) {
        if (command[i] == '"' && quotation == 0)
            quotation = 1;
        else if (command[i] == '"' && quotation == 1)
            quotation = 0;
        if (command[i] == '(')
            parenthese++;
        if (command[i] == ')')
            parenthese--;
        if ((command[i] == '>' || command[i] == '<') &&
            quotation == 0 && parenthese <= 0)
            return (1);
    }
    return (0);
}

int is_there_a_separator(char *command)
{
    int quotation = 0;
    int parenthese = 0;

    for (int i = 0; command[i]; i++) {
        if (command[i] == '"' && quotation == 0)
            quotation = 1;
        else if (command[i] == '"' && quotation == 1)
            quotation = 0;
        if (command[i] == '(')
            parenthese++;
        if (command[i] == ')')
            parenthese--;
        if (command[i] == '&' && command[i + 1] == '&' &&
            quotation == 0 && parenthese <= 0)
            return ('&');
        if (command[i] == '|' && command[i + 1] == '|' &&
            quotation == 0 && parenthese <= 0)
            return ('|');
    }
    return (0);
}

int is_there_a_parenthese(char *command)
{
    int quotation = 0;

    for (int i = 0; command[i]; i++) {
        if (command[i] == '"' && quotation == 0)
            quotation = 1;
        else if (command[i] == '"' && quotation == 1)
            quotation = 0;
        if (command[i] == '(' && quotation == 0)
            return (1);
    }
    return (0);
}

void execute_command(char *command, storage_t *storage)
{
    char ascii = 0;

    if (is_command_a_job(command))
        return (check_job(command, storage));
    if (ascii = is_there_a_separator(command))
        return (check_separator(command, storage, ascii));
    if (is_a_redirection(command))
        return (redirection_command(command, storage));
    if (is_a_pipe(command) && my_strlen(command) > 0)
        pipe_command(command, storage);
    else if (is_there_a_parenthese(command))
        execute_subshell(command, storage);
    else
        simple_command(command, storage);
}