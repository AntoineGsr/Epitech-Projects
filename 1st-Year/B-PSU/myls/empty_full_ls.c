/*
** EPITECH PROJECT, 2020
** empty_full_ls.c
** File description:
** my_ls
*/

#include "my_ls.h"

char *empty_full_ls(char *full_ls, char *test, int *count)
{
    if (*count == 0)
        *count = 12;
    for (int j = 0; j < my_strlen(test); j++, *count = *count + 1)
        full_ls[*count] = test[j];
    full_ls[*count] = ' ';
    *count = *count + 1;
    return (full_ls);
}
