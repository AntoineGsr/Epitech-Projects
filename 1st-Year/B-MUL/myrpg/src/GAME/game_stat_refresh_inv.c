/*
** EPITECH PROJECT, 2021
** game_stat_refresh_inv.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void refr_inv(rpg_t *rpg_tab)
{
    rpg_tab->g->inventory->inv_wind->sprite_pos =
    sfRenderWindow_mapPixelToCoords
    (rpg_tab->window, (sfVector2i)
    {coeff_window(rpg_tab->window_size.x, 320, 1920),
    coeff_window(rpg_tab->window_size.y, 180, 1080)}, rpg_tab->view);
    rpg_tab->g->inventory->skin->sprite_pos =
    (sfVector2f){rpg_tab->g->inventory->inv_wind->sprite_pos.x +
    coeff_window(rpg_tab->window_size.x, 60, 1920),
    rpg_tab->g->inventory->inv_wind->sprite_pos.y +
    coeff_window(rpg_tab->window_size.y, 34, 1080)};
    rpg_tab->g->inventory->skin->sprite_rect.top =
    rpg_tab->g->perso->guy->sprite_rect.top;
    rpg_tab->g->inventory->skin->sprite_rect.left =
    rpg_tab->g->perso->guy->sprite_rect.left;
    rpg_tab->g->inventory->stats->hp_bar->sprite_pos = (sfVector2f)
    {rpg_tab->g->inventory->inv_wind->sprite_pos.x +
    coeff_window(rpg_tab->window_size.x, 563, 1920),
    rpg_tab->g->inventory->inv_wind->sprite_pos.y +
    coeff_window(rpg_tab->window_size.y, 33, 1080)};
}

void refr_inv_nd(rpg_t *rpg_tab)
{
    rpg_tab->g->inventory->stats->xp_bar->sprite_pos = (sfVector2f)
    {rpg_tab->g->inventory->inv_wind->sprite_pos.x +
    coeff_window(rpg_tab->window_size.x, 563, 1920),
    rpg_tab->g->inventory->inv_wind->sprite_pos.y +
    coeff_window(rpg_tab->window_size.y, 133, 1080)};
    rpg_tab->g->inventory->stats->hp_bar->sprite_rect.width =
    ((float) (rpg_tab->g->var->hp) / 100.0) * 670;
}

void refr_inv_rd(rpg_t *rpg_tab)
{
    rpg_tab->g->inventory->stats->xp_bar->sprite_rect.width =
    ((float) (rpg_tab->g->var->xp % 100) / 100.0) * 670;
    sfText_setPosition(rpg_tab->g->inventory->stats->xp_txt->text,
    (sfVector2f) {rpg_tab->g->inventory->stats->xp_bar->sprite_pos.x
    + (coeff_window(rpg_tab->window_size.x, 670, 1920) / 3) +
    my_strlen(rpg_tab->g->inventory->stats->xp_txt->ctrl) * 10,
    rpg_tab->g->stats->xp_bar->sprite_pos.y + 5 + rpg_tab->g->
    inventory->stats->xp_bar->sprite_rect.height / 2});
    sfText_setPosition(rpg_tab->g->inventory->stats->hp_txt->text,
    (sfVector2f) {rpg_tab->g->inventory->stats->hp_bar->sprite_pos.x
    + (coeff_window(rpg_tab->window_size.x, 670, 1920) / 3) +
    my_strlen(rpg_tab->g->inventory->stats->hp_txt->ctrl) * 10,
    rpg_tab->g->stats->hp_bar->sprite_pos.y - rpg_tab->g->inventory->
    stats->hp_bar->sprite_rect.height / 10});
}

void refr_inv_foor(rpg_t *rpg_tab)
{
    if (my_strcmp(rpg_tab->g->stats->xp_txt->ctrl,
    rpg_tab->g->inventory->stats->xp_txt->ctrl) != 0) {
        free(rpg_tab->g->inventory->stats->xp_txt->ctrl);
        rpg_tab->g->inventory->stats->xp_txt->ctrl = my_memset_char(my_strlen
        (rpg_tab->g->stats->xp_txt->ctrl) + 1);
        rpg_tab->g->inventory->stats->xp_txt->ctrl = my_strcpy
        (rpg_tab->g->inventory->stats->xp_txt->ctrl,
        rpg_tab->g->stats->xp_txt->ctrl);
    }
    if (my_strcmp(rpg_tab->g->stats->hp_txt->ctrl,
    rpg_tab->g->inventory->stats->hp_txt->ctrl) != 0) {
        free(rpg_tab->g->inventory->stats->hp_txt->ctrl);
        rpg_tab->g->inventory->stats->hp_txt->ctrl = my_memset_char(my_strlen
        (rpg_tab->g->stats->hp_txt->ctrl) + 1);
        rpg_tab->g->inventory->stats->hp_txt->ctrl = my_strcpy
        (rpg_tab->g->inventory->stats->hp_txt->ctrl,
        rpg_tab->g->stats->hp_txt->ctrl);
    }
}

void game_stat_refresh_inventory(rpg_t *rpg_tab)
{
    refr_inv(rpg_tab);
    refr_inv_nd(rpg_tab);
    refr_inv_rd(rpg_tab);
    refr_inv_foor(rpg_tab);
    for (int i = 0; i < 9; i++) {
        if (rpg_tab->g->inventory->case_inv[i]->inventory == false)
            continue;
        rpg_tab->g->inventory->case_inv[i]->hitbox_item = (sfFloatRect)
        {rpg_tab->g->inventory->case_inv[i]->inv_case->sprite_pos.x, rpg_tab->
        g->inventory->case_inv[i]->inv_case->sprite_pos.y, rpg_tab->g->
        inventory->case_inv[i]->
        inv_case->sprite_rect.width * 2, rpg_tab->g->inventory->case_inv[i]
        ->inv_case->sprite_rect.height * 2};
    }
}