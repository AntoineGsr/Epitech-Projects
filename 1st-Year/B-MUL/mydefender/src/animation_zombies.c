/*
** EPITECH PROJECT, 2021
** zombies_gestion.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void zombie_attack_house(list ***gbl, l_list ***node, game_object ***sprite,
int *i)
{
    if ((*node)[1]->mob->pos.x < 130) {
        (*gbl)[0]->life_house -= 1;
        destroy_node_noloop(&(*gbl)[1], &(*node)[1], i);
    }
}

void up_zombie_obstacle(l_list ***node, game_object ***sprite, float seconds)
{
    if ((*node)[1]->mob->pos.y <= (*sprite)[19]->pos.y
        || (*node)[1]->mob->pos.y <= (*sprite)[19]->pos.y
        + (*sprite)[19]->rect.height - 80) {
        (*node)[1]->mob->pos.y += (*node)[1]->mob->speed_y * seconds;
    }
}

void down_zombie_obstacle(l_list ***node, game_object ***sprite, float seconds)
{
    if ((*node)[1]->mob->pos.y + (*node)[1]->mob->rect.height
        >= (*sprite)[19]->pos.y - 20 && (*node)[1]->mob->pos.y + 20
        < (*sprite)[19]->pos.y) {
        (*node)[1]->mob->pos.y -= (*node)[1]->mob->speed_y * seconds;
    }
}

void dodge_obsgacle(l_list ***node, game_object ***sprite, float seconds)
{
    if ((*sprite)[19]->pos.x + 50 >= (*node)[1]->mob->pos.x
        && (*sprite)[19]->life == 0) {
        if ((*sprite)[19]->pos.y < 160) {
            up_zombie_obstacle(node, sprite, seconds);
        } else
            down_zombie_obstacle(node, sprite, seconds);
    }
}

void zombie_movement(list ***gbl, l_list ***node, game_object ***sprite)
{
    float seconds = 0;

    for (int i = 0; i < (*gbl)[1]->max_node; i++,
        (*node)[1] = (*node)[1]->next) {
        (*node)[1]->mob->time = sfClock_restart
        ((*node)[1]->mob->clock_action);
        seconds = (*node)[1]->mob->time.microseconds / 1000000.0;
        (*node)[1]->mob->pos.x -= (*node)[1]->mob->speed_x * seconds;
        dodge_obsgacle(node, sprite, seconds);
        (*node)[1]->mob->time = sfClock_getElapsedTime((*node)[1]->mob->clock);
        seconds = (*node)[1]->mob->time.microseconds / 1000000.0;
        if (seconds > (*node)[1]->mob->animation_time) {
            (*node)[1]->mob->rect.left += (*node)[1]->mob->rect.width;
            if ((*node)[1]->mob->rect.left >= (*node)[1]->mob->offset)
                (*node)[1]->mob->rect.left = 0;
            sfClock_restart((*node)[1]->mob->clock);
        }
        zombie_attack_house(gbl, node, sprite, &i);
    }
    (*node)[1] = (*gbl)[1]->first;
}