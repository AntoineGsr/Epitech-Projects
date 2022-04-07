/*
** EPITECH PROJECT, 2021
** raven_animation.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void raven_time_elec(game_object ***sprite, enum pages *state)
{
    float seconds = 0;

    (*sprite)[4]->time = sfClock_getElapsedTime((*sprite)[4]->clock);
    seconds = (*sprite)[4]->time.microseconds / 1000000.0;
    if ((*sprite)[4]->rect.left == 0) {
        if (seconds >= 1)
            (*sprite)[4]->rect.left += 144;
    } else if (seconds >= 0.15) {
        (*sprite)[4]->rect.left += 144;
        if ((*sprite)[4]->rect.left >= 432)
            (*sprite)[4]->rect.left = 0;
        sfClock_restart((*sprite)[4]->clock);
    }
}

void raven_click_animation(game_object ***sprite, enum pages *state)
{
    sfClock_restart((*sprite)[4]->clock);
    sfTexture_destroy((*sprite)[4]->texture);
    (*sprite)[4]->texture = sfTexture_createFromFile
    ("./images/raven_click.png", NULL);
    (*sprite)[4]->pos = (sfVector2f){278, 20};
    (*sprite)[4]->rect = (sfIntRect){0, 0, 234, 497};
    *state = RAVEN;
}

void raven_animation(game_object ***sprite, enum pages *state,
sfRenderWindow *window)
{
    float seconds = 0;

    (*sprite)[4]->time = sfClock_getElapsedTime((*sprite)[4]->clock);
    seconds = (*sprite)[4]->time.microseconds / 1000000.0;
    if (*state == RAVEN_CLICK) {
        raven_click_animation(sprite, state);
        return;
    } else if ((*sprite)[4]->pos.x == 278 && seconds >= 0.2) {
        sfTexture_destroy((*sprite)[4]->texture);
        (*sprite)[4]->texture = sfTexture_createFromFile
        ("./images/raven.png", NULL);
        (*sprite)[4]->pos = (sfVector2f){370, 337};
        (*sprite)[4]->rect = (sfIntRect){0, 0, 144, 156};
    } else {
        if ((*sprite)[4]->pos.x == 278)
            return;
    }
    raven_time_elec(sprite, state);
}