/*
** EPITECH PROJECT, 2021
** mouse_click_menu.c
** File description:
** my_runner
*/

#include "my_runner.h"

void mouse_click_menu(enum pages *state, game_object ***sprite,
sfRenderWindow *window)
{
    if (*state == START)
        *state = GAME;
    if (*state == CONTROLS)
        *state = CTRL;
    if (*state == SETTINGS)
        *state = STGS;
    if (*state == QUIT)
        sfRenderWindow_close(window);
    if (*state == CTRL_BCK)
        *state = MENU;
    if (*state == STGS_BCK)
        *state = MENU;
    if (*state == STGS_8D)
        (*sprite)[16]->eight_d_sound = ((*sprite)[16]->eight_d_sound + 1) % 2;
    if (*state == STGS_SOUND)
        (*sprite)[16]->sound_effect = ((*sprite)[16]->sound_effect + 1) % 2;
    if (*state == STGS_MUSIC)
        (*sprite)[16]->music = ((*sprite)[16]->music + 1) % 2;
}