/*
** EPITECH PROJECT, 2021
** init_txt.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void init_txt(rpg_t *rpg_tab)
{
    rpg_tab->g->drop_msg = get_my_text("Press E to grab item",
    (sfVector2f){0, 0}, sfWhite, 30);
    rpg_tab->g->door_msg = get_my_text("Press E to interact",
    (sfVector2f){0, 0}, sfWhite, 30);
    rpg_tab->g->reload_msg = get_my_text("Press R to reload",
    (sfVector2f){0, 0}, sfWhite, 30);
    rpg_tab->g->reloading = false;
    rpg_tab->g->nb_bullet = 9;
    rpg_tab->g->player_info->bag_space = get_my_text("0/9",
    (sfVector2f){0, 0}, sfWhite, 25);
    rpg_tab->g->player_info->bullet_charger = get_my_text("9/9",
    (sfVector2f){0, 0}, sfWhite, 25);
    rpg_tab->g->player_info->bag_icon = get_my_sprite(rpg_tab, ICON,
    (sfVector2f){0, 0}, (sfIntRect){0, 30, 30, 30});
    rpg_tab->g->player_info->gun_icon = get_my_sprite(rpg_tab, ICON,
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 30, 30});
    rpg_tab->g->card->big_card = get_my_sprite(rpg_tab, ACCESS_CARD,
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 326, 417});
}