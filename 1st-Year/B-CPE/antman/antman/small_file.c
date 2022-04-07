/*
** EPITECH PROJECT, 2021
** small_file.c
** File description:
** antman
*/

#include "../include/antman.h"

int small_file(compression *antman)
{
    int opn = 0;
    int wrt = 0;

    if (my_strlen(antman->file) < 3) {
        opn = open(antman->av1, O_WRONLY | O_TRUNC);
        wrt = write(opn, antman->file, my_strlen(antman->file));
        close(opn);
        return (1);
    }
    return (0);
}
