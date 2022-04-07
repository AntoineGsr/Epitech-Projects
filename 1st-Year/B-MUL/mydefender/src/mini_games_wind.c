/*
** EPITECH PROJECT, 2021
** mini_games_wind.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void mini_games_animation(game_object ***sprite, char *path, int *max_display)
{
    (*sprite)[5] = create_object(path, (sfVector2f){60, 150},
    (sfIntRect){0, 0, 400, 340});
    *max_display += 1;
}

void move_flowers(game_object ***sprite, enum pages *state,
sfRenderWindow *window, int *max_display)
{
    if (*state == SUN_FLOWER_PRESENT)
        mini_games_animation(sprite, "./images/sun_choosen.png",
        max_display);
    if (*state == GREEN_FLOWER_PRESENT)
        mini_games_animation(sprite, "./images/green_shoot.png",
        max_display);
    if (*state == BLUE_FLOWER_PRESENT)
        mini_games_animation(sprite, "./images/blue_shoot.png", max_display);
    if (*state == CARNIVORE_FLOWER_PRESENT)
        mini_games_animation(sprite, "./images/carnivore_plant.png",
        max_display);
    if (*state == MINE_FLOWER_PRESENT)
        mini_games_animation(sprite, "./images/mine_planted.png",
        max_display);
}

void mini_games_choose_plant(game_object ***sprite, enum pages *state,
sfRenderWindow *window, int *max_display)
{
    if (*state == PLANT_CHOSE)
        mini_games_animation(sprite,
        "./images/character_board_plant_choose.png", max_display);
    if (*state == PLANT_CHOSE_CLICK || *state == PLANT_EXIT)
        mini_games_animation(sprite, "./images/plant_present.png",
        max_display);
    move_flowers(sprite, state, window, max_display);
    if (*state == ZOMBIE_CHOSE)
        mini_games_animation(sprite,
        "./images/character_board_zombie_choose.png", max_display);
}

void mini_games_wind(game_object ***sprite, enum pages *state,
sfRenderWindow *window, int *max_display)
{
    if (*state == MINI_GAMES_CLICK) {
        (*sprite)[5] = create_object("./images/character_board.png",
        (sfVector2f){60, 150}, (sfIntRect){0, 0, 400, 340});
        *max_display += 1;
    }
    if (*state == MINI_GAMES_OK) {
        (*sprite)[5] = create_object("./images/character_board_ok.png",
        (sfVector2f){60, 150}, (sfIntRect){0, 0, 400, 340});
        if ((*sprite)[0]->mouse_left_click == 1) {
            sfTexture_destroy((*sprite)[5]->texture);
            (*sprite)[5]->texture = sfTexture_createFromFile
            ("./images/character_board_released.png", NULL);
        }
        *max_display += 1;
    }
    mini_games_choose_plant(sprite, state, window, max_display);
}