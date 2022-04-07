/*
** EPITECH PROJECT, 2021
** param_buttons.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void param_buttons_click_three(rpg_t *rpg_tab)
{
    if (rpg_tab->m->p_butt->button_state == PARAM_60FPS) {
        rpg_tab->m->p_butt->button[2]->sprite_rect.left = 0;
        rpg_tab->m->p_butt->button[4]->sprite_rect.left = 0;
        rpg_tab->m->p_butt->button[3]->sprite_rect.left =
        2 * rpg_tab->m->p_butt->button[3]->sprite_rect.width;
        sfRenderWindow_setFramerateLimit(rpg_tab->window, 60);
        rpg_tab->config->fps = 60;
    } if (rpg_tab->m->p_butt->button_state == PARAM_120FPS) {
        rpg_tab->m->p_butt->button[2]->sprite_rect.left = 0;
        rpg_tab->m->p_butt->button[3]->sprite_rect.left = 0;
        rpg_tab->m->p_butt->button[4]->sprite_rect.left =
        2 * rpg_tab->m->p_butt->button[4]->sprite_rect.width;
        sfRenderWindow_setFramerateLimit(rpg_tab->window, 120);
        rpg_tab->config->fps = 120;
    } rpg_tab->mouse_left_click = 1;
}

void param_buttons_click_two(rpg_t *rpg_tab)
{
    if (rpg_tab->m->p_butt->button_state == PARAM_MUSIC) {
        rpg_tab->m->p_butt->button[1]->sprite_rect.width = rpg_tab->event.
        mouseButton.x - (rpg_tab->m->p_butt->button[1]->sprite_pos.x / 1920)
        * sfRenderWindow_getSize(rpg_tab->window).x;
        if (rpg_tab->m->p_butt->button[1]->sprite_rect.width < 0)
            rpg_tab->m->p_butt->button[1]->sprite_rect.width = 0;
        if (rpg_tab->m->p_butt->button[1]->sprite_rect.width > 265)
            rpg_tab->m->p_butt->button[1]->sprite_rect.width = 265;
    } if (rpg_tab->m->p_butt->button_state == PARAM_30FPS) {
        rpg_tab->m->p_butt->button[3]->sprite_rect.left = 0;
        rpg_tab->m->p_butt->button[4]->sprite_rect.left = 0;
        rpg_tab->m->p_butt->button[2]->sprite_rect.left =
        2 * rpg_tab->m->p_butt->button[2]->sprite_rect.width;
        sfRenderWindow_setFramerateLimit(rpg_tab->window, 30);
        rpg_tab->config->fps = 30;
    }
}

void param_buttons_click(rpg_t *rpg_tab)
{
    for (int i = 6; i < 15; i++) {
        if (rpg_tab->m->p_butt->button[i]->sprite_rect.left ==
        3 * rpg_tab->m->p_butt->button[i]->sprite_rect.width)
            rpg_tab->m->p_butt->button[i]->sprite_rect.left = 0;
    } if (rpg_tab->m->p_butt->button_state >= PARAM_BACK
        && rpg_tab->m->p_butt->button_state <= P_LEFT) {
        for (int i = 5; i < 15; i++)
            rpg_tab->m->p_butt->button[i]->sprite_rect.left = 0;
        rpg_tab->m->p_butt->button[(int)rpg_tab->m->p_butt->button_state - 1]
        ->sprite_rect.left = 2 * rpg_tab->m->p_butt->button[(int)rpg_tab->m->
        p_butt->button_state - 1]->sprite_rect.width;
    } if (rpg_tab->m->p_butt->button_state == PARAM_SOUND) {
        rpg_tab->m->p_butt->button[0]->sprite_rect.width = rpg_tab->event.
        mouseButton.x - rpg_tab->m->p_butt->button[0]->sprite_pos.x;
        if (rpg_tab->m->p_butt->button[0]->sprite_rect.width < 0)
            rpg_tab->m->p_butt->button[0]->sprite_rect.width = 0;
        if (rpg_tab->m->p_butt->button[0]->sprite_rect.width > 273)
            rpg_tab->m->p_butt->button[0]->sprite_rect.width = 273;
    } param_buttons_click_two(rpg_tab);
    param_buttons_click_three(rpg_tab);
}

void param_buttons_released(rpg_t *rpg_tab)
{
    int state = (int)rpg_tab->m->p_butt->button_state - 1;

    rpg_tab->mouse_left_click = 0;
    if (rpg_tab->m->p_butt->button_state > PARAM_MUSIC
        && rpg_tab->m->p_butt->button_state < CB_PARAM_SOUND) {
        sfClock_restart(rpg_tab->m->p_butt->button[state]->anim_clock);
        if (rpg_tab->m->p_butt->button_state == PARAM_BACK)
            start_transition(rpg_tab);
        rpg_tab->m->p_butt->button[state]->sprite_rect.left
        += rpg_tab->m->p_butt->button[state]->sprite_rect.width;
        rpg_tab->m->p_butt->button_state += 15;
    }
}