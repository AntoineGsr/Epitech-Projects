/*
** EPITECH PROJECT, 2021
** init_inventory.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void init_inventory(rpg_t *rpg_tab)
{
    for (int i = 0; i < 9; i++)
        rpg_tab->g->inventory->case_inv[i] = malloc(sizeof(case_t));
    for (int i = 0; i < 9; i++)
        rpg_tab->g->inventory->case_inv[i]->inventory = false;
    rpg_tab->g->inventory->skin = get_my_sprite(rpg_tab, rpg_tab->g->var->skin,
    (sfVector2f){34, 34}, (sfIntRect){0, 0, 100, 100});
    rpg_tab->g->inventory->stats->hp_bar = get_my_sprite(rpg_tab,
    "assets/png/game/life_and_xp_bar.png", (sfVector2f){0, 0},
    (sfIntRect){0, 0, 670, 84});
    rpg_tab->g->inventory->stats->xp_bar = get_my_sprite(rpg_tab,
    "assets/png/game/life_and_xp_bar.png", (sfVector2f){0, 0},
    (sfIntRect){0, 84, 670, 84});
    rpg_tab->g->inventory->stats->xp_txt = get_my_text("LVL.0",
    (sfVector2f){0, 0}, sfWhite, 40);
    rpg_tab->g->inventory->stats->hp_txt = get_my_text("100HP",
    (sfVector2f){0, 0}, sfWhite, 40);
    rpg_tab->g->left_click = false;
    rpg_tab->g->right_click = false;
    rpg_tab->g->drop_list->nb_node = 0;
    rpg_tab->g->drop_list->first = NULL;
}