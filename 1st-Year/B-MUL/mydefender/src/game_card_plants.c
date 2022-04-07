/*
** EPITECH PROJECT, 2021
** game_card_plants.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

int swap_sprite_game(game_object ***sprite, int type_plante, char *pth,
sfIntRect rect)
{
    sfTexture_destroy((*sprite)[20]->texture);
    (*sprite)[20]->texture = sfTexture_createFromFile(pth, NULL);
    (*sprite)[0]->type_plante = type_plante;
    (*sprite)[20]->rect = rect;
    return (1);
}

void game_card_plants(game_object ***sprite, enum pages *state,
int *max_display)
{
    if (*state == CARD_SUN_CLICK)
        *max_display += swap_sprite_game(sprite, 1, "./images/tournesol.png",
        (sfIntRect){0, 0, 116, 128});
    if (*state == CARD_SHOOTER_CLICK)
        *max_display += swap_sprite_game(sprite, 2, "./images/shooter.png",
        (sfIntRect){0, 0, 116, 128});
    if (*state == CARD_CARNIVOR_CLICK)
        *max_display += swap_sprite_game(sprite, 3, "./images/carnivor.png",
        (sfIntRect){0, 0, 180, 155});
    if (*state == CARD_BOMB_CLICK)
        *max_display += swap_sprite_game(sprite, 4, "./images/bomb.png",
        (sfIntRect){0, 0, 83, 80});
    if (*state == CARD_FROZ_CLICK)
        *max_display += swap_sprite_game(sprite, 5, "./images/frozen.png",
        (sfIntRect){0, 0, 131, 124});
    if (*state == CARD_OBSTACLE_CLICK)
        *max_display += swap_sprite_game(sprite, 6, "./images/obstacle.png",
        (sfIntRect){0, 0, 33, 114});
}