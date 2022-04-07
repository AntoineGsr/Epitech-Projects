/*
** EPITECH PROJECT, 2020
** analyse_event.c
** File description:
** my_hunter
*/

#include "my_hunter.h"

void analyse_events(B_base *bck, S_base *bird, sfRenderWindow *window,
sfEvent event)
{
    S_base menu;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            close_window(window, event);
        if (event.type == sfEvtMouseButtonPressed)
            manage_mouse_click(event, *&bird);
        if (sfMouse_isButtonPressed(sfMouseRight)) {
            sfClock_destroy(bird[0].clock);
            bird[0].exit_button = display_menu(window, bck, event, &menu);
            bird[0].clock = sfClock_create();
        }
    }
}