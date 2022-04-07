/*
** EPITECH PROJECT, 2021
** gestion_page.c
** File description:
** my_runner
*/

#include "../include/my_defender.h"

void gestion_page(game_object ***sprite, enum pages *state,
sfRenderWindow *window, list **gbl)
{
    sfRenderWindow_clear(window, sfBlack);
    if (*state == PRESENTATION)
        presentation_page(sprite, state, window);
    if (*state == PSEUDO)
        pseudo_page(sprite, state, window);
    if (*state >= MENU && *state <= MOVE_CLOUD)
        menu_page(sprite, state, window);
    if (*state >= MOVE_GAME && *state < GAME)
        tuto_page(sprite, state, window);
    if (*state >= ENTITY_CREATION)
        game_page(sprite, state, window);
}