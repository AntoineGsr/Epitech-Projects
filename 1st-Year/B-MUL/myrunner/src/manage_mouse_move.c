/*
** EPITECH PROJECT, 2021
** manage_mouse_move.c
** File description:
** my_runner
*/

#include "my_runner.h"

void manage_mouse_move(sfEvent event, enum pages *state)
{
    if (*state > PRESS && *state < CTRL)
        mouse_move_menu(event, state);
    if (*state == CTRL || *state == CTRL_BCK)
        mouse_move_controls(event, state);
    if (*state >= STGS && *state <= STGS_MUSIC)
        mouse_move_settings(event, state);
    if (*state >= GAME && *state <= PAUSE)
        mouse_move_game(event, state);
    if (*state >= PAUSE_CLICK && *state <= EXIT)
        mouse_move_pause(event, state);
    if (*state >= GAMEWIN && *state <= W_END_QUIT)
        mouse_move_win(event, state);
    if (*state >= GAMEOVER && *state <= L_END_QUIT)
        mouse_move_over(event, state);
}