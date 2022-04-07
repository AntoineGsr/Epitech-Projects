/*
** EPITECH PROJECT, 2020
** convert_nb.c
** File description:
** navy
*/

#include "navy.h"

int convert_nb(char letter)
{
    int coord = 0;

    coord = letter % '1';
    if (coord > 7 || coord < 0)
        return (-1);
    return (coord);
}