/*
** EPITECH PROJECT, 2021
** pos_case_inv.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

sfVector2f pos_st(rpg_t *rpg_tab, int box, int width, int height)
{
    sfVector2f pos = {0, 0};

    if (box % 3 == 0)
        pos.x = rpg_tab->g->inventory->inv_wind->sprite_pos.x +
        coeff_window(rpg_tab->window_size.x, 537, 1920) +
        coeff_window(rpg_tab->window_size.x, 113, 1920) -
        width / 2;
    if (box % 3 == 1)
        pos.x = rpg_tab->g->inventory->inv_wind->sprite_pos.x +
        coeff_window(rpg_tab->window_size.x, 777, 1920) +
        coeff_window(rpg_tab->window_size.x, 113, 1920) -
        width / 2;
    if (box % 3 == 2)
        pos.x = rpg_tab->g->inventory->inv_wind->sprite_pos.x +
        coeff_window(rpg_tab->window_size.x, 1017, 1920) +
        coeff_window(rpg_tab->window_size.x, 113, 1920) -
        width / 2;
    return (pos);
}

sfVector2f pos_case_inventory(rpg_t *rpg_tab, int box, int width, int height)
{
    sfVector2f pos = {0, 0};

    pos = pos_st(rpg_tab, box, width, height);
    if (box < 3)
        pos.y = rpg_tab->g->inventory->inv_wind->sprite_pos.y +
        coeff_window(rpg_tab->window_size.y, 257, 1080) +
        coeff_window(rpg_tab->window_size.y, 60, 1080);
    if (box >= 3 && box < 6)
        pos.y = rpg_tab->g->inventory->inv_wind->sprite_pos.y +
        coeff_window(rpg_tab->window_size.y, 400, 1080) +
        coeff_window(rpg_tab->window_size.y, 60, 1080);
    if (box >= 6)
        pos.y = rpg_tab->g->inventory->inv_wind->sprite_pos.y +
        coeff_window(rpg_tab->window_size.y, 543, 1080) +
        coeff_window(rpg_tab->window_size.y, 60, 1080);
    return (pos);
}