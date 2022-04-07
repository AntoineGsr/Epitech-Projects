/*
** EPITECH PROJECT, 2021
** mouse_click_pause.c
** File description:
** my_runner
*/

#include "my_runner.h"

void mouse_click_restart(enum pages *state, game_object ***sprite,
sfRenderWindow *window)
{
    destroy_objects_game(sprite, window);
    *sprite = malloc(sizeof(game_object *) * 20);
    create_objects_game(sprite);
    create_music(sprite);
    sfRenderWindow_clear(window, sfBlack);
    restart_clocks(*sprite);
    (*sprite)[16]->restart_press = 1;
}

void mouse_click_pause(enum pages *state, game_object ***sprite,
sfRenderWindow *window)
{
    if (*state == PAUSE)
        *state = PAUSE_CLICK;
    if (*state == RESUME) {
        *state = GAME;
        restart_clocks(*sprite);
        sfRenderWindow_clear(window, sfBlack);
    }
    if (*state == RESTART) {
        *state = GAME;
        mouse_click_restart(state, sprite, window);
    }
    if (*state == SOUND_EFFECT)
        (*sprite)[16]->sound_effect = ((*sprite)[16]->sound_effect + 1) % 2;
    if (*state == MUSIC)
        (*sprite)[16]->music = ((*sprite)[16]->music + 1) % 2;
    if (*state == EXIT)
        sfRenderWindow_close(window);
}