/*
** EPITECH PROJECT, 2021
** center_plante.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

int center_plante_seconds(list ***gbl, l_list ***node, game_object ***sprite,
float center)
{
    float pos_y = (*gbl)[0]->new_node_pos.y + (*sprite)[20]->rect.height / 2;

    if (pos_y >= 495 && pos_y <= 606) {
        (*gbl)[0]->new_node_pos = (sfVector2f){center, 568};
        return (3);
    }
    if (pos_y >= 607 && pos_y <= 744) {
        (*gbl)[0]->new_node_pos = (sfVector2f){center, 691};
        return (4);
    }
    return (0);
}

int center_plante(list ***gbl, l_list ***node, game_object ***sprite,
float center)
{
    float pos_y = (*gbl)[0]->new_node_pos.y + (*sprite)[20]->rect.height / 2;
    int value_ret = 0;

    if (pos_y >= 114 && pos_y <= 231) {
        (*gbl)[0]->new_node_pos = (sfVector2f){center, 185};
        return (0);
    }
    if (pos_y >= 232 && pos_y <= 359) {
        (*gbl)[0]->new_node_pos = (sfVector2f){center, 315};
        return (1);
    }
    if (pos_y >= 360 && pos_y <= 494) {
        (*gbl)[0]->new_node_pos = (sfVector2f){center, 449};
        return (2);
    }
    value_ret = center_plante_seconds(gbl, node, sprite, center);
    return (value_ret);
}