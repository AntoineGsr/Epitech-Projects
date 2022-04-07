/*
** EPITECH PROJECT, 2021
** mouse_move_pause.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void mouse_move_pause(sfEvent event, enum pages *state, game_object ***sprite)
{
    *state = GAME_MENU_CLICK;
    if (event.mouseMove.x >= (*sprite)[16]->pos.x && event.mouseMove.x
        <= (*sprite)[16]->pos.x + (*sprite)[16]->rect.width) {
        if (event.mouseMove.y >= (*sprite)[16]->pos.y && event.mouseMove.y
            <= (*sprite)[16]->pos.y + (*sprite)[16]->rect.height)
            *state = GAME_MENU_MENU;
        if (event.mouseMove.y >= (*sprite)[17]->pos.y && event.mouseMove.y
            <= (*sprite)[17]->pos.y + (*sprite)[17]->rect.height)
            *state = GAME_MENU_RESUME;
        if (event.mouseMove.y >= (*sprite)[18]->pos.y && event.mouseMove.y
            <= (*sprite)[18]->pos.y + (*sprite)[18]->rect.height)
            *state = GAME_MENU_QUIT;
    }
}
