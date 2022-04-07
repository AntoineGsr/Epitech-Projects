/*
** EPITECH PROJECT, 2021
** gestion_page.c
** File description:
** my_runner
*/

#include "my_runner.h"

void gestion_page(game_object **sprite, enum pages *state,
sfRenderWindow *window, list **gbl)
{
    sfRenderWindow_clear(window, sfBlack);
    if (*state == PRESS)
        press_page(sprite, window);
    if (*state >= MENU && *state <= STGS_MUSIC)
        menu_page(sprite, *state, window);
    if (*state >= GAME && *state <= PAUSE)
        game_page(sprite, state, window, gbl);
    if (*state >= GAME && *state <= EXIT)
        home_pause_page(sprite, *state, window);
    if (*state >= GAMEWIN && *state <= L_END_QUIT)
        gameend_page(sprite, state, window);
    gestion_music(sprite, state);
}