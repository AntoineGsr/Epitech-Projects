/*
** EPITECH PROJECT, 2021
** parenthese error
** File description:
** display error parenthese
*/

#include "include/my.h"

int parenthese_error(char *str, storage_t *storage, char *line)
{
    my_puterr(str);
    storage->status = 1;
    free(line);
    return (0);
}