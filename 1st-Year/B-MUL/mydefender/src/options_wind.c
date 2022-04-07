/*
** EPITECH PROJECT, 2021
** options_wind.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void options_volume_bars(game_object ***sprite, enum pages *state,
sfRenderWindow *window, int *max_display)
{
    if (*state >= OPTIONS_CLICK && *state <= OPTIONS_SOUND) {
        (*sprite)[5] = create_object("./images/options_wind.png",
        (sfVector2f){64, 240}, (sfIntRect){0, 0, 384, 288});
        (*sprite)[6] = create_object("./images/bar_volume.png",
        (sfVector2f){276, 323}, (sfIntRect){0, 0, (*sprite)[0]->music, 2});
        (*sprite)[7] = create_object("./images/bar_volume.png",
        (sfVector2f){276, 348},
        (sfIntRect){0, 0, (*sprite)[0]->sound_effect, 2});
        if (*state == OPTIONS_MUSIC && (*sprite)[0]->mouse_left_click == 1) {
            (*sprite)[6]->rect.width = (int)((*sprite)[0]->mouse_pos.x) - 276;
            (*sprite)[0]->music = (*sprite)[6]->rect.width;
        }
        if (*state == OPTIONS_SOUND && (*sprite)[0]->mouse_left_click == 1) {
            (*sprite)[7]->rect.width = (int)((*sprite)[0]->mouse_pos.x) - 276;
            (*sprite)[0]->sound_effect = (*sprite)[7]->rect.width;
        }
        *max_display += 3;
    }
}

void options_wind(game_object ***sprite, enum pages *state,
sfRenderWindow *window, int *max_display)
{
    options_volume_bars(sprite, state, window, max_display);
    if (*state == OPTIONS_OK) {
        (*sprite)[5] = create_object("./images/options_ok_wind.png",
        (sfVector2f){64, 240}, (sfIntRect){0, 0, 384, 288});
        (*sprite)[6] = create_object("./images/bar_volume.png",
        (sfVector2f){276, 323}, (sfIntRect){0, 0, (*sprite)[0]->music, 2});
        (*sprite)[7] = create_object("./images/bar_volume.png",
        (sfVector2f){276, 348},
        (sfIntRect){0, 0, (*sprite)[0]->sound_effect, 2});
        if ((*sprite)[0]->mouse_left_click == 1) {
            sfTexture_destroy((*sprite)[5]->texture);
            (*sprite)[5]->texture = sfTexture_createFromFile
            ("./images/options_ok_released.png", NULL);
        }
        *max_display += 3;
    }
}