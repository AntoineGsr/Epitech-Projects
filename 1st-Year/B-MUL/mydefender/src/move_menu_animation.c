/*
** EPITECH PROJECT, 2021
** move_more_animation.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void move_more_menu(game_object ***sprite, enum pages *state)
{
    float seconds = 0;
    float previous_posx = (*sprite)[2]->rect.left;

    (*sprite)[2]->time = sfClock_restart((*sprite)[2]->clock);
    seconds = (*sprite)[2]->time.microseconds / 1000000.0;
    (*sprite)[2]->speed_x -= (*sprite)[2]->speed_x * seconds / 2;
    (*sprite)[2]->rect.left += (*sprite)[2]->speed_x * seconds;
    (*sprite)[3]->rect.left += (*sprite)[2]->speed_x * seconds;
    (*sprite)[4]->pos.x -= (*sprite)[2]->rect.left - previous_posx;
    if ((*sprite)[2]->rect.left >= 512 || (*sprite)[3]->rect.left >= 512) {
        (*sprite)[2]->rect.left = 512;
        (*sprite)[3]->rect.left = 512;
        (*sprite)[2]->speed_x = 325;
        *state = MENU;
    }
}

void move_menu_more(game_object ***sprite, enum pages *state)
{
    float seconds = 0;
    float previous_posx = (*sprite)[2]->rect.left;

    (*sprite)[2]->time = sfClock_restart((*sprite)[2]->clock);
    seconds = (*sprite)[2]->time.microseconds / 1000000.0;
    (*sprite)[2]->speed_x -= (*sprite)[2]->speed_x * seconds / 2;
    (*sprite)[2]->rect.left -= (*sprite)[2]->speed_x * seconds;
    (*sprite)[3]->rect.left -= (*sprite)[2]->speed_x * seconds;
    (*sprite)[4]->pos.x += previous_posx - (*sprite)[2]->rect.left;
    if ((*sprite)[2]->rect.left <= 0 || (*sprite)[3]->rect.left <= 0) {
        (*sprite)[2]->rect.left = 0;
        (*sprite)[3]->rect.left = 0;
        (*sprite)[2]->speed_x = 325;
        *state = MENU_MORE;
    }
}

void move_clouds_game(game_object ***sprite, enum pages *state)
{
    (*sprite)[2]->pos.y = 768;
    (*sprite)[3]->pos.y = 768 + 384;
    (*sprite)[4]->pos.y += (*sprite)[2]->pos.y - 370;
    (*sprite)[5]->pos.y = 0;
    (*sprite)[2]->speed_x = 325;
    (*sprite)[2]->speed_y = 475;
    *state = MOVE_GAME;
    sfClock_restart((*sprite)[5]->clock);
}

void move_clouds(game_object ***sprite, enum pages *state)
{
    float seconds = 0;
    float previous_posy = (*sprite)[2]->pos.y;

    (*sprite)[2]->time = sfClock_restart((*sprite)[2]->clock);
    seconds = (*sprite)[2]->time.microseconds / 1000000.0;
    if (*state == MOVE_CLOUD) {
        (*sprite)[2]->speed_y -= (*sprite)[2]->speed_y * seconds / 2;
        (*sprite)[2]->pos.y += (*sprite)[2]->speed_y * seconds;
        (*sprite)[3]->pos.y += (*sprite)[2]->speed_y * seconds;
        (*sprite)[4]->pos.y = (*sprite)[2]->pos.y + 337;
        (*sprite)[5]->pos.y = (*sprite)[2]->pos.y - 768;
        if ((*sprite)[2]->pos.y >= 768 || (*sprite)[3]->pos.y >= 768 + 384)
            move_clouds_game(sprite, state);
    }
}

void move_menu_more_game(game_object ***sprite, enum pages *state,
sfRenderWindow *window, int *max_display)
{
    if (*state == MOVE_MENU || *state == MOVE_MORE) {
        if (*state == MOVE_MORE)
            move_menu_more(sprite, state);
        if (*state == MOVE_MENU)
            move_more_menu(sprite, state);
    }
    if (*state == MOVE_CLOUD) {
        (*sprite)[5] = create_object("./images/clouds.png",
        (sfVector2f){0, -768}, (sfIntRect){0, 0, 512, 768});
        *max_display += 1;
        move_clouds(sprite, state);
    }
    if (*state == MOVE_GAME) {
        sfRenderWindow_destroy(window);
        window = create_my_window(1300, 768);
    }
}