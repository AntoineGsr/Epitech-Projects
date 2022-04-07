/*
** EPITECH PROJECT, 2021
** ai_turn_gestion.c
** File description:
** matchstick
*/

#include "../include/matchstick.h"

void calcul_sticks_row(global **data)
{
    for (int i = 0; i < (*data)->rows; i++) {
        if ((*data)->higher_line < (*data)->sticks_line[i]) {
            (*data)->higher_line = (*data)->sticks_line[i];
            (*data)->coord_higher_line = i;
        }
        if ((*data)->sticks_line[i] == 1)
            (*data)->row_equal_one += 1;
        if ((*data)->sticks_line[i] > 1)
            (*data)->row_upper_one += 1;
    }
}

int pick_higher_nb(global **data)
{
    if ((*data)->sticks_line[(*data)->coord_higher_line]
        > (*data)->pick_stick + 1 && (*data)->row_equal_one
        + (*data)->row_upper_one > 2) {
        (*data)->sticks_line[(*data)->coord_higher_line]
        -= (*data)->pick_stick;
        (*data)->total_stick -= (*data)->pick_stick;
        my_put_nbr((*data)->pick_stick);
        my_putstr(" match(es) from line ");
        my_put_nbr((*data)->coord_higher_line + 1);
        my_putchar('\n');
        return (1);
    }
    return (0);
}

int optimise_stick_pick(global **data)
{
    if ((*data)->row_equal_one == 1 && (*data)->row_upper_one == 1) {
        if ((*data)->sticks_line[(*data)->coord_higher_line]
            <= (*data)->pick_stick) {
            (*data)->total_stick -= (*data)->sticks_line
            [(*data)->coord_higher_line];
            my_put_nbr((*data)->sticks_line[(*data)->coord_higher_line]);
            my_putstr(" match(es) from line ");
            my_put_nbr((*data)->coord_higher_line + 1);
            my_putchar('\n');
            (*data)->sticks_line[(*data)->coord_higher_line] = 0;
            return (1);
        }
    }
    return (0);
}

int pick_one_stick(global **data)
{
    for (int i = 0; i < (*data)->rows; i++) {
        if ((*data)->sticks_line[i] > 1 || ((*data)->row_upper_one == 0
            && (*data)->sticks_line[i] == 1)) {
            (*data)->sticks_line[i] -= 1;
            (*data)->total_stick -= 1;
            my_putstr("1 match(es) from line ");
            my_put_nbr(i + 1);
            my_putchar('\n');
            return (1);
        }
    }
    return (0);
}