/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../../include/my.h"

void display_tile_hitboxes_two(rpg_t *rpg_tab)
{
    for (int i = 0; i < rpg_tab->g->drop_list->nb_node; i++,
    rpg_tab->g->drop_node = rpg_tab->g->drop_node->next) {
        show_hitbox(rpg_tab, rpg_tab->g->drop_node->hitbox_bullet);
    } rpg_tab->g->drop_node = rpg_tab->g->drop_list->first;
    for (int i = 0; i < rpg_tab->g->gunshot_list->nb_node; i++,
    rpg_tab->g->gunshot_node = rpg_tab->g->gunshot_node->next) {
        show_hitbox(rpg_tab, rpg_tab->g->gunshot_node->hitbox_bullet);
    } rpg_tab->g->gunshot_node = rpg_tab->g->gunshot_list->first;
    show_hitbox(rpg_tab, rpg_tab->g->captain->sprite_frect);
    show_hitbox(rpg_tab, rpg_tab->g->mehdik->sprite_frect);
    show_hitbox(rpg_tab, rpg_tab->g->mehdik_quest);
}

void display_tile_hitboxes(rpg_t *rpg_tab)
{
    if (rpg_tab->g->open_door == true) {
        show_hitbox(rpg_tab, rpg_tab->g->card->big_card->sprite_frect);
        show_hitbox(rpg_tab, rpg_tab->g->card->scanner->sprite_frect);
    }
    for (int i = 0; rpg_tab->g->hitbox_tile[i] != NULL; i++)
        show_hitbox(rpg_tab, rpg_tab->g->hitbox_tile[i]->hitbox);
    show_hitbox(rpg_tab, rpg_tab->g->perso->guy_hitbox);
    for (int i = 0; i < rpg_tab->g->nb_mob; i++) {
        show_hitbox(rpg_tab, rpg_tab->g->enemy[i]->blop_hitbox);
        show_hitbox(rpg_tab, rpg_tab->g->enemy[i]->blop->sprite_frect);
    }   display_tile_hitboxes_two(rpg_tab);
}