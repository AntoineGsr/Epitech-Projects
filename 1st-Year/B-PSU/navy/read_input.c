/*
** EPITECH PROJECT, 2020
** read_input.c
** File description:
** navy
*/

#include "navy.h"

int read_input(list **player, struct sigaction sms)
{
    size_t len = 0;
    int line_size = 0;
    int signal = 0;

    (*player)->input_coord = NULL;
    line_size = getline(&(*player)->input_coord, &len, stdin);
    if (error_input((*player)->input_coord) != 0) {
        my_putstr("wrong position\n");
        return (-1);
    }
    return (0);
}