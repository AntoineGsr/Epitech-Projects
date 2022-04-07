/*
** EPITECH PROJECT, 2020
** matrix_size.c
** File description:
** 103cipher
*/

#include "103cipher.h"

int matrix_size(int ac, char **av)
{
    int size = my_strlen(av[2]);
    int i = 0;

    for (i; (i * i) < size; i++);
    return (i);
}