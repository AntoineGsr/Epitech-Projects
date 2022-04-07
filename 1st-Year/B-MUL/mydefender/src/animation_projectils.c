/*
** EPITECH PROJECT, 2021
** animation_projectils.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void zombie_died(list ***gbl, l_list ***node, game_object ***sprite, int *j)
{
    if ((*node)[1]->mob->life <= 0) {
        destroy_node_noloop(&(*gbl)[1], &(*node)[1], j);
        (*gbl)[0]->score += 1;
    }
}

void verif_froze_hit(l_list ***node)
{
    if ((*node)[2]->mob->type_plante == 5) {
        (*node)[1]->mob->speed_x = 5;
        (*node)[1]->mob->speed_y = 5;
    }
}

void verif_hit_zombie(list ***gbl, l_list ***node, game_object ***sprite,
int *i)
{
    for (int j = 0; j < (*gbl)[1]->max_node; j++,
        (*node)[1] = (*node)[1]->next) {
        if ((((*node)[2]->mob->pos.x >= (*node)[1]->mob->pos.x
        + (*node)[1]->mob->rect.width / 2
            && (*node)[2]->mob->pos.x <= (*node)[1]->mob->pos.x
            + (*node)[1]->mob->rect.width))
            && (((*node)[2]->mob->pos.y >= (*node)[1]->mob->pos.y
            && (*node)[2]->mob->pos.y <= (*node)[1]->mob->pos.y
            + (*node)[1]->mob->rect.height / 3))) {
            (*node)[1]->mob->life -= (*node)[2]->mob->damage;
            verif_froze_hit(node);
            destroy_node_noloop(&(*gbl)[2], &(*node)[2], i);
            zombie_died(gbl, node, sprite, &j);
            break;
        }
    }
    (*node)[1] = (*gbl)[1]->first;
}

void projectils_movement(list ***gbl, l_list ***node, game_object ***sprite)
{
    float seconds = 0;

    for (int i = 0; i < (*gbl)[2]->max_node; i++,
        (*node)[2] = (*node)[2]->next) {
        (*node)[2]->mob->time = sfClock_restart((*node)[2]->mob->clock);
        seconds = (*node)[2]->mob->time.microseconds / 1000000.0;
        (*node)[2]->mob->pos.x += (*node)[2]->mob->speed_x * seconds;
        verif_hit_zombie(gbl, node, sprite, &i);
    }
    (*node)[2] = (*gbl)[2]->first;
}