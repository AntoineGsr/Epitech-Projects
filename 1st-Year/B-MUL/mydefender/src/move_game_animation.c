/*
** EPITECH PROJECT, 2021
** move_game_animation.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void move_clouds_menu(game_object ***sprite, enum pages *state)
{
    float seconds = 0;

    (*sprite)[2]->time = sfClock_restart((*sprite)[2]->clock);
    seconds = (*sprite)[2]->time.microseconds / 1000000.0;
    if (*state == MOVE_BACK_MENU) {
        (*sprite)[2]->speed_y -= (*sprite)[2]->speed_y * seconds / 2;
        (*sprite)[2]->pos.y -= (*sprite)[2]->speed_y * seconds;
        (*sprite)[3]->pos.y -= (*sprite)[2]->speed_y * seconds;
        (*sprite)[4]->pos.y = (*sprite)[2]->pos.y + 337;
        (*sprite)[5]->pos.y = (*sprite)[2]->pos.y - 768;
        if ((*sprite)[2]->pos.y <= 0 || (*sprite)[3]->pos.y <= 0 + 384) {
            (*sprite)[2]->speed_y = 475;
            *state = MENU;
        }
    }
}

void replace_sprite(game_object ***sprite)
{
    (*sprite)[9]->pos = (sfVector2f){1182, 0};
    (*sprite)[10]->pos = (sfVector2f){119, 7};
    (*sprite)[11]->pos = (sfVector2f){226, 7};
    (*sprite)[12]->pos = (sfVector2f){330, -1};
    (*sprite)[13]->pos = (sfVector2f){434, 3};
    (*sprite)[14]->pos = (sfVector2f){538, 15};
    (*sprite)[15]->pos = (sfVector2f){28, 20};
    (*sprite)[16]->pos = (sfVector2f){500, 224};
    (*sprite)[17]->pos = (sfVector2f){500, 334};
    (*sprite)[18]->pos = (sfVector2f){500, 444};
    (*sprite)[19]->pos = (sfVector2f){670, 0};
    (*sprite)[19]->life = 1;
    (*sprite)[20]->pos = (sfVector2f){30, 100};
}

void move_game_clouds_limit(game_object ***sprite, enum pages *state,
sfRenderWindow *window)
{
    for (int i = 8; i < 21; i++)
        (*sprite)[i]->speed_y = 475;
    (*sprite)[5]->speed_y = 475;
    *state = DESTROY_ENTITY;
    sfTexture_destroy((*sprite)[5]->texture);
    (*sprite)[5]->texture = sfTexture_createFromFile
    ("./images/clouds.png", NULL);
    (*sprite)[5]->rect = (sfIntRect){0, 0, 512, 768};
    (*sprite)[5]->pos = (sfVector2f){0, 0};
    sfRenderWindow_destroy(window);
    window = create_my_window(512, 768);
    replace_sprite(sprite);
}

void move_game_clouds(game_object ***sprite, enum pages *state,
sfRenderWindow *window)
{
    float seconds = 0;

    (*sprite)[2]->time = sfClock_restart((*sprite)[2]->clock);
    seconds = (*sprite)[2]->time.microseconds / 1000000.0;
    if (*state == MOVE_BACK_GAME) {
        (*sprite)[5]->speed_y -= (*sprite)[5]->speed_y * seconds / 2;
        (*sprite)[5]->pos.y += (*sprite)[5]->speed_y * seconds;
        for (int i = 8; i < 21; i++) {
            (*sprite)[i]->speed_y -= (*sprite)[i]->speed_y * seconds / 2;
            (*sprite)[i]->pos.y += (*sprite)[i]->speed_y * seconds;
        }
        if ((*sprite)[8]->pos.y >= 768) {
            move_game_clouds_limit(sprite, state, window);
        }
    }
}

void move_game_menu(game_object ***sprite, enum pages *state,
sfRenderWindow *window)
{
    if (*state == MOVE_BACK_GAME || *state == DESTROY_ENTITY) {
        move_game_clouds(sprite, state, window);
        display_sprite(*sprite, window, 5, 6);
    }
    if (*state == MOVE_BACK_MENU) {
        move_clouds_menu(sprite, state);
        display_sprite(*sprite, window, 2, 6);
    }
    if (*state == MENU) {
        sfTexture_destroy((*sprite)[8]->texture);
        (*sprite)[8]->texture = sfTexture_createFromFile
        ("./images/tutorial_part1.png", NULL);
    }
}