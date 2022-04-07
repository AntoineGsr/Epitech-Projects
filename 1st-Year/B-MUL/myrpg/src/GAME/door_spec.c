/*
** EPITECH PROJECT, 2021
** entity_gestion.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void animate_door_open(sfIntRect *rect, sfVector3f param, rpg_t *rpg_tab)
{
    int repeat = param.x / param.z;

    for (int i = 0; i < repeat; i++) {
        (*rect).left += param.z;
        if ((*rect).left >= param.y)
            (*rect).left = param.y;
    }
}

void animate_door_close(sfIntRect *rect, sfVector3f param, rpg_t *rpg_tab)
{
    int repeat = param.x / param.z;

    for (int i = 0; i < repeat; i++) {
        (*rect).left += param.z;
        if ((*rect).left <= param.y)
            (*rect).left = param.y;
    }
}

void change_door_hitbox(rpg_t *rpg_tab, tile_t *tile)
{
    for (int i = 0; rpg_tab->g->hitbox_tile[i] != NULL; i++) {
        if (rpg_tab->g->hitbox_tile[i]->id == tile->id) {
            if (tile->tile->sprite_rect.left == 600)
                rpg_tab->g->hitbox_tile[i]->hitbox.width = 0;
            if (tile->tile->sprite_rect.left == 0)
                rpg_tab->g->hitbox_tile[i]->hitbox =
                rpg_tab->g->hitbox_tile[i]->hitbox_saved;
        }
    }
}