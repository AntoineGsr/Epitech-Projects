/*
** EPITECH PROJECT, 2021
** my_memset_char.c
** File description:
** antman
*/

#include "../include/antman.h"

char *my_memset_char(int size)
{
    char *str = malloc(sizeof(char) * size);

    for (int i = 0; i < size; i++)
        str[i] = '\0';
    return (str);
}