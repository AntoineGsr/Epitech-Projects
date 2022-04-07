/*
** EPITECH PROJECT, 2021
** mouse_move_first_menu.c
** File description:
** my_runner
*/

#include "my_runner.h"

void mouse_move_menu(sfEvent event, enum pages *state)
{
    *state = MENU;
    if (event.mouseMove.x >= 664 && event.mouseMove.x <= 1258) {
        if (event.mouseMove.y >= 119 && event.mouseMove.y <= 312)
            *state = START;
        if (event.mouseMove.y >= 335 && event.mouseMove.y <= 529)
            *state = CONTROLS;
        if (event.mouseMove.y >= 554 && event.mouseMove.y <= 747)
            *state = SETTINGS;
        if (event.mouseMove.y >= 767 && event.mouseMove.y <= 965)
            *state = QUIT;
    }
}

void mouse_move_controls(sfEvent event, enum pages *state)
{
    if (event.mouseMove.x >= 664 && event.mouseMove.x <= 1258) {
        if (event.mouseMove.y >= 767 && event.mouseMove.y <= 965) {
            *state = CTRL_BCK;
        } else
            *state = CTRL;
    } else
        *state = CTRL;
}

void mouse_move_settings(sfEvent event, enum pages *state)
{
    *state = STGS;
    if (event.mouseMove.x >= 664 && event.mouseMove.x <= 1258) {
        if (event.mouseMove.y >= 767 && event.mouseMove.y <= 965)
            *state = STGS_BCK;
    }
    if (event.mouseMove.x >= 852 && event.mouseMove.x <= 1047) {
        if (event.mouseMove.y >= 247 && event.mouseMove.y <= 442)
            *state = STGS_8D;
    }
    if (event.mouseMove.x >= 696 && event.mouseMove.x <= 890) {
        if (event.mouseMove.y >= 508 && event.mouseMove.y <= 701)
            *state = STGS_SOUND;
    }
    if (event.mouseMove.x >= 1024 && event.mouseMove.x <= 1218) {
        if (event.mouseMove.y >= 508 && event.mouseMove.y <= 701)
            *state = STGS_MUSIC;
    }
}