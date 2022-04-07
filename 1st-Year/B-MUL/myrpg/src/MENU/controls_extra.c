/*
** EPITECH PROJECT, 2021
** param.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void print_controlls(rpg_t *rpg_tab, int i)
{
    sfText_setPosition(rpg_tab->m->p_butt->key[i]->text, rpg_tab->
    m->p_butt->key[i]->text_pos);
    sfText_setString(rpg_tab->m->p_butt->key[i]->text,
    rpg_tab->m->p_butt->key[i]->ctrl);
    sfRenderWindow_drawText(rpg_tab->window, rpg_tab->m->p_butt->key[i]->text,
    NULL);
}

void display_param_buttons(rpg_t *rpg_tab)
{
    for (int i = 0; i < 3; i++) {
        sfSprite_setTextureRect(rpg_tab->m->p_butt->p_wind[i]->sprite,
        rpg_tab->m->p_butt->p_wind[i]->sprite_rect);
        sfRenderWindow_drawSprite(rpg_tab->window,
        rpg_tab->m->p_butt->p_wind[i]->sprite, NULL);
    }
    for (int i = 0; i < 15; i++) {
        sfSprite_setTextureRect(rpg_tab->m->p_butt->button[i]->sprite,
        rpg_tab->m->p_butt->button[i]->sprite_rect);
        sfRenderWindow_drawSprite(rpg_tab->window,
        rpg_tab->m->p_butt->button[i]->sprite, NULL);
        if (i < 9)
            print_controlls(rpg_tab, i);
    }
}

void check_controls_mod_two_ex(rpg_t *rpg_tab, int i)
{
    if (i == 6)
        rpg_tab->keys->game_menu = rpg_tab->event.key.code;
    if (i == 7)
        rpg_tab->keys->inventory = rpg_tab->event.key.code;
    if (i == 8)
        rpg_tab->keys->interaction = rpg_tab->event.key.code;
    if (i == 9)
        rpg_tab->keys->switch_weapon = rpg_tab->event.key.code;
    if (i == 10)
        rpg_tab->keys->reload = rpg_tab->event.key.code;
    if (i == 11)
        rpg_tab->keys->up = rpg_tab->event.key.code;
    if (i == 12)
        rpg_tab->keys->down = rpg_tab->event.key.code;
    if (i == 13)
        rpg_tab->keys->right = rpg_tab->event.key.code;
    if (i == 14)
        rpg_tab->keys->left = rpg_tab->event.key.code;
}

void check_controls_txt_two_ex(rpg_t *rpg_tab, int i)
{
    if (rpg_tab->event.text.unicode < 128) {
        free(rpg_tab->m->p_butt->key[i - 6]->ctrl);
        if (rpg_tab->event.text.unicode == 9
            || rpg_tab->event.text.unicode == 27
            || rpg_tab->event.text.unicode == 32) {
            check_controls_txt_three(rpg_tab, i);
        } else {
            rpg_tab->m->p_butt->key[i - 6]->ctrl = my_memset_char(2);
            rpg_tab->m->p_butt->key[i - 6]->ctrl[0] =
            rpg_tab->event.text.unicode;
            rpg_tab->m->p_butt->key[i - 6]->text_pos.x =
            rpg_tab->m->p_butt->button[i]->sprite_pos.x + 30 - i + 6;
        }
    }
}