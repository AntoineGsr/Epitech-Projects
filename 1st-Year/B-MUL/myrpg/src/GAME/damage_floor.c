/*
** EPITECH PROJECT, 2021
** entity_gestion.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void gestion_damage_floor(rpg_t *rpg_tab)
{
    if (rpg_tab->g->perso->guy->sprite_pos.x < 10288)
        return;
    for (int i = 0; rpg_tab->g->all_tiles->under_tiles[i] != NULL; i++) {
        for (int j = 0; rpg_tab->g->all_tiles->under_tiles[i][j] != NULL; j++) {
            if (rpg_tab->g->all_tiles->under_tiles[i][j]->tile_type != VOID
            && rpg_tab->g->all_tiles->under_tiles[i][j]->x_tile == 100
            && rpg_tab->g->all_tiles->under_tiles[i][j]->y_tile == 1000
            && sfFloatRect_intersects(&rpg_tab->g->perso->guy_hitbox,
            &((sfFloatRect) {rpg_tab->g->all_tiles->under_tiles[i][j]->
            tile->sprite_pos.x,
            rpg_tab->g->all_tiles->under_tiles[i][j]->tile->sprite_pos.y,
            100, 100}), NULL) && sfClock_getElapsedTime(rpg_tab->g->perso->
            floor_damage_clock).microseconds / 1000000.0 > 0.5) {
                sfClock_restart(rpg_tab->g->perso->floor_damage_clock);
                rpg_tab->g->var->hp = rpg_tab->g->var->hp - 5;
                return;
            }
        }
    }
}