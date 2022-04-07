/*
** EPITECH PROJECT, 2020
** manage_mouse_click.c
** File description:
** my_hunter
*/

#include "my_hunter.h"

void manage_mouse_click(sfEvent event, S_base *bird)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        for (int i = 0; i < bird[i].nb_bird; i++) {
            if ((event.mouseButton.x >= bird[i].pos.x && event.mouseButton.x
            <= (bird[i].pos.x + bird[i].rect.width)) && (event.mouseButton.y
            >= bird[i].pos.y && event.mouseButton.y
            <= (bird[i].pos.y + bird[i].rect.height) && bird[i].kill == 0)) {
                bird[i].kill = 1;
            }
        }
    }
}
