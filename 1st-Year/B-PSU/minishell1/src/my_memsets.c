/*
** EPITECH PROJECT, 2021
** my_memset_char.c
** File description:
** antman
*/

#include "../include/minishell.h"

char **my_memset_dchar(int size1, int size2)
{
    char **str = malloc(sizeof(char *) * size1);

    for (int i = 0; i < size1; i++) {
        str[i] = my_memset_char(size2);
    }
    return (str);
}

char *my_memset_char(int size)
{
    char *str = malloc(sizeof(char) * size);

    for (int i = 0; i < size; i++)
        str[i] = '\0';
    return (str);
}