/*
** EPITECH PROJECT, 2021
** gestion_inv_extra.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void gestion_click_inv_foor(rpg_t *rpg_tab, int i)
{
    if (rpg_tab->g->inventory->case_inv[i]->inventory == 4) {
        rpg_tab->g->var->water_bidon = false;
        rpg_tab->g->drop_node = add_node_firstpos(&rpg_tab->g->drop_list,
        &rpg_tab->g->drop_node);
        rpg_tab->g->drop_node->type_drop =
        my_memset_char(my_strlen(SMALL_BIDON) + 1);
        rpg_tab->g->drop_node->type_drop = SMALL_BIDON;
        rpg_tab->g->drop_node->button = get_my_sprite(rpg_tab, SMALL_BIDON,
        (sfVector2f){rpg_tab->g->perso->guy->sprite_pos.x + 45, rpg_tab->g->
        perso->guy->sprite_pos.y + 45}, (sfIntRect){0, 0, 38, 61});
        rpg_tab->g->drop_node->hitbox_bullet = (sfFloatRect){rpg_tab->g->
        drop_node->button->sprite_pos.x - 38, rpg_tab->g->drop_node->button->
        sprite_pos.y - 61, rpg_tab->g->drop_node->button->
        sprite_rect.width * 3, rpg_tab->g->drop_node->button->
        sprite_rect.height * 3};
    }
}

void gestion_click_inv_three(rpg_t *rpg_tab, int i)
{
    if (rpg_tab->g->inventory->case_inv[i]->inventory == 3) {
        rpg_tab->g->var->access_card = false;
        rpg_tab->g->drop_node = add_node_firstpos(&rpg_tab->g->drop_list,
        &rpg_tab->g->drop_node);
        rpg_tab->g->drop_node->type_drop =
        my_memset_char(my_strlen(SMALL_ACCESS_CARD) + 1);
        rpg_tab->g->drop_node->type_drop = SMALL_ACCESS_CARD;
        rpg_tab->g->drop_node->button = get_my_sprite(rpg_tab,
        SMALL_ACCESS_CARD, (sfVector2f){rpg_tab->g->perso->guy->
        sprite_pos.x + 45, rpg_tab->g->perso->guy->sprite_pos.y + 45},
        (sfIntRect){0, 0, 47, 60});
        rpg_tab->g->drop_node->hitbox_bullet = (sfFloatRect){rpg_tab->g->
        drop_node->button->sprite_pos.x - 47, rpg_tab->g->drop_node->button->
        sprite_pos.y - 60, rpg_tab->g->drop_node->button->
        sprite_rect.width * 3, rpg_tab->g->drop_node->button->
        sprite_rect.height * 3};
    }
}

void gestion_click_inv_two(rpg_t *rpg_tab, int i)
{
    if (rpg_tab->g->inventory->case_inv[i]->inventory == 2) {
        rpg_tab->g->drop_node = add_node_firstpos(&rpg_tab->g->drop_list,
        &rpg_tab->g->drop_node);
        rpg_tab->g->drop_node->type_drop =
        my_memset_char(my_strlen(HEALTH) + 1);
        rpg_tab->g->drop_node->type_drop = HEALTH;
        rpg_tab->g->drop_node->button = get_my_sprite(rpg_tab, HEALTH,
        (sfVector2f){rpg_tab->g->perso->guy->sprite_pos.x + 45, rpg_tab->g->
        perso->guy->sprite_pos.y + 45}, (sfIntRect){0, 0, 59, 59});
        rpg_tab->g->drop_node->hitbox_bullet = (sfFloatRect){rpg_tab->g->
        drop_node->button->sprite_pos.x - 59, rpg_tab->g->drop_node->button->
        sprite_pos.y - 59, rpg_tab->g->drop_node->button->
        sprite_rect.width * 3, rpg_tab->g->drop_node->button->
        sprite_rect.height * 3};
    }
}

void gestion_click_inv(rpg_t *rpg_tab, int i)
{
    if (rpg_tab->g->inventory->case_inv[i]->inventory == 1) {
        rpg_tab->g->drop_node = add_node_firstpos(&rpg_tab->g->
        drop_list, &rpg_tab->g->drop_node);
        rpg_tab->g->drop_node->type_drop = my_memset_char(my_strlen(GUN) + 1);
        rpg_tab->g->drop_node->type_drop = GUN;
        rpg_tab->g->drop_node->button = get_my_sprite(rpg_tab, GUN,
        (sfVector2f){rpg_tab->g->perso->guy->sprite_pos.x + 55, rpg_tab->g->
        perso->guy->sprite_pos.y + 55}, (sfIntRect){0, 0, 45, 46});
        rpg_tab->g->drop_node->hitbox_bullet = (sfFloatRect){rpg_tab->g->
        drop_node->button->sprite_pos.x - 45, rpg_tab->g->drop_node->button->
        sprite_pos.y - 46, rpg_tab->g->drop_node->button->
        sprite_rect.width * 3, rpg_tab->g->drop_node->button->
        sprite_rect.height * 3};
    }
}