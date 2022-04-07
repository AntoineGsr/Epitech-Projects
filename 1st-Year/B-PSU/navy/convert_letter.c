/*
** EPITECH PROJECT, 2020
** convert_letter.c
** File description:
** navy
*/

#include "navy.h"

int convert_letter(char letter)
{
    int coord = 0;

    coord = letter % 'A';
    if (coord > 7 || coord < 0)
        return (-1);
    return (coord);
}