/*
** EPITECH PROJECT, 2021
** swap_sprite_menu.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void refresh_sprite_index(game_object ***sprite, int i, char *pth_one,
char *pth_two)
{
    sfTexture_destroy((*sprite)[i]->texture);
    (*sprite)[i]->texture = sfTexture_createFromFile(pth_one, NULL);
    if ((*sprite)[0]->mouse_left_click == 1) {
        sfTexture_destroy((*sprite)[i]->texture);
        (*sprite)[i]->texture = sfTexture_createFromFile(pth_two, NULL);
    }
}

void state_sprite_second_menu(game_object ***sprite, enum pages *state,
sfRenderWindow *window)
{
    if (*state == SURVIVAL)
        refresh_sprite_index(sprite, 3, "./images/survival_button.png",
        "./images/survival_released.png");
    if (*state == VS)
        refresh_sprite_index(sprite, 3, "./images/vs_button.png",
        "./images/vs_released.png");
    if (*state == OPTIONS)
        refresh_sprite_index(sprite, 3, "./images/option_button.png",
        "./images/option_released.png");
    if (*state == HELP)
        refresh_sprite_index(sprite, 2, "./images/help_menu.jpg",
        "./images/help_released.jpg");
    if (*state == BACK)
        refresh_sprite_index(sprite, 2, "./images/back_menu.jpg",
        "./images/back_released.jpg");
}

void state_sprite_first_menu(game_object ***sprite, enum pages *state,
sfRenderWindow *window)
{
    if (*state == START)
        refresh_sprite_index(sprite, 3, "./images/start_button.png",
        "./images/start_released.png");
    if (*state == MORE)
        refresh_sprite_index(sprite, 3, "./images/more_button.png",
        "./images/more_released.png");
    if (*state == SAVE)
        refresh_sprite_index(sprite, 2, "./images/save_menu.jpg",
        "./images/save_released.jpg");
    if (*state == ACHIEVEMENT)
        refresh_sprite_index(sprite, 2, "./images/achievement_menu.jpg",
        "./images/achievement_released.jpg");
    if (*state == PUZZLE)
        refresh_sprite_index(sprite, 3, "./images/puzzle_button.png",
        "./images/puzzle_released.png");
    if (*state == MINI_GAMES)
        refresh_sprite_index(sprite, 3, "./images/minigame_button.png",
        "./images/minigames_released.png");
}