/*
** EPITECH PROJECT, 2021
** tuto_page.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void move_tuto(game_object ***sprite, enum pages *state)
{
    float seconds = 0;

    (*sprite)[5]->time = sfClock_restart((*sprite)[5]->clock);
    seconds = (*sprite)[5]->time.microseconds / 1000000.0;
    if (*state == MOVE_GAME) {
        (*sprite)[5]->speed_y -= (*sprite)[5]->speed_y * seconds / 2;
        (*sprite)[5]->pos.y -= (*sprite)[5]->speed_y * seconds;
        (*sprite)[8]->pos.y = (*sprite)[5]->pos.y + 768;
        if ((*sprite)[5]->pos.y <= -768) {
            (*sprite)[5]->pos.y = -768;
            (*sprite)[8]->pos.y = 0;
            (*sprite)[5]->speed_x = 325;
            (*sprite)[5]->speed_y = 475;
            (*sprite)[2]->speed_y = 475;
            *state = TUTO1;
        }
    }
}

void change_sprite_tuto(game_object ***sprite, enum pages *state)
{
    if (*state == MOVE_GAME)
        move_tuto(sprite, state);
    if (*state == TUTO2) {
        sfTexture_destroy((*sprite)[8]->texture);
        (*sprite)[8]->texture = sfTexture_createFromFile
        ("./images/tutorial_part2.png", NULL);
    }
    if (*state == TUTO3) {
        sfTexture_destroy((*sprite)[8]->texture);
        (*sprite)[8]->texture = sfTexture_createFromFile
        ("./images/tutorial_part3.png", NULL);
    }
    if (*state == TUTO4) {
        sfTexture_destroy((*sprite)[8]->texture);
        (*sprite)[8]->texture = sfTexture_createFromFile
        ("./images/tutorial_part4.png", NULL);
    }
}

void tuto_page(game_object ***sprite, enum pages *state,
sfRenderWindow *window)
{
    (*sprite)[5]->rect = (sfIntRect){0, 0, 1300, 768};
    sfTexture_destroy((*sprite)[5]->texture);
    (*sprite)[5]->texture = sfTexture_createFromFile
    ("./images/clouds big.png", NULL);
    change_sprite_tuto(sprite, state);
    display_sprite(*sprite, window, 5, 6);
    display_sprite(*sprite, window, 8, 9);
}