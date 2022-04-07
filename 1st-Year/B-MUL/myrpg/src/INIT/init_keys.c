/*
** EPITECH PROJECT, 2021
** init_keys.c
** File description:
** my_rpg
*/

#include "../../include/my.h"

void init_keys(rpg_t *rpg_tab)
{
    rpg_tab->keys->up = sfKeyZ;
    rpg_tab->keys->down = sfKeyS;
    rpg_tab->keys->left = sfKeyQ;
    rpg_tab->keys->right = sfKeyD;
    rpg_tab->keys->game_menu = sfKeyEscape;
    rpg_tab->keys->inventory = sfKeyI;
    rpg_tab->keys->interaction = sfKeyE;
    rpg_tab->keys->switch_weapon = sfKeyF;
    rpg_tab->keys->reload = sfKeyR;
    rpg_tab->keys->nb_pressed = 0;
    rpg_tab->keys->mv_up = false;
    rpg_tab->keys->mv_down = false;
    rpg_tab->keys->mv_right = false;
    rpg_tab->keys->mv_left = false;
}