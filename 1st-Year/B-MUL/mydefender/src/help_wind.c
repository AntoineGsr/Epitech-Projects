/*
** EPITECH PROJECT, 2021
** help_wind.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void help_wind(game_object ***sprite, enum pages *state,
sfRenderWindow *window, int *max_display)
{
    if (*state == HELP_CLICK || *state == HELP_OK) {
        (*sprite)[5] = create_object("./images/help_wind.png",
        (sfVector2f){64, 240}, (sfIntRect){0, 0, 384, 288});
        *max_display += 1;
    }
}