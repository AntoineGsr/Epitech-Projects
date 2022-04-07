/*
** EPITECH PROJECT, 2021
** separate command
** File description:
** separate the commands
*/

#include "include/my.h"

char *separate_first_command(char *command, char c)
{
    int len = 0;
    char *first_command;
    int parenthese = 0;

    for (int i = 0; command[i]; i++) {
        if (command[i] == '(')
            parenthese++;
        if (command[i] == ')')
            parenthese--;
        if (command[i] == c && command[i + 1] == c && parenthese <= 0)
            break;
        else
            len++;
    }
    first_command = malloc(sizeof(char) * (len + 2));
    for (int i = 0; i < len; i++)
        first_command[i] = command[i];
    first_command[len] = '\n';
    first_command[len + 1] = '\0';
    return (first_command);
}

char *separate_second_command(char *command, char c)
{
    int i = 0;
    int len_first_command = 0;
    int len = 0;
    char *second_command;
    int parenthese = 0;
    for (; command[i]; i++) {
        if (command[i] == '(')
            parenthese++;
        if (command[i] == ')')
            parenthese--;
        if (command[i] == c && command[i + 1] == c && parenthese <= 0)
            break;
        else
            len_first_command++;
    } i += 2;
    len = my_strlen(command) - len_first_command - 2;
    second_command = malloc(sizeof(char) * (len + 1));
    for (int j = 0; command[i]; i++, j++)
        second_command[j] = command[i];
    second_command[len] = '\0';
    return (second_command);
}

void handle_second_command(char *second_command, storage_t *storage, char c)
{
    if (c == '&') {
        if (storage->status == 0)
            execute_command(second_command, storage);
        else
            free(second_command);
    }
    if (c == '|') {
        if (storage->status != 0)
            execute_command(second_command, storage);
        else
            free(second_command);
    }
}

void separate_command(char *command, storage_t *storage, char c)
{
    char *first_command = separate_first_command(command, c);
    char *second_command = separate_second_command(command, c);

    free(command);
    if (my_strlen(first_command) > 1)
        execute_command(first_command, storage);
    else {
        storage->status = 0;
        free(first_command);
    }
    handle_second_command(second_command, storage, c);
}