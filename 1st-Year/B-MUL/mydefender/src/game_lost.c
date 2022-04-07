/*
** EPITECH PROJECT, 2021
** game_lost.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void game_lost(list ***gbl, game_object ***sprite, enum pages *state)
{
    if ((*gbl)[0]->life_house <= 0) {
        *state = MOVE_BACK_GAME;
        sfClock_restart((*sprite)[2]->clock);
    }
}