/*
** EPITECH PROJECT, 2020
** manage_mouse_click.c
** File description:
** my_hunter
*/

#include "../include/my_defender.h"

void manage_mouse_click(sfEvent event, sfRenderWindow *window,
enum pages *state, game_object ***sprite)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        (*sprite)[0]->mouse_left_click = 1;
        mouse_click_game(state, sprite, window, event);
    }
}
