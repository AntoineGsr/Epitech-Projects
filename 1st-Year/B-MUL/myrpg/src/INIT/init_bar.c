/*
** EPITECH PROJECT, 2021
** init_bar.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void init_bar(rpg_t *rpg_tab)
{
    rpg_tab->g->inventory->inv_wind = get_my_sprite(rpg_tab,
    "assets/png/game/inventory.png", (sfVector2f){320, 180},
    (sfIntRect){0, 0, 1280, 720});
    rpg_tab->g->stats->hp_bar = get_my_sprite(rpg_tab,
    "assets/png/game/hp_little_bar.png", (sfVector2f){0, 0},
    (sfIntRect){0, 0, 240, 28});
    rpg_tab->g->stats->xp_bar = get_my_sprite(rpg_tab,
    "assets/png/game/xp_little_bar.png", (sfVector2f){0, 0},
    (sfIntRect){0, 0, 240, 28});
    rpg_tab->g->stats->hp_color = get_my_sprite(rpg_tab,
    "assets/png/game/hp_xp_little_col.png", (sfVector2f){0, 0},
    (sfIntRect){0, 0, 223, 28});
    rpg_tab->g->stats->xp_color = get_my_sprite(rpg_tab,
    "assets/png/game/hp_xp_little_col.png", (sfVector2f){0, 0},
    (sfIntRect){0, 28, 0, 28});
    rpg_tab->g->stats->xp_txt = get_my_text("LVL.0", (sfVector2f) {0, 0},
    sfWhite, 25);
    rpg_tab->g->stats->hp_txt = get_my_text("100HP", (sfVector2f) {0, 0},
    sfWhite, 25);
}