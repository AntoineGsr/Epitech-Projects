/*
** EPITECH PROJECT, 2021
** mouse_move_game.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void mouse_move_select_obs(sfEvent event, enum pages *state,
game_object ***sprite)
{
    if (event.mouseMove.x >= (*sprite)[19]->pos.x && event.mouseMove.x
        <= (*sprite)[19]->pos.x + (*sprite)[19]->rect.width
        && (*sprite)[19]->life == 1) {
        if (event.mouseMove.y >= (*sprite)[19]->pos.y && event.mouseMove.y
            <= (*sprite)[19]->pos.y + (*sprite)[19]->rect.height) {
            *state = CARD_OBSTACLE;
        }
    }
}

void mouse_move_hitbox_cards(sfEvent event, enum pages *state,
game_object ***sprite)
{
    if (event.mouseMove.y >= 19 && event.mouseMove.y <= 97) {
        if (event.mouseMove.x >= 130 && event.mouseMove.x <= 216
            && (*sprite)[10]->rect.left == 0)
            *state = CARD_SUN;
        if (event.mouseMove.x >= 235 && event.mouseMove.x <= 323
            && (*sprite)[11]->rect.left == 0)
            *state = CARD_SHOOTER;
        if (event.mouseMove.x >= 343 && event.mouseMove.x <= 423
            && (*sprite)[12]->rect.left == 0)
            *state = CARD_CARNIVOR;
        if (event.mouseMove.x >= 446 && event.mouseMove.x <= 526
            && (*sprite)[13]->rect.left == 0)
            *state = CARD_BOMB;
        if (event.mouseMove.x >= 549 && event.mouseMove.x <= 633
            && (*sprite)[14]->rect.left == 0)
            *state = CARD_FROZ;
    }
    mouse_move_select_obs(event, state, sprite);
}

void mouse_move_game(sfEvent event, enum pages *state, game_object ***sprite)
{
    if ((*state < CARD_SUN_CLICK && (*sprite)[0]->mouse_left_click == 0)
        || *state == GAME_MENU)
        *state = GAME;
    if (*state >= CARD_SUN_CLICK && (*sprite)[0]->mouse_left_click == 1) {
        (*sprite)[20]->pos =
        (sfVector2f){event.mouseMove.x - (*sprite)[20]->rect.width / 2,
        event.mouseMove.y - (*sprite)[20]->rect.height
        + (*sprite)[20]->rect.height / 5};
        return;
    }
    if (event.mouseMove.x >= 1182 && event.mouseMove.x <= 1275) {
        if (event.mouseMove.y >= 0 && event.mouseMove.y <= 87)
            *state = GAME_MENU;
    }
    mouse_move_hitbox_cards(event, state, sprite);
}