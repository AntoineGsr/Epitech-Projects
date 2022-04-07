/*
** EPITECH PROJECT, 2021
** drop_system.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void drop_item_mob_kill_two(rpg_t *rpg_tab, int i)
{
    if (rand() % 2 == 0) {
        rpg_tab->g->drop_node = add_node_firstpos(&rpg_tab->g->drop_list,
        &rpg_tab->g->drop_node);
        rpg_tab->g->drop_node->type_drop = my_memset_char(my_strlen(HEALTH)
        + 1);
        rpg_tab->g->drop_node->type_drop = HEALTH;
        rpg_tab->g->drop_node->button = get_my_sprite(rpg_tab,
        "assets/png/game/health_kit.png", (sfVector2f){rpg_tab->g->enemy[i]->
        blop->sprite_pos.x + 30, rpg_tab->g->enemy[i]->blop->sprite_pos.y +
        30}, (sfIntRect){0, 0, 59, 59});
        rpg_tab->g->drop_node->hitbox_bullet = (sfFloatRect){rpg_tab->g->
        drop_node->button->sprite_pos.x - 59, rpg_tab->g->drop_node->button
        ->sprite_pos.y - 59, rpg_tab->g->drop_node->button->sprite_rect.width
        * 3, rpg_tab->g->drop_node->button->sprite_rect.height * 3};
    }
}

void drop_item_mob_kill(rpg_t *rpg_tab, int i)
{
    if (rand() % 2 == 0) {
        rpg_tab->g->drop_node = add_node_firstpos
        (&rpg_tab->g->drop_list, &rpg_tab->g->drop_node);
        rpg_tab->g->drop_node->type_drop = my_memset_char(my_strlen(GUN) + 1);
        rpg_tab->g->drop_node->type_drop = GUN;
        rpg_tab->g->drop_node->button = get_my_sprite(rpg_tab,
        "assets/png/game/bullet_charger.png", (sfVector2f){
            rpg_tab->g->enemy[i]->blop->sprite_pos.x + 55,
            rpg_tab->g->enemy[i]->blop->sprite_pos.y + 55},
            (sfIntRect){0, 0, 45, 46});
        rpg_tab->g->drop_node->hitbox_bullet = (sfFloatRect)
        {rpg_tab->g->drop_node->button->sprite_pos.x - 45,
        rpg_tab->g->drop_node->button->sprite_pos.y - 46,
        rpg_tab->g->drop_node->button->sprite_rect.width * 3,
        rpg_tab->g->drop_node->button->sprite_rect.height * 3};
    } drop_item_mob_kill_two(rpg_tab, i);
}