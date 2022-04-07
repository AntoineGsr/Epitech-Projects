/*
** EPITECH PROJECT, 2021
** mouse_click_home.c
** File description:
** my_runner
*/

#include "my_runner.h"

void mouse_click_home(enum pages *state, game_object ***sprite,
sfRenderWindow *window)
{
    if (*state == HOME) {
        *state = MENU;
        destroy_objects_game(sprite, window);
        *sprite = malloc(sizeof(game_object *) * 20);
        create_objects_game(sprite);
        create_music(sprite);
        sfRenderWindow_clear(window, sfBlack);
        restart_clocks(*sprite);
    }
}