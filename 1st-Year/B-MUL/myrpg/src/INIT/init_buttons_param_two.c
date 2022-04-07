/*
** EPITECH PROJECT, 2021
** init_param_buttons_two.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void init_sprite_param_two(rpg_t *rpg_tab)
{
    rpg_tab->m->p_butt->button[11] =  get_my_sprite(rpg_tab, BP_DIRECTION,
    (sfVector2f) {rpg_tab->m->p_butt->p_wind[2]->sprite_pos.x + 346, rpg_tab->
    m->p_butt->p_wind[2]->sprite_pos.y + 49}, (sfIntRect) {0, 0, 55, 45});
    rpg_tab->m->p_butt->button[12] =  get_my_sprite(rpg_tab, BP_DIRECTION,
    (sfVector2f) {rpg_tab->m->p_butt->p_wind[2]->sprite_pos.x + 340, rpg_tab->
    m->p_butt->p_wind[2]->sprite_pos.y + 82}, (sfIntRect) {0, 0, 55, 45});
    rpg_tab->m->p_butt->button[13] =  get_my_sprite(rpg_tab, BP_DIRECTION,
    (sfVector2f) {rpg_tab->m->p_butt->p_wind[2]->sprite_pos.x + 334, rpg_tab->
    m->p_butt->p_wind[2]->sprite_pos.y + 115}, (sfIntRect) {0, 0, 55, 45});
    rpg_tab->m->p_butt->button[14] =  get_my_sprite(rpg_tab, BP_DIRECTION,
    (sfVector2f) {rpg_tab->m->p_butt->p_wind[2]->sprite_pos.x + 330, rpg_tab->
    m->p_butt->p_wind[2]->sprite_pos.y + 150}, (sfIntRect) {0, 0, 55, 45});
    for (int i = 0; i < 9; i++) {
        rpg_tab->m->p_butt->key[i] = malloc(sizeof(keys_t));
        rpg_tab->m->p_butt->key[i]->ctrl = my_memset_char(4);
    }
}

void init_sprite_param(rpg_t *rpg_tab)
{
    rpg_tab->m->p_butt->button[0]->sprite_rect.width =
    rpg_tab->config->sound_vol;
    rpg_tab->m->p_butt->button[1]->sprite_rect.width =
    rpg_tab->config->music_vol;
    rpg_tab->m->p_butt->button[6] =  get_my_sprite(rpg_tab, BP_GM,
    (sfVector2f) {rpg_tab->m->p_butt->p_wind[1]->sprite_pos.x + 390, rpg_tab->
    m->p_butt->p_wind[1]->sprite_pos.y + 61}, (sfIntRect) {0, 0, 63, 41});
    rpg_tab->m->p_butt->button[7] =  get_my_sprite(rpg_tab, BP_INV,
    (sfVector2f) {rpg_tab->m->p_butt->p_wind[1]->sprite_pos.x + 381, rpg_tab->
    m->p_butt->p_wind[1]->sprite_pos.y + 106}, (sfIntRect) {0, 0, 62, 42});
    rpg_tab->m->p_butt->button[8] =  get_my_sprite(rpg_tab, BP_INTERACT,
    (sfVector2f) {rpg_tab->m->p_butt->p_wind[1]->sprite_pos.x + 373, rpg_tab->
    m->p_butt->p_wind[1]->sprite_pos.y + 149}, (sfIntRect) {0, 0, 62, 43});
    rpg_tab->m->p_butt->button[9] =  get_my_sprite(rpg_tab, BP_SWITCH,
    (sfVector2f) {rpg_tab->m->p_butt->p_wind[1]->sprite_pos.x + 366, rpg_tab->
    m->p_butt->p_wind[1]->sprite_pos.y + 190}, (sfIntRect) {0, 0, 61, 44});
    rpg_tab->m->p_butt->button[10] =  get_my_sprite(rpg_tab, BP_MAP,
    (sfVector2f) {rpg_tab->m->p_butt->p_wind[1]->sprite_pos.x + 356, rpg_tab->
    m->p_butt->p_wind[1]->sprite_pos.y + 232}, (sfIntRect) {0, 0, 62, 43});
}