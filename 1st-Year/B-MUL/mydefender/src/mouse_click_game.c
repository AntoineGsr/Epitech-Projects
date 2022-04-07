/*
** EPITECH PROJECT, 2021
** mouse_click_game.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void mouse_click_follow(game_object ***sprite, sfEvent event)
{
    (*sprite)[20]->pos = (sfVector2f){event.mouseButton.x
    - (*sprite)[20]->rect.width / 2, event.mouseButton.y
    - (*sprite)[20]->rect.height + (*sprite)[20]->rect.height / 5};
    (*sprite)[0]->pos = (sfVector2f){event.mouseButton.x,
    event.mouseButton.y};
}

void mouse_click_game(enum pages *state, game_object ***sprite,
sfRenderWindow *window, sfEvent event)
{
    if (*state == GAME)
        *state = CLICK_INGAME;
    if (*state == CARD_SUN)
        *state = CARD_SUN_CLICK;
    if (*state == CARD_SHOOTER)
        *state = CARD_SHOOTER_CLICK;
    if (*state == CARD_CARNIVOR)
        *state = CARD_CARNIVOR_CLICK;
    if (*state == CARD_BOMB)
        *state = CARD_BOMB_CLICK;
    if (*state == CARD_FROZ)
        *state = CARD_FROZ_CLICK;
    if (*state == CARD_OBSTACLE)
        *state = CARD_OBSTACLE_CLICK;
    if (*state > GAME_MENU_CLICK && *state < QUIT)
        *state += 1;
    mouse_click_follow(sprite, event);
    return;
}