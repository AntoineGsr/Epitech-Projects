/*
** EPITECH PROJECT, 2021
** display_map.c
** File description:
** mysokoban
*/

#include "../include/sokoban.h"

void bonus_color_display_ground(global *game, int i, int j)
{
    if (game->map[i][j] == '#') {
        init_pair(5, COLOR_RED, COLOR_RED);
        attron(COLOR_PAIR(5));
        mvprintw(i, j, "#");
        attroff(COLOR_PAIR(5));
    }
    if (game->map[i][j] == ' ') {
        init_pair(4, COLOR_WHITE, COLOR_WHITE);
        attron(COLOR_PAIR(4));
        mvprintw(i, j, " ");
        attroff(COLOR_PAIR(4));
    }
}

void bonus_color_display_entity(global *game, int i, int j)
{
    if (game->map[i][j] == 'O') {
        init_pair(1, COLOR_MAGENTA, COLOR_WHITE);
        attron(COLOR_PAIR(1));
        mvprintw(i, j, "O");
        attroff(COLOR_PAIR(1));
    }
    if (game->map[i][j] == 'X') {
        init_pair(2, COLOR_BLACK, COLOR_WHITE);
        attron(COLOR_PAIR(2));
        mvprintw(i, j, "X");
        attroff(COLOR_PAIR(2));
    }
    if (game->map[i][j] == 'P') {
        init_pair(3, COLOR_BLUE, COLOR_WHITE);
        attron(COLOR_PAIR(3));
        mvprintw(i, j, "P");
        attroff(COLOR_PAIR(3));
    }
}

void display_map(global *game)
{
    for (int i = 0; game->map[i] != NULL; i++) {
        for (int j = 0; game->map[i][j] != '\0'; j++) {
            bonus_color_display_ground(game, i, j);
            bonus_color_display_entity(game, i, j);
        }
    }
}
