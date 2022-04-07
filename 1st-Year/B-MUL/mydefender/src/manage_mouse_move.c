/*
** EPITECH PROJECT, 2021
** manage_mouse_move.c
** File description:
** my_defender
*/

#include "../include/my_defender.h"

void manage_mouse_move_all_menus(sfEvent event, enum pages *state,
game_object ***sprite)
{
    if (*state >= MENU && *state < MOVE_MORE)
        mouse_move_menu(event, state);
    if (*state >= MENU_MORE && *state < MOVE_MENU)
        mouse_move_menu_more(event, state);
    if (*state == PUZZLE_CLICK || *state == PUZZLE_OK)
        mouse_move_puzzle_click(event, state);
    if (*state >= MINI_GAMES_CLICK && *state <= MINI_GAMES_OK)
        mouse_move_minigames_click(event, state);
    if (*state >= OPTIONS_CLICK && *state <= OPTIONS_OK)
        mouse_move_options_click(event, state);
    if (*state == SURVIVAL_CLICK || *state == SURVIVAL_OK)
        mouse_move_survival_click(event, state);
    if (*state == VS_CLICK || *state == VS_OK)
        mouse_move_vs_click(event, state);
    if (*state == HELP_CLICK || *state == HELP_OK)
        mouse_move_help_click(event, state);
}

void manage_mouse_move_all_game(sfEvent event, enum pages *state,
game_object ***sprite)
{
    if (*state >= GAME && *state < GAME_MENU_CLICK)
        mouse_move_game(event, state, sprite);
    if (*state >= GAME_MENU_CLICK && *state < QUIT)
        mouse_move_pause(event, state, sprite);
}

void manage_mouse_move(sfEvent event, enum pages *state,
game_object ***sprite)
{
    (*sprite)[0]->mouse_pos =
    (sfVector2f){event.mouseMove.x, event.mouseMove.y};
    manage_mouse_move_all_menus(event, state, sprite);
    manage_mouse_move_all_game(event, state, sprite);
}