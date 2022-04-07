/*
** EPITECH PROJECT, 2021
** tools
** File description:
** mysh
*/

#include "include/my.h"

void free_dbtab(char **dbtab)
{
    for (int i = 0; dbtab[i] != NULL; i++) {
        free(dbtab[i]);
    }
    free(dbtab);
}

int check_try_execute(char *command)
{
    if ((command[0] == '.' && command[1] == '/') || command[0] == '/') {
        return (1);
    }
    return (0);
}