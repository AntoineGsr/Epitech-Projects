/*
** EPITECH PROJECT, 2021
** init_buttons_param.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void init_param_buttons_three(rpg_t *rpg_tab)
{
    rpg_tab->m->p_butt->button[3] =  get_my_sprite(rpg_tab, B_SIXTY,
    (sfVector2f) {rpg_tab->m->p_butt->p_wind[0]->sprite_pos.x + 211, rpg_tab->
    m->p_butt->p_wind[0]->sprite_pos.y + 646}, (sfIntRect) {189, 0, 63, 62});
    rpg_tab->m->p_butt->button[4] =  get_my_sprite(rpg_tab, B_HUNDRED,
    (sfVector2f) {rpg_tab->m->p_butt->p_wind[0]->sprite_pos.x + 350, rpg_tab->
    m->p_butt->p_wind[0]->sprite_pos.y + 669}, (sfIntRect) {0, 0, 63, 62});
    rpg_tab->m->p_butt->button[5] =  get_my_sprite(rpg_tab, BP_BACK,
    (sfVector2f) {rpg_tab->m->p_butt->p_wind[0]->sprite_pos.x + 181, rpg_tab->
    m->p_butt->p_wind[0]->sprite_pos.y + 738}, (sfIntRect) {0, 0, 124, 60});
    for (int i = 0; i < 6; i++) {
        rpg_tab->m->p_butt->button[i]->sprite_frect = (sfFloatRect) {
        rpg_tab->m->p_butt->button[i]->sprite_pos.x,
        rpg_tab->m->p_butt->button[i]->sprite_pos.y,
        rpg_tab->m->p_butt->button[i]->sprite_rect.width,
        rpg_tab->m->p_butt->button[i]->sprite_rect.height};
    }
}

void init_param_buttons_two(rpg_t *rpg_tab)
{
    rpg_tab->m->p_butt->offset = malloc(sizeof(int) * 2);
    rpg_tab->m->p_butt->offset[0] = 273;
    rpg_tab->m->p_butt->offset[1] = 265;
    rpg_tab->m->p_butt->button_state = PARAM_BASE;
    rpg_tab->m->p_butt->p_wind[0] = get_my_sprite(rpg_tab, P_WIN,
    (sfVector2f) {1275, 125}, (sfIntRect) {0, 0, 565, 925});
    rpg_tab->m->p_butt->p_wind[1] = get_my_sprite(rpg_tab, EX_P_WIN,
    (sfVector2f) {25, 35}, (sfIntRect) {0, 0, 513, 410});
    rpg_tab->m->p_butt->p_wind[2] = get_my_sprite(rpg_tab, DIR_WIN,
    (sfVector2f) {28, 340}, (sfIntRect) {0, 0, 454, 353});
    rpg_tab->m->p_butt->button[0] =  get_my_sprite(rpg_tab, S_BAR,
    (sfVector2f) {rpg_tab->m->p_butt->p_wind[0]->sprite_pos.x + 139, rpg_tab->
    m->p_butt->p_wind[0]->sprite_pos.y + 432}, (sfIntRect) {0, 0, 273, 29});
    rpg_tab->m->p_butt->button[1] =  get_my_sprite(rpg_tab, M_BAR,
    (sfVector2f) {rpg_tab->m->p_butt->p_wind[0]->sprite_pos.x + 152, rpg_tab->
    m->p_butt->p_wind[0]->sprite_pos.y + 216}, (sfIntRect) {0, 0, 265, 44});
    rpg_tab->m->p_butt->button[2] =  get_my_sprite(rpg_tab, B_THIRTY,
    (sfVector2f) {rpg_tab->m->p_butt->p_wind[0]->sprite_pos.x + 76, rpg_tab->
    m->p_butt->p_wind[0]->sprite_pos.y + 623}, (sfIntRect) {0, 0, 63, 62});
}

void init_txt_malloc(rpg_t *rpg_tab, int i)
{
    rpg_tab->m->p_butt->key[i - 6]->font = sfFont_createFromFile
    ("./assets/font/arial.ttf");
    rpg_tab->m->p_butt->key[i - 6]->text = sfText_create();
    sfText_setFont(rpg_tab->m->p_butt->key[i - 6]->text, rpg_tab->
    m->p_butt->key[i - 6]->font);
    sfText_setColor(rpg_tab->m->p_butt->key[i - 6]->text, sfWhite);
    sfText_setCharacterSize(rpg_tab->m->p_butt->key[i - 6]->text, 18);
    sfText_setRotation(rpg_tab->m->p_butt->key[i - 6]->text, -5);
    rpg_tab->m->p_butt->key[i - 6]->text_pos = (sfVector2f){
    rpg_tab->m->p_butt->button[i]->sprite_pos.x + 30 - i + 6,
    rpg_tab->m->p_butt->button[i]->sprite_pos.y + 10};
    if (my_strlen(rpg_tab->m->p_butt->key[i - 6]->ctrl) != 1)
        rpg_tab->m->p_butt->key[i - 6]->text_pos.x =
        rpg_tab->m->p_butt->button[i]->sprite_pos.x + 15 + i - 6;
    sfText_setPosition(rpg_tab->m->p_butt->key[i - 6]->text, rpg_tab->
    m->p_butt->key[i - 6]->text_pos);
}

void init_param_buttons(rpg_t *rpg_tab)
{
    init_param_buttons_two(rpg_tab);
    init_param_buttons_three(rpg_tab);
    init_sprite_param(rpg_tab);
    init_sprite_param_two(rpg_tab);
    init_txt_keys(rpg_tab);
    for (int i = 6; i < 15; i++) {
        rpg_tab->m->p_butt->button[i]->sprite_frect = (sfFloatRect) {
        rpg_tab->m->p_butt->button[i]->sprite_pos.x,
        rpg_tab->m->p_butt->button[i]->sprite_pos.y + 5,
        rpg_tab->m->p_butt->button[i]->sprite_rect.width,
        rpg_tab->m->p_butt->button[i]->sprite_rect.height - 5};
        init_txt_malloc(rpg_tab, i);
    }
}