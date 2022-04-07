/*
** EPITECH PROJECT, 2021
** parse_save.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void update_var_game_five(rpg_t *rpg_tab, int i, sfVector2f *pos_item)
{
    if (rpg_tab->g->inventory->case_inv[i]->inventory == 3) {
        *pos_item = pos_case_inventory(rpg_tab, i, 47, 60);
        rpg_tab->g->inventory->case_inv[i]->inv_case = get_my_sprite
        (rpg_tab, SMALL_ACCESS_CARD, *pos_item,
        (sfIntRect){0, 0, 47, 60});
        rpg_tab->g->inventory->case_inv[i]->hitbox_item = (sfFloatRect)
        {(*pos_item).x, (*pos_item).y, 47 * 2, 60 * 2};
        rpg_tab->g->var->space_bag += 1;
    }
    if (rpg_tab->g->inventory->case_inv[i]->inventory == 4) {
        *pos_item = pos_case_inventory(rpg_tab, i, 38, 61);
        rpg_tab->g->inventory->case_inv[i]->inv_case = get_my_sprite
        (rpg_tab, SMALL_BIDON, *pos_item,
        (sfIntRect){0, 0, 47, 60});
        rpg_tab->g->inventory->case_inv[i]->hitbox_item = (sfFloatRect)
        {(*pos_item).x, (*pos_item).y, 438 * 2, 61 * 2};
        rpg_tab->g->var->space_bag += 1;
    }
}

void update_var_game_four(rpg_t *rpg_tab, int i, sfVector2f *pos_item)
{
    if (rpg_tab->g->inventory->case_inv[i]->inventory == 1) {
        *pos_item = pos_case_inventory(rpg_tab, i, 45, 46);
        rpg_tab->g->inventory->case_inv[i]->inv_case = get_my_sprite
        (rpg_tab, GUN, *pos_item,
        (sfIntRect){0, 0, 45, 46});
        rpg_tab->g->inventory->case_inv[i]->hitbox_item = (sfFloatRect)
        {(*pos_item).x, (*pos_item).y, 45 * 2, 46 * 2};
        rpg_tab->g->var->space_bag += 1;
    }
    if (rpg_tab->g->inventory->case_inv[i]->inventory == 2) {
        *pos_item = pos_case_inventory(rpg_tab, i, 59, 59);
        rpg_tab->g->inventory->case_inv[i]->inv_case = get_my_sprite
        (rpg_tab, HEALTH, *pos_item,
        (sfIntRect){0, 0, 59, 59});
        rpg_tab->g->inventory->case_inv[i]->hitbox_item = (sfFloatRect)
        {(*pos_item).x, (*pos_item).y, 59 * 2, 59 * 2};
        rpg_tab->g->var->space_bag += 1;
    }
}

void update_var_game_three(rpg_t *rpg_tab)
{
    rpg_tab->g->var->water_bidon = my_getnbr(rpg_tab->m->l_butt->parsing[58]);
    rpg_tab->g->water_done = my_getnbr(rpg_tab->m->l_butt->parsing[59]);
    if (rpg_tab->g->var->water_bidon == true) {
        int a = 0;
        for (; a < rpg_tab->g->drop_list->nb_node - 2; a++,
        rpg_tab->g->drop_node = rpg_tab->g->drop_node->next);
        destroy_node_noloop(&rpg_tab->g->drop_list,
        &rpg_tab->g->drop_node, &a);
            rpg_tab->g->drop_node = rpg_tab->g->drop_list->first;
    }
    if (rpg_tab->g->var->access_card == true) {
        int i = 0;
        for (; i < rpg_tab->g->drop_list->nb_node - 1; i++,
        rpg_tab->g->drop_node = rpg_tab->g->drop_node->next);
        destroy_node_noloop(&rpg_tab->g->drop_list,
        &rpg_tab->g->drop_node, &i);
        rpg_tab->g->drop_node = rpg_tab->g->drop_list->first;
    }
}

void update_var_game_two(rpg_t *rpg_tab)
{
    rpg_tab->g->var->gun_dmg = my_getnbr(rpg_tab->m->l_butt->parsing[8]);
    rpg_tab->g->inventory->case_inv[0]->inventory = my_getnbr(
        rpg_tab->m->l_butt->parsing[9]);
    rpg_tab->g->inventory->case_inv[1]->inventory = my_getnbr(
        rpg_tab->m->l_butt->parsing[10]);
    rpg_tab->g->inventory->case_inv[2]->inventory  = my_getnbr(
        rpg_tab->m->l_butt->parsing[11]);
    rpg_tab->g->inventory->case_inv[3]->inventory  = my_getnbr(
        rpg_tab->m->l_butt->parsing[12]);
    rpg_tab->g->inventory->case_inv[4]->inventory  = my_getnbr(
        rpg_tab->m->l_butt->parsing[13]);
    rpg_tab->g->inventory->case_inv[5]->inventory  = my_getnbr(
        rpg_tab->m->l_butt->parsing[14]);
    rpg_tab->g->inventory->case_inv[6]->inventory  = my_getnbr(
        rpg_tab->m->l_butt->parsing[52]);
    rpg_tab->g->inventory->case_inv[7]->inventory  = my_getnbr(
        rpg_tab->m->l_butt->parsing[53]);
    rpg_tab->g->inventory->case_inv[8]->inventory  = my_getnbr(
        rpg_tab->m->l_butt->parsing[54]);
    rpg_tab->g->var->access_card = my_getnbr(rpg_tab->m->l_butt->parsing[55]);
}

void update_var_game(rpg_t *rpg_tab)
{
    sfVector2f pos_item;
    free(rpg_tab->g->var->skin);
    rpg_tab->g->var->skin = my_memset_char(my_strlen
    (rpg_tab->m->l_butt->parsing[1]) + 27);
    rpg_tab->g->var->skin = my_strcpy(rpg_tab->g->var->skin,
    "assets/png/util/character_");
    rpg_tab->g->var->skin = my_strcat(rpg_tab->g->var->skin,
    rpg_tab->m->l_butt->parsing[1]);
    rpg_tab->g->var->quest = my_getnbr(rpg_tab->m->l_butt->parsing[2]);
    rpg_tab->g->var->xp = my_getnbr(rpg_tab->m->l_butt->parsing[3]);
    rpg_tab->g->var->hp = my_getnbr(rpg_tab->m->l_butt->parsing[4]);
    rpg_tab->g->var->bandage = my_getnbr(rpg_tab->m->l_butt->parsing[5]);
    rpg_tab->g->var->gun_charger = my_getnbr(rpg_tab->m->l_butt->parsing[6]);
    rpg_tab->g->var->katana_dmg = my_getnbr(rpg_tab->m->l_butt->parsing[7]);
    update_var_game_zero(rpg_tab, pos_item);
}