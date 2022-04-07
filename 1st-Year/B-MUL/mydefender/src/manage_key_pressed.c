/*
** EPITECH PROJECT, 2021
** manage_key_pressed.c
** File description:
** my_defender
*/

#include "../include/my_defender.h"

void manage_key_pressed(sfEvent event, enum pages *state)
{
    if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
        if (*state <= PSEUDO || (*state >= TUTO1 && *state <= TUTO4))
            *state += 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        if (*state >= GAME && *state < GAME_MENU_CLICK) {
            *state = GAME_MENU_CLICK;
        } else if (*state >= GAME_MENU_CLICK && *state < QUIT) {
            *state = GAME;
        }
    }
}
