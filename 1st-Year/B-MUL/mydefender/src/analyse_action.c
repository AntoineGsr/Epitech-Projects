/*
** EPITECH PROJECT, 2021
** analyse_action.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void analyse_range_plante(list ***gbl, l_list ***node, game_object ***sprite)
{
    if ((*node)[1]->mob->pos.x <= (*node)[0]->mob->pos.x
        + (*node)[0]->mob->range && (*node)[1]->mob->pos.x
        >= (*node)[0]->mob->pos.x) {
        if ((*node)[1]->mob->pos.y <= (*node)[0]->mob->pos.y &&
            (*node)[1]->mob->pos.y + (*node)[1]->mob->rect.height >=
            (*node)[0]->mob->pos.y + (*node)[0]->mob->rect.height / 2) {
            (*node)[0]->mob->have_to_shoot = 1;
            (*node)[0]->mob->rect.top = (*node)[0]->mob->rect.height;
            (*node)[0]->mob->offset = (*node)[0]->mob->offset_shoot;
            (*node)[0]->mob->rect.left = 0;
        }
    }
}

void analyse_action(list ***gbl, l_list ***node, game_object ***sprite)
{
    if ((*node)[0]->mob->type_plante == 1) {
        (*gbl)[0]->nb_sun += 25;
        sfClock_restart((*node)[0]->mob->clock_action);
    } else if ((*node)[0]->mob->type_plante != 6) {
        for (int i = 0; i < (*gbl)[1]->max_node; i++, (*node)[1]
            = (*node)[1]->next) {
            analyse_range_plante(gbl, node, sprite);
        }
        (*node)[1] = (*gbl)[1]->first;
    }
}