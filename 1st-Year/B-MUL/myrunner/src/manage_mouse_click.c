/*
** EPITECH PROJECT, 2020
** manage_mouse_click.c
** File description:
** my_hunter
*/

#include "my_runner.h"

void manage_mouse_click(sfEvent event, sfRenderWindow *window,
enum pages *state, game_object ***sprite)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        mouse_click_menu(state, sprite, window);
        mouse_click_pause(state, sprite, window);
        mouse_click_home(state, sprite, window);
        mouse_click_end(state, sprite, window);
    }
}
