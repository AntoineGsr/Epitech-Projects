/*
** EPITECH PROJECT, 2021
** game_mob_refr_stat.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void game_stat_refresh_mob_rd_loop(rpg_t *rpg_tab)
{
    for (int i = 0; i < rpg_tab->g->nb_mob; i++) {
        if (rpg_tab->g->enemy[i]->hp > 0) {
            rpg_tab->g->enemy[i]->blop_hitbox =
            (sfFloatRect){rpg_tab->g->enemy[i]->blop->sprite_pos.x + 30,
            rpg_tab->g->enemy[i]->blop->sprite_pos.y +
            50, 45, 35};
            rpg_tab->g->enemy[i]->blop->sprite_frect = (sfFloatRect)
            {rpg_tab->g->enemy[i]
            ->blop->sprite_pos.x - 50, rpg_tab->g->enemy[i]->blop->
            sprite_pos.y - 50, 200, 200};
            rpg_tab->g->enemy[i]->explosion = (sfFloatRect)
            {rpg_tab->g->enemy[i]
            ->blop->sprite_pos.x - 125, rpg_tab->g->enemy[i]->blop->
            sprite_pos.y - 125, 350, 350};
        }
    }
}

void game_stat_refresh_mob_nd(rpg_t *rpg_tab)
{
    rpg_tab->g->enemy[37]->blop_hitbox = (sfFloatRect) {rpg_tab->g->enemy[37]
    ->blop->sprite_pos.x + 60, rpg_tab->g->enemy[37]->blop->sprite_pos.y +
    100, 90, 70};
    rpg_tab->g->enemy[37]->blop->sprite_frect = (sfFloatRect)
    {rpg_tab->g->enemy[37]
    ->blop->sprite_pos.x - 100, rpg_tab->g->enemy[37]->blop->
    sprite_pos.y - 100, 400, 400};
    rpg_tab->g->enemy[37]->explosion = (sfFloatRect)
    {rpg_tab->g->enemy[37]
    ->blop->sprite_pos.x - 250, rpg_tab->g->enemy[37]->blop->
    sprite_pos.y - 250, 700, 700};
}

void game_stat_refresh_mob(rpg_t *rpg_tab)
{
    game_stat_refresh_mob_rd_loop(rpg_tab);
    game_stat_refresh_mob_nd(rpg_tab);
    for (int i = 0; i < 9; i++) {
        if (rpg_tab->g->inventory->case_inv[i]->inventory != false) {
            rpg_tab->g->inventory->case_inv[i]->inv_case->sprite_pos =
            pos_case_inventory(rpg_tab, i, rpg_tab->g->inventory->case_inv[i]->
            inv_case->sprite_rect.width, rpg_tab->g->inventory->case_inv[i]->
            inv_case->sprite_rect.height);
        }
    }
}