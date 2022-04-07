/*
** EPITECH PROJECT, 2020
** analyse_events.c
** File description:
** my_defender
*/

#include "../include/my_defender.h"

void analyse_events(sfRenderWindow *window, sfEvent event,
game_object ***sprite, enum pages *state)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseMoved && *state > PSEUDO)
            manage_mouse_move(event, state, sprite);
        if (event.type == sfEvtMouseButtonReleased && *state > PSEUDO)
            manage_mouse_released(event, window, state, sprite);
        if (event.type == sfEvtMouseButtonPressed && *state > PSEUDO)
            manage_mouse_click(event, window, state, sprite);
        if (event.type == sfEvtKeyPressed)
            manage_key_pressed(event, state);
        if (event.type == sfEvtTextEntered)
            input_name_handling(sprite, state, window, event);
    }
}