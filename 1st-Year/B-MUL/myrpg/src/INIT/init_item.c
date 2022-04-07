/*
** EPITECH PROJECT, 2021
** init_item.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void init_item_two(rpg_t *rpg_tab)
{
    rpg_tab->g->card->scanner = get_my_sprite(rpg_tab, CARD_SCANNER,
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 494, 524});
    rpg_tab->g->water_done = false;
    rpg_tab->g->water_grab = false;
    rpg_tab->g->can_grab_water = false;
    rpg_tab->g->drop_node = add_node_firstpos(&rpg_tab->g->drop_list,
    &rpg_tab->g->drop_node);
    rpg_tab->g->drop_node->type_drop = my_memset_char(
    my_strlen(SMALL_BIDON) + 1);
    rpg_tab->g->drop_node->type_drop = SMALL_BIDON;
    rpg_tab->g->drop_node->button = get_my_sprite(rpg_tab, SMALL_BIDON,
    (sfVector2f){2562, 628}, (sfIntRect){0, 0, 38, 61});
    rpg_tab->g->drop_node->hitbox_bullet = (sfFloatRect){rpg_tab->g->
    drop_node->button->sprite_pos.x - 38, rpg_tab->g->drop_node->button->
    sprite_pos.y - 61, rpg_tab->g->drop_node->button->sprite_rect.width * 3,
    rpg_tab->g->drop_node->button->sprite_rect.height * 3};
}

void init_item(rpg_t *rpg_tab)
{
    rpg_tab->g->var->access_card = false;
    rpg_tab->g->drop_node = add_node_firstpos(&rpg_tab->g->drop_list,
    &rpg_tab->g->drop_node);
    rpg_tab->g->drop_node->type_drop = my_memset_char(
    my_strlen(SMALL_ACCESS_CARD) + 1);
    rpg_tab->g->drop_node->type_drop = SMALL_ACCESS_CARD;
    rpg_tab->g->drop_node->button = get_my_sprite(rpg_tab, SMALL_ACCESS_CARD,
    (sfVector2f){1990, 817}, (sfIntRect){0, 0, 47, 60});
    rpg_tab->g->drop_node->hitbox_bullet = (sfFloatRect){rpg_tab->g->
    drop_node->button->sprite_pos.x - 47, rpg_tab->g->drop_node->button->
    sprite_pos.y - 60, rpg_tab->g->drop_node->button->sprite_rect.width * 3,
    rpg_tab->g->drop_node->button->sprite_rect.height * 3};
    init_item_two(rpg_tab);
}