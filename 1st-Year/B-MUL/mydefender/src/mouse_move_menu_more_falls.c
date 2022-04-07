/*
** EPITECH PROJECT, 2021
** mouse_move_menu_more_falls.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void mouse_move_help_click(sfEvent event, enum pages *state)
{
    *state = HELP_CLICK;
    if (!((event.mouseMove.x >= 64 && event.mouseMove.x <= 448)
        && (event.mouseMove.y >= 240 && event.mouseMove.y <= 488))) {
        *state = HELP_OK;
    }
}

void mouse_move_vs_click(sfEvent event, enum pages *state)
{
    *state = VS_CLICK;
    if (event.mouseMove.x >= 156 && event.mouseMove.x <= 356) {
        if (event.mouseMove.y >= 433 && event.mouseMove.y <= 468)
            *state = VS_OK;
    }
}

void mouse_move_survival_click(sfEvent event, enum pages *state)
{
    *state = SURVIVAL_CLICK;
    if (event.mouseMove.x >= 156 && event.mouseMove.x <= 356) {
        if (event.mouseMove.y >= 433 && event.mouseMove.y <= 468)
            *state = SURVIVAL_OK;
    }
}

void mouse_move_options_click(sfEvent event, enum pages *state)
{
    *state = OPTIONS_CLICK;
    if (event.mouseMove.x >= 155 && event.mouseMove.x <= 357) {
        if (event.mouseMove.y >= 469 && event.mouseMove.y <= 505) {
            *state = OPTIONS_OK;
        }
    }
    if (event.mouseMove.x >= 276 && event.mouseMove.x <= 350) {
        if (event.mouseMove.y >= 318 && event.mouseMove.y <= 330) {
            *state = OPTIONS_MUSIC;
        }
        if (event.mouseMove.y >= 345 && event.mouseMove.y <= 355) {
            *state = OPTIONS_SOUND;
        }
    }
}

void mouse_move_puzzle_click(sfEvent event, enum pages *state)
{
    *state = PUZZLE_CLICK;
    if (event.mouseMove.x >= 156 && event.mouseMove.x <= 356) {
        if (event.mouseMove.y >= 433 && event.mouseMove.y <= 468)
            *state = PUZZLE_OK;
    }
}