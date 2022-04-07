/*
** EPITECH PROJECT, 2021
** mouse_move_endgame.c
** File description:
** my_runner
*/

#include "my_runner.h"

void mouse_move_win(sfEvent event, enum pages *state)
{
    *state = GAMEWIN;
    if (event.mouseMove.x >= 664 && event.mouseMove.x <= 1258) {
        if (event.mouseMove.y >= 335 && event.mouseMove.y <= 529)
            *state = W_END_MENU;
        if (event.mouseMove.y >= 554 && event.mouseMove.y <= 747)
            *state = W_END_NEW_GAME;
        if (event.mouseMove.y >= 767 && event.mouseMove.y <= 965)
            *state = W_END_QUIT;
    }
}

void mouse_move_over(sfEvent event, enum pages *state)
{
    *state = GAMEOVER;
    if (event.mouseMove.x >= 664 && event.mouseMove.x <= 1258) {
        if (event.mouseMove.y >= 335 && event.mouseMove.y <= 529)
            *state = L_END_MENU;
        if (event.mouseMove.y >= 554 && event.mouseMove.y <= 747)
            *state = L_END_NEW_GAME;
        if (event.mouseMove.y >= 767 && event.mouseMove.y <= 965)
            *state = L_END_QUIT;
    }
}