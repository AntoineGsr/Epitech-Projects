/*
** EPITECH PROJECT, 2021
** init_menu_buttons.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void init_menu_buttons_two(rpg_t *rpg_tab)
{
    rpg_tab->m->m_butt->button[3] =  get_my_sprite(rpg_tab, B_PARAM,
    (sfVector2f) {rpg_tab->m->m_wind[0]->sprite_pos.x + 194, rpg_tab->m->
    m_wind[0]->sprite_pos.y + 94}, (sfIntRect) {0, 0, 190, 51});
    rpg_tab->m->m_butt->button[4] =  get_my_sprite(rpg_tab, B_HELP,
    (sfVector2f) {rpg_tab->m->m_wind[0]->sprite_pos.x + 214, rpg_tab->m->
    m_wind[0]->sprite_pos.y + 215}, (sfIntRect) {0, 0, 109, 50});
    rpg_tab->m->m_butt->button[5] =  get_my_sprite(rpg_tab, BUTTON_SKIN_BLUE,
    (sfVector2f) {rpg_tab->m->m_wind[1]->sprite_pos.x - 15, rpg_tab->m->
    m_wind[1]->sprite_pos.y + 152}, (sfIntRect) {0, 0, 72, 78});
    for (int i = 0; i < 6; i++) {
        rpg_tab->m->m_butt->button[i]->sprite_frect = (sfFloatRect) {
        rpg_tab->m->m_butt->button[i]->sprite_pos.x,
        rpg_tab->m->m_butt->button[i]->sprite_pos.y,
        rpg_tab->m->m_butt->button[i]->sprite_rect.width,
        rpg_tab->m->m_butt->button[i]->sprite_rect.height};
    }
}

void init_menu_buttons(rpg_t *rpg_tab)
{
    rpg_tab->m->m_butt->button_state = MENU_BASE;
    rpg_tab->m->m_wind[0] = get_my_sprite(rpg_tab, EX_M_WIN,
    (sfVector2f) {25, 35}, (sfIntRect) {0, 0, 513, 410});
    rpg_tab->m->m_wind[1] = get_my_sprite(rpg_tab, M_WIN,
    (sfVector2f) {1275, 125}, (sfIntRect) {0, 0, 565, 925});
    rpg_tab->m->m_butt->button[0] =  get_my_sprite(rpg_tab, B_PLAY,
    (sfVector2f) {rpg_tab->m->m_wind[1]->sprite_pos.x + 210, rpg_tab->m->
    m_wind[1]->sprite_pos.y + 173}, (sfIntRect) {0, 0, 125, 54});
    rpg_tab->m->m_butt->button[1] =  get_my_sprite(rpg_tab, B_LOAD,
    (sfVector2f) {rpg_tab->m->m_wind[1]->sprite_pos.x + 185, rpg_tab->m->
    m_wind[1]->sprite_pos.y + 369}, (sfIntRect) {0, 0, 151, 44});
    rpg_tab->m->m_butt->button[2] =  get_my_sprite(rpg_tab, B_QUIT,
    (sfVector2f) {rpg_tab->m->m_wind[1]->sprite_pos.x + 176, rpg_tab->m->
    m_wind[1]->sprite_pos.y + 596}, (sfIntRect) {0, 0, 141, 58});
    init_menu_buttons_two(rpg_tab);
}