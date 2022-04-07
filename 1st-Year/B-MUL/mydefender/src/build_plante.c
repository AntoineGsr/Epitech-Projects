/*
** EPITECH PROJECT, 2021
** build_plante.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

int verif_pos_plante(list ***gbl, game_object ***sprite, int pos_array,
int pos_x)
{
    if ((*gbl)[0]->map[pos_x][pos_array] == 0) {
        (*gbl)[0]->map[pos_x][pos_array] = (*sprite)[0]->type_plante;
        (*gbl)[0]->pos_x_map = pos_x;
        (*gbl)[0]->pos_y_map = pos_array;
        return (0);
    }
    return (1);
}

int detect_plante_rd(list ***gbl, l_list ***node, game_object ***sprite,
int pos_x)
{
    int pos_array = 0;
    int value_ret = 0;

    if (pos_x >= 947 && pos_x <= 1043) {
        pos_array = center_plante(gbl, node, sprite, 995);
        value_ret = verif_pos_plante(gbl, sprite, pos_array, 6);
        return (value_ret);
    }
    if (pos_x >= 1044 && pos_x <= 1144) {
        pos_array = center_plante(gbl, node, sprite, 1094);
        value_ret = verif_pos_plante(gbl, sprite, pos_array, 7);
        return (value_ret);
    }
    if (pos_x >= 1145 && pos_x <= 1271) {
        pos_array = center_plante(gbl, node, sprite, 1208);
        value_ret = verif_pos_plante(gbl, sprite, pos_array, 8);
        return (value_ret);
    }
    return (2);
}

int detect_plante_nd(list ***gbl, l_list ***node, game_object ***sprite,
int pos_x)
{
    int pos_array = 0;
    int value_ret = 0;

    if (pos_x >= 642 && pos_x <= 736) {
        pos_array = center_plante(gbl, node, sprite, 689);
        value_ret = verif_pos_plante(gbl, sprite, pos_array, 3);
        return (value_ret);
    }
    if (pos_x >= 737 && pos_x <= 843) {
        pos_array = center_plante(gbl, node, sprite, 790);
        value_ret = verif_pos_plante(gbl, sprite, pos_array, 4);
        return (value_ret);
    }
    if (pos_x >= 844 && pos_x <= 946) {
        pos_array = center_plante(gbl, node, sprite, 895);
        value_ret = verif_pos_plante(gbl, sprite, pos_array, 5);
        return (value_ret);
    }
    return (2);
}

int detect_plante_st(list ***gbl, l_list ***node, game_object ***sprite,
int pos_x)
{
    int pos_array = 0;
    int value_ret = 0;

    if (pos_x >= 339 && pos_x <= 426) {
        pos_array = center_plante(gbl, node, sprite, 382);
        value_ret = verif_pos_plante(gbl, sprite, pos_array, 0);
        return (value_ret);
    }
    if (pos_x >= 427 && pos_x <= 528) {
        pos_array = center_plante(gbl, node, sprite, 477);
        value_ret = verif_pos_plante(gbl, sprite, pos_array, 1);
        return (value_ret);
    }
    if (pos_x >= 529 && pos_x <= 641) {
        pos_array = center_plante(gbl, node, sprite, 585);
        value_ret = verif_pos_plante(gbl, sprite, pos_array, 2);
        return (value_ret);
    }
    return (2);
}

int build_plante(list ***gbl, l_list ***node, game_object ***sprite)
{
    float pos_x = (*gbl)[0]->new_node_pos.x + (*sprite)[20]->rect.width / 2;
    float pos_y = (*gbl)[0]->new_node_pos.y + (*sprite)[20]->rect.height / 2;
    int value_ret = 0;

    if (pos_y >= 114 && pos_y <= 744) {
        if ((value_ret = detect_plante_st(gbl, node, sprite, pos_x)) != 2)
            return (value_ret);
        if ((value_ret = detect_plante_nd(gbl, node, sprite, pos_x)) != 2)
            return (value_ret);
        if ((value_ret = detect_plante_rd(gbl, node, sprite, pos_x)) != 2)
            return (value_ret);
        return (1);
    } else
        return (1);
    return (0);
}