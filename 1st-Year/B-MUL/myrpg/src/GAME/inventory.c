/*
** EPITECH PROJECT, 2021
** inventory.c
** File description:
** my_rpg
*/

#include "../../include/my.h"

void health_inv_gestion(rpg_t *rpg_tab, int i)
{
    sfTexture_destroy(rpg_tab->g->inventory->case_inv[i]->
    inv_case->texture);
    sfSprite_destroy(rpg_tab->g->inventory->case_inv[i]->
    inv_case->sprite);
    free(rpg_tab->g->inventory->case_inv[i]->inv_case);
    rpg_tab->g->var->hp += 15;
    if (rpg_tab->g->var->hp > 100)
        rpg_tab->g->var->hp = 100;
    rpg_tab->g->left_click = false;
    rpg_tab->g->inventory->case_inv[i]->inventory = false;
    rpg_tab->g->var->space_bag -= 1;
}

void inv_click_call(rpg_t *rpg_tab, int i)
{
    sfTexture_destroy(rpg_tab->g->inventory->case_inv[i]->
    inv_case->texture);
    sfSprite_destroy(rpg_tab->g->inventory->case_inv[i]->
    inv_case->sprite);
    free(rpg_tab->g->inventory->case_inv[i]->inv_case);
    gestion_click_inv(rpg_tab, i);
    gestion_click_inv_two(rpg_tab, i);
    gestion_click_inv_three(rpg_tab, i);
    gestion_click_inv_foor(rpg_tab, i);
    rpg_tab->g->right_click = false;
    rpg_tab->g->inventory->case_inv[i]->inventory = false;
    rpg_tab->g->var->space_bag -= 1;
}

void gestion_hitbox_inventary(rpg_t *rpg_tab)
{
    for (int i = 0; i < 9; i++) {
        if (rpg_tab->g->left_click == true && rpg_tab->g->var->hp < 100 &&
            rpg_tab->g->inventory->case_inv[i]->inventory == 2 &&
            sfFloatRect_intersects(&rpg_tab->u->c_box,
            &rpg_tab->g->inventory->case_inv[i]->hitbox_item, NULL)
            == sfTrue) {
            health_inv_gestion(rpg_tab, i);
            break;
        }
        if (rpg_tab->g->right_click == true &&
            rpg_tab->g->inventory->case_inv[i]->inventory != false &&
            sfFloatRect_intersects(&rpg_tab->u->c_box,
            &rpg_tab->g->inventory->case_inv[i]->hitbox_item, NULL)
            == sfTrue) {
            inv_click_call(rpg_tab, i);
            break;
        }
    }
}