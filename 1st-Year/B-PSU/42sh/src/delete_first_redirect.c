/*
** EPITECH PROJECT, 2021
** delete first redirect
** File description:
** delete first redirect
*/

#include "include/my.h"

char *delete_first_redirect(char *command)
{
    int len = my_strlen(command) - 1;
    char *new_command = malloc(sizeof(char) * (len + 1));
    int found = 0;

    for (int i = 0, j = 0; command[i]; i++, j++) {
        if (command[i] == '<' && found == 0) {
            i++;
            found = 1;
        }
        new_command[j] = command[i];
    }
    new_command[len] = '\0';
    free(command);
    return (new_command);
}