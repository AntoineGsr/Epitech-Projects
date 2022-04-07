/*
** EPITECH PROJECT, 2021
** is command a job
** File description:
** check if the command is a job
*/

#include "include/my.h"

int is_command_a_job(char *command)
{
    if (command[0] == '&' && command[1] != '&')
        return (1);
    for (int i = 1; command[i]; i++) {
        if (command[i] == '&' && command[i + 1] != '&' && command[i - 1] != '&')
            return (1);
    }
    return (0);
}