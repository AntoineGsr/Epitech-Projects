/*
** EPITECH PROJECT, 2020
** analyse_events.c
** File description:
** my_runner
*/

#include "my_runner.h"

void analyse_events(sfRenderWindow *window, sfEvent event,
game_object ***sprite, enum pages *state)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if ((event.type == sfEvtKeyPressed || event.type
            == sfEvtMouseButtonPressed) && *state == PRESS)
            *state = MENU;
        if (event.type == sfEvtMouseMoved && *state > PRESS)
            manage_mouse_move(event, state);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed)
            manage_mouse_click(event, window, state, sprite);
        if (event.type == sfEvtKeyPressed)
            manage_key_pressed(event, sprite);
    }
}