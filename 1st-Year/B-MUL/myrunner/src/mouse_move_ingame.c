/*
** EPITECH PROJECT, 2021
** mouse_move_ingame.c
** File description:
** my_runner
*/

#include "my_runner.h"

void mouse_move_game(sfEvent event, enum pages *state)
{
    *state = GAME;
    if (event.mouseMove.x >= 1852 && event.mouseMove.x <= 1899) {
        if (event.mouseMove.y >= 22 && event.mouseMove.y <= 68) {
            *state = PAUSE;
        }
    }
    if (event.mouseMove.x >= 1792 && event.mouseMove.x <= 1837) {
        if (event.mouseMove.y >= 22 && event.mouseMove.y <= 68) {
            *state = HOME;
        }
    }
}

void mouse_move_pause(sfEvent event, enum pages *state)
{
    *state = PAUSE_CLICK;
    if (event.mouseMove.x >= 696 && event.mouseMove.x <= 889) {
        if (event.mouseMove.y >= 248 && event.mouseMove.y <= 441)
            *state = RESUME;
        if (event.mouseMove.y >= 509 && event.mouseMove.y <= 702)
            *state = SOUND_EFFECT;
    }
    if (event.mouseMove.x >= 1023 && event.mouseMove.x <= 1217) {
        if (event.mouseMove.y >= 248 && event.mouseMove.y <= 441)
            *state = RESTART;
        if (event.mouseMove.y >= 509 && event.mouseMove.y <= 702)
            *state = MUSIC;
    }
    if (event.mouseMove.x >= 662 && event.mouseMove.x <= 1258) {
        if (event.mouseMove.y >= 767 && event.mouseMove.y <= 964)
            *state = EXIT;
    }
}