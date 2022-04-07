/*
** EPITECH PROJECT, 2021
** reload_gun.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void reaload_gun(rpg_t *rpg_tab)
{
    for (int i = 8; i >= 0; i--) {
        if (rpg_tab->g->inventory->case_inv[i]->inventory == 1) {
            sfTexture_destroy(rpg_tab->g->inventory->case_inv[i]->
            inv_case->texture);
            sfSprite_destroy(rpg_tab->g->inventory->case_inv[i]->
            inv_case->sprite);
            free(rpg_tab->g->inventory->case_inv[i]->inv_case);
            rpg_tab->g->nb_bullet = 9;
            rpg_tab->g->reloading = false;
            rpg_tab->g->inventory->case_inv[i]->inventory = false;
            rpg_tab->g->var->space_bag -= 1;
            break;
        }
    }
}