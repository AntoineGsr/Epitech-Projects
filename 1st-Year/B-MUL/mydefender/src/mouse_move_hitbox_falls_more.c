/*
** EPITECH PROJECT, 2021
** mouse_move_hitbox_falls_more.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void mouse_move_hitbox_puzzle(sfEvent event, enum pages *state)
{
    if (event.mouseMove.x >= 29 && event.mouseMove.x <= 143) {
        if (event.mouseMove.y >= 413 && event.mouseMove.y <= 491)
            *state = PUZZLE;
    }
    if (event.mouseMove.x >= 34 && event.mouseMove.x <= 83) {
        if (event.mouseMove.y >= 484 && event.mouseMove.y <= 544)
            *state = PUZZLE;
    }
    if (event.mouseMove.x >= 96 && event.mouseMove.x <= 141) {
        if (event.mouseMove.y >= 485 && event.mouseMove.y <= 536)
            *state = PUZZLE;
    }
}

void mouse_move_hitbox_mini_games(sfEvent event, enum pages *state)
{
    if (event.mouseMove.x >= 209 && event.mouseMove.x <= 296) {
        if (event.mouseMove.y >= 433 && event.mouseMove.y <= 498)
            *state = MINI_GAMES;
    }
    if (event.mouseMove.x >= 193 && event.mouseMove.x <= 304) {
        if (event.mouseMove.y >= 498 && event.mouseMove.y <= 557)
            *state = MINI_GAMES;
    }
}

void mouse_move_hitbox_survival(sfEvent event, enum pages *state)
{
    if (event.mouseMove.x >= 336 && event.mouseMove.x <= 507) {
        if (event.mouseMove.y >= 462 && event.mouseMove.y <= 521)
            *state = SURVIVAL;
    }
    if (event.mouseMove.x >= 375 && event.mouseMove.x <= 452) {
        if (event.mouseMove.y >= 449 && event.mouseMove.y <= 463)
            *state = SURVIVAL;
    }
}

void mouse_move_menu_more(sfEvent event, enum pages *state)
{
    *state = MENU_MORE;
    mouse_move_hitbox_puzzle(event, state);
    mouse_move_hitbox_mini_games(event, state);
    mouse_move_hitbox_survival(event, state);
    if (event.mouseMove.x >= 84 && event.mouseMove.x <= 190) {
        if (event.mouseMove.y >= 603 && event.mouseMove.y <= 673)
            *state = VS;
    }
    if (event.mouseMove.x >= 31 && event.mouseMove.x <= 185) {
        if (event.mouseMove.y >= 715 && event.mouseMove.y <= 759)
            *state = OPTIONS;
    }
    if (event.mouseMove.x >= 211 && event.mouseMove.x <= 360) {
        if (event.mouseMove.y >= 714 && event.mouseMove.y <= 765)
            *state = HELP;
    }
    if (event.mouseMove.x >= 370 && event.mouseMove.x <= 505) {
        if (event.mouseMove.y >= 687 && event.mouseMove.y <= 747)
            *state = BACK;
    }
}