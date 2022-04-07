/*
** EPITECH PROJECT, 2021
** up_down_gestion.c
** File description:
** sokoban
*/

#include "../include/sokoban.h"

int up_down_move_box(global **game, int stock_x, int stock_y, int val)
{
    int vald = 2 * val;

    if ((*game)->map[stock_x + val][stock_y] == 'X') {
        if ((*game)->map[stock_x + vald][stock_y] == 'X'
            || (*game)->map[stock_x + vald][stock_y] == '#') {
            (*game)->map[stock_x][stock_y] = 'P';
            return (1);
        }
        if ((*game)->map[stock_x + vald][stock_y] == ' '
            || (*game)->map[stock_x + vald][stock_y] == 'O') {
            (*game)->box_move = (*game)->map[stock_x + vald][stock_y];
            (*game)->map[stock_x + vald][stock_y] = 'X';
            check_loose(game, stock_x + vald, stock_y);
        }
    }
    return (0);
}

int up_down(global **game, int stock_x, int stock_y, int val)
{
    if ((*game)->map[stock_x + val][stock_y] != '#') {
        if (up_down_move_box(game, stock_x, stock_y, val) == 1) return (1);
        if ((*game)->box_move == 'O')
            (*game)->nb_o -= 1;
        (*game)->pos_xp += val;
        (*game)->action += 1;
        (*game)->previous_case = (*game)->map[(*game)->pos_xp][stock_y];
    }
    (*game)->map[(*game)->pos_xp][(*game)->pos_yp] = 'P';
    return (0);
}

int right_left_move_box(global **game, int stock_x, int stock_y, int val)
{
    int vald = 2 * val;

    if ((*game)->map[stock_x][stock_y + val] == 'X') {
        if ((*game)->map[stock_x][stock_y + vald] == 'X'
            || (*game)->map[stock_x][stock_y + vald] == '#') {
            (*game)->map[stock_x][stock_y] = 'P';
            return (1);
        }
        if ((*game)->map[stock_x][stock_y + vald] == ' '
            || (*game)->map[stock_x][stock_y + vald] == 'O') {
            (*game)->box_move = (*game)->map[stock_x][stock_y + vald];
            (*game)->map[stock_x][stock_y + vald] = 'X';
            check_loose(game, stock_x, stock_y + vald);
        }
    }
    return (0);
}

int right_left(global **game, int stock_x, int stock_y, int val)
{
    if ((*game)->map[stock_x][stock_y + val] != '#') {
        if (right_left_move_box(game, stock_x, stock_y, val) == 1) return (1);
        if ((*game)->box_move == 'O')
            (*game)->nb_o -= 1;
        (*game)->pos_yp += val;
        (*game)->action += 1;
        (*game)->previous_case = (*game)->map[stock_x][(*game)->pos_yp];
    }
    (*game)->map[(*game)->pos_xp][(*game)->pos_yp] = 'P';
    return (0);
}