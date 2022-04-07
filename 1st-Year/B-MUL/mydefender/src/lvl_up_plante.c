/*
** EPITECH PROJECT, 2021
** lvl_up_plante.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void click_lvl_up(list ***gbl, l_list ***node, game_object ***sprite)
{
    (*node)[0]->mob->type_plante += 10;
    (*gbl)[0]->nb_sun -= 300;
    (*node)[0]->mob->offset = 580;
    (*node)[0]->mob->offset_origin = 580;
    (*node)[0]->mob->offset_shoot = 232;
    sfTexture_destroy((*node)[0]->mob->texture);
    (*node)[0]->mob->rect.top = 0;
    (*node)[0]->mob->rect.left = 0;
    (*node)[0]->mob->texture = sfTexture_createFromFile
    ("./images/shooter2.png", NULL);
}

void lvl_up_plante(list ***gbl, l_list ***node, game_object ***sprite,
enum pages *state)
{
    *state = GAME;
    (*gbl)[0]->new_node_pos = (*sprite)[20]->pos;
    for (int i = 0; i < (*gbl)[0]->max_node; i++,
        (*node)[0] = (*node)[0]->next) {
        if (((*node)[0]->mob->type_plante == 2 && (*gbl)[0]->nb_sun >= 300)
            && (((*sprite)[0]->pos.x >= (*node)[0]->lvl_up->pos.x
            && (*sprite)[0]->pos.x <= (*node)[0]->lvl_up->pos.x + 22))
            && (((*sprite)[0]->pos.y >= (*node)[0]->lvl_up->pos.y
            && (*sprite)[0]->pos.y <= (*node)[0]->lvl_up->pos.y + 26))) {
            click_lvl_up(gbl, node, sprite);
        }
    }
    (*node)[0] = (*gbl)[0]->first;
}