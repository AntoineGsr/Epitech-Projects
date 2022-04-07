/*
** EPITECH PROJECT, 2021
** destroy_all.c
** File description:
** sokoban
*/

#include "../include/sokoban.h"

void leave_game(global *game, list **list_o, l_list **node_o)
{
    ncurses_desactivation();
    destroy_struct(game);
    destroy_list(list_o, node_o);
}