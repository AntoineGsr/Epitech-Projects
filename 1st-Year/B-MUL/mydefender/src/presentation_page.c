/*
** EPITECH PROJECT, 2021
** presentation_page.c
** File description:
** my_defender
*/

#include "../include/my_defender.h"

void animate_press(game_object ***sprite, sfRenderWindow *window)
{
    float seconds = 0;

    (*sprite)[1]->time = sfClock_getElapsedTime((*sprite)[1]->clock);
    seconds = (*sprite)[1]->time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if ((*sprite)[1]->rect.top <= 0) {
            (*sprite)[1]->speed_y = 16;
            (*sprite)[1]->rect.top += (*sprite)[1]->speed_y;
        } else if ((*sprite)[1]->rect.top <= 64) {
            (*sprite)[1]->rect.top += (*sprite)[1]->speed_y;
        }
        if ((*sprite)[1]->rect.top >= 64) {
            (*sprite)[1]->speed_y = -16;
            (*sprite)[1]->rect.top = 64;
        }
        sfClock_restart((*sprite)[1]->clock);
    }
}

void presentation_page(game_object ***sprite, enum pages *state,
sfRenderWindow *window)
{
    display_sprite(*sprite, window, 0, 2);
    animate_press(sprite, window);
}