/*
** EPITECH PROJECT, 2021
** vs_wind.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void vs_wind(game_object ***sprite, enum pages *state,
sfRenderWindow *window, int *max_display)
{
    if (*state == VS_CLICK) {
        (*sprite)[5] = create_object("./images/vs_wind.png",
        (sfVector2f){64, 240}, (sfIntRect){0, 0, 384, 288});
        *max_display += 1;
    }
    if (*state == VS_OK) {
        (*sprite)[5] = create_object("./images/vs_ok_wind.png",
        (sfVector2f){64, 240}, (sfIntRect){0, 0, 384, 288});
        if ((*sprite)[0]->mouse_left_click == 1) {
            sfTexture_destroy((*sprite)[5]->texture);
            (*sprite)[5]->texture =
            sfTexture_createFromFile("./images/vs_ok_released.png", NULL);
        }
        *max_display += 1;
    }
}