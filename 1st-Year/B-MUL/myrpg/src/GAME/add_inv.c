/*
** EPITECH PROJECT, 2021
** add_inv.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void add_inv_two(rpg_t *rpg_tab, int i)
{
    if (my_strcmp(GUN, rpg_tab->g->drop_node->type_drop) == 0) {
        rpg_tab->g->inventory->case_inv[i]->inventory = 1;
    }
    if (my_strcmp(HEALTH, rpg_tab->g->drop_node->type_drop) == 0) {
        rpg_tab->g->inventory->case_inv[i]->inventory = 2;
    }
    if (my_strcmp(SMALL_ACCESS_CARD, rpg_tab->g->drop_node->type_drop) == 0) {
        rpg_tab->g->var->access_card = true;
        rpg_tab->g->inventory->case_inv[i]->inventory = 3;
    }
    if (my_strcmp(SMALL_BIDON, rpg_tab->g->drop_node->type_drop) == 0) {
        rpg_tab->g->var->water_bidon = true;
        rpg_tab->g->inventory->case_inv[i]->inventory = 4;
    }
    rpg_tab->g->var->space_bag += 1;
}

int add_inventory(rpg_t *rpg_tab)
{
    sfVector2f pos_item = (sfVector2f) {0, 0};

    for (int i = 0; i < 9; i++) {
        if (rpg_tab->g->inventory->case_inv[i]->inventory == false) {
            pos_item = pos_case_inventory(rpg_tab, i, rpg_tab->g->
            drop_node->button->sprite_rect.width, rpg_tab->g->drop_node->button
            ->sprite_rect.height);
            rpg_tab->g->inventory->case_inv[i]->inv_case = get_my_sprite
            (rpg_tab, rpg_tab->g->drop_node->type_drop, pos_item,
            (sfIntRect){0, 0, rpg_tab->g->drop_node->button->sprite_rect.width,
            rpg_tab->g->drop_node->button->sprite_rect.height});
            rpg_tab->g->inventory->case_inv[i]->hitbox_item = (sfFloatRect)
            {pos_item.x, pos_item.y, rpg_tab->g->inventory->case_inv[i]->
            inv_case->sprite_rect.width * 2, rpg_tab->g->inventory->case_inv[i]
            ->inv_case->sprite_rect.height * 2};
            add_inv_two(rpg_tab, i);
            return (1);
        }
    }
    return (0);
}