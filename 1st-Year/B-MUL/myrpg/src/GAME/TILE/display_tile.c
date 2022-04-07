/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../../include/my.h"

void display_one_tile(rpg_t *rpg_tab, tile_t ***tiles)
{
    for (int i = 0; tiles[i] != NULL; i++) {
        for (int j = 0; tiles[i][j] != NULL; j++) {
            if (tiles[i][j]->tile != NULL) {
                sfRenderWindow_drawSprite(rpg_tab->window,
                tiles[i][j]->tile->sprite, NULL);
            }
        }
    }
}

void display_tiles(rpg_t *rpg_tab)
{
    display_one_tile(rpg_tab, rpg_tab->g->all_tiles->under_tiles);
    display_one_tile(rpg_tab, rpg_tab->g->all_tiles->wall_tiles);
    display_one_tile(rpg_tab, rpg_tab->g->all_tiles->upper_tiles);
}