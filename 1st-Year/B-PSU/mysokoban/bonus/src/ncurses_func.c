/*
** EPITECH PROJECT, 2021
** ncurses_func.c
** File description:
** sokoban
*/

#include "../include/sokoban.h"

void ncurses_activation(void)
{
    initscr();
    start_color();
    noecho();
    cbreak();
    erase();
    refresh();
}

void ncurses_desactivation(void)
{
    echo();
    nocbreak();
    endwin();
}