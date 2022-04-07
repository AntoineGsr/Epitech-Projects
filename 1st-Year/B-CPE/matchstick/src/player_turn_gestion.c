/*
** EPITECH PROJECT, 2021
** verif_turn_input.c
** File description:
** matchstick
*/

#include "../include/matchstick.h"

void verif_turn_player(global **data, int *turn)
{
    if (*turn == -1) {
        *turn += 1;
        (*data)->player_turn += 1;
        my_putstr("Your turn:\n");
    }
    (*data)->input[*turn] = NULL;
    if (*turn == 0) {
        my_putstr("Line: ");
    } else
        my_putstr("Matches: ");
}

int input_error(global **data, int turn)
{
    for (int i = 0; (*data)->input[turn][i] != '\n'
        && (*data)->input[turn][i] != '\0'; i++) {
        if ((*data)->input[turn][i] < '0' || (*data)->input[turn][i] > '9') {
            my_putstr("Error: invalid input (positive number expected\n");
            return (1);
        }
    }
    return (0);
}

int player_turn(global **data, int turn)
{
    if (my_getnbr((*data)->input[turn]) <= 0
        || my_getnbr((*data)->input[turn]) > (*data)->rows) {
        my_putstr("Error: this line is out of range\n");
        return (1);
    }
    (*data)->player_turn += 1;
    return (0);
}

int input_not_range(global **data, int turn)
{
    if (my_getnbr((*data)->input[turn]) > (*data)->pick_stick) {
        my_putstr("Error: you cannot remove more than ");
        my_putstr(my_getstr((*data)->pick_stick));
        my_putstr("matches per turn\n");
        return (1);
    }
    if (my_getnbr((*data)->input[turn]) <= 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (1);
    }
    if (my_getnbr((*data)->input[turn]) >
        (*data)->sticks_line[my_getnbr((*data)->input[0]) - 1]) {
        my_putstr("Error: not enough matches on this line\n");
        return (1);
    }
    (*data)->player_turn += 1;
    return (0);
}

void display_player_action(global **data, int turn)
{
    my_putstr("Player removed ");
    my_put_nbr(my_getnbr((*data)->input[1]));
    my_putstr(" match(es) from line ");
    my_put_nbr(my_getnbr((*data)->input[0]));
    my_putchar('\n');
    (*data)->sticks_line[my_getnbr((*data)->input[0]) - 1]
    -= my_getnbr((*data)->input[1]);
    (*data)->total_stick -= my_getnbr((*data)->input[turn]);
}