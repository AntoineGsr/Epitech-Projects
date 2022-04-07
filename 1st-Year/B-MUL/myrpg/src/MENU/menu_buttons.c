/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void menu_move_verif_click(rpg_t *rpg_tab, int i)
{
    if (rpg_tab->mouse_left_click == 0)
        rpg_tab->m->m_butt->button[i]->sprite_rect.left =
        rpg_tab->m->m_butt->button[i]->sprite_rect.width;
}

void menu_move(rpg_t *rpg_tab)
{
    rpg_tab->m->m_butt->button_state = MENU_BASE;
    for (int i = 0; i < 6; i++) {
        if (sfFloatRect_intersects(
        &(rpg_tab->m->m_butt->button[i]->sprite_frect),
        &(rpg_tab->u->c_box), NULL) == sfTrue) {
            menu_move_verif_click(rpg_tab, i);
            rpg_tab->m->m_butt->button_state = i + 1;
        } else
            rpg_tab->m->m_butt->button[i]->sprite_rect.left = 0;
    }
}

void menu_buttons_click(rpg_t *rpg_tab)
{
    if (rpg_tab->m->m_butt->button_state == MENU_PLAY)
        rpg_tab->m->m_butt->button[0]->sprite_rect.left =
        2 * rpg_tab->m->m_butt->button[0]->sprite_rect.width;
    if (rpg_tab->m->m_butt->button_state == MENU_LOAD)
        rpg_tab->m->m_butt->button[1]->sprite_rect.left =
        2 * rpg_tab->m->m_butt->button[1]->sprite_rect.width;
    if (rpg_tab->m->m_butt->button_state == MENU_END)
        rpg_tab->m->m_butt->button[2]->sprite_rect.left =
        2 * rpg_tab->m->m_butt->button[2]->sprite_rect.width;
    if (rpg_tab->m->m_butt->button_state == MENU_PARAM)
        rpg_tab->m->m_butt->button[3]->sprite_rect.left =
        2 * rpg_tab->m->m_butt->button[3]->sprite_rect.width;
    if (rpg_tab->m->m_butt->button_state == MENU_HELP)
        rpg_tab->m->m_butt->button[4]->sprite_rect.left =
        2 * rpg_tab->m->m_butt->button[4]->sprite_rect.width;
    if (rpg_tab->m->m_butt->button_state == MENU_SKIN)
        rpg_tab->m->m_butt->button[5]->sprite_rect.left =
        2 * rpg_tab->m->m_butt->button[5]->sprite_rect.width;
    rpg_tab->mouse_left_click = 1;
}

void menu_buttons_released(rpg_t *rpg_tab)
{
    int state = (int)rpg_tab->m->m_butt->button_state - 1;

    rpg_tab->mouse_left_click = 0;
    if (rpg_tab->m->m_butt->button_state >= MENU_PLAY
        && rpg_tab->m->m_butt->button_state < CB_PLAY) {
        sfClock_restart(rpg_tab->m->m_butt->button[state]->anim_clock);
        start_transition(rpg_tab);
        rpg_tab->m->m_butt->button[state]->sprite_rect.left
        += rpg_tab->m->m_butt->button[state]->sprite_rect.width;
        rpg_tab->m->m_butt->button_state += 6;
    }
}