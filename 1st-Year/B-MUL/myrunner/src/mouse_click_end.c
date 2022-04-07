/*
** EPITECH PROJECT, 2021
** mouse_click_end.c
** File description:
** my_runner
*/

#include "my_runner.h"

void restart_game(game_object ***sprite, sfRenderWindow *window)
{
    destroy_objects_game(sprite, window);
    *sprite = malloc(sizeof(game_object *) * 20);
    create_objects_game(sprite);
    create_music(sprite);
    sfRenderWindow_clear(window, sfBlack);
    restart_clocks(*sprite);
}

void mouse_click_end(enum pages *state, game_object ***sprite,
sfRenderWindow *window)
{
    if (*state == W_END_MENU || *state == L_END_MENU) {
        *state = MENU;
        restart_game(sprite, window);
    }
    if (*state == W_END_NEW_GAME || *state == L_END_NEW_GAME) {
        *state = GAME;
        restart_game(sprite, window);
        (*sprite)[16]->restart_press = 1;
    }
    if (*state == W_END_QUIT || *state == L_END_QUIT)
        sfRenderWindow_close(window);
}