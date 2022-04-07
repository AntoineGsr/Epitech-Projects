/*
** EPITECH PROJECT, 2021
** define file name
** File description:
** define the name of a file when redirect
*/

#include "include/my.h"

char *define_file_name(char *command, char c)
{
    int i = 0;
    int size = 0;
    char *file_name;

    while (command[i] != c)
        i++;
    while (command[i] == c)
        i++;
    while (command[i] == ' ' || command[i] == '\t')
        i++;
    for (int k = i; command[k] && command[k] != '\n' &&
        command[k] != ' ' && command[k] != '\t'; k++)
        size++;
    file_name = malloc(sizeof(char) * (size + 1));
    for (int j = 0; j < size; j++, i++)
        file_name[j] = command[i];
    file_name[size] = '\0';
    return (file_name);
}