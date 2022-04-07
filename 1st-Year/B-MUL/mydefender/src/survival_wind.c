/*
** EPITECH PROJECT, 2021
** survival_wind.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void survival_wind(game_object ***sprite, enum pages *state,
sfRenderWindow *window, int *max_display)
{
    if (*state == SURVIVAL_CLICK) {
        (*sprite)[5] = create_object("./images/survival_wind.png",
        (sfVector2f){64, 240}, (sfIntRect){0, 0, 384, 288});
        *max_display += 1;
    }
    if (*state == SURVIVAL_OK) {
        (*sprite)[5] = create_object("./images/survival_ok_wind.png",
        (sfVector2f){64, 240}, (sfIntRect){0, 0, 384, 288});
        if ((*sprite)[0]->mouse_left_click == 1) {
            sfTexture_destroy((*sprite)[5]->texture);
            (*sprite)[5]->texture = sfTexture_createFromFile
            ("./images/survival_ok_released.png", NULL);
        }
        *max_display += 1;
    }
}