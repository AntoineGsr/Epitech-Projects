/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void call_back_buttons_two(rpg_t *rpg_tab)
{
    if (rpg_tab->m->m_butt->button_state == CB_LOAD) {
        rpg_tab->step = LOAD;
        rpg_tab->m->m_butt->button[1]->sprite_rect.left = 0;
    } if (rpg_tab->m->m_butt->button_state == CB_END) {
        rpg_tab->step = END;
    } if (rpg_tab->m->m_butt->button_state == CB_PARAM) {
        rpg_tab->step = PARAM;
        rpg_tab->m->m_butt->button[3]->sprite_rect.left = 0;
    } if (rpg_tab->m->m_butt->button_state == CB_HELP) {
        rpg_tab->step = HELP;
        rpg_tab->m->m_butt->button[4]->sprite_rect.left = 0;
    }
    if (rpg_tab->m->m_butt->button_state == CB_SKIN) {
        sfClock_restart(rpg_tab->m->s_butt->skin_rotate->anim_clock);
        rpg_tab->m->m_butt->button[5]->sprite_rect.left = 0;
        rpg_tab->step = SKIN;
    } rpg_tab->m->m_butt->button_state = MENU_BASE;
}

void call_back_buttons(rpg_t *rpg_tab)
{
    int state = (int)rpg_tab->m->m_butt->button_state - 7;
    sfTime time = sfClock_getElapsedTime(
    rpg_tab->m->m_butt->button[state]->anim_clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 0.75) {
        if (rpg_tab->m->m_butt->button_state == CB_PLAY) {
            rpg_tab->step = GAME;
            rpg_tab->g->play = NEW_GAME;
            clean_log_text(rpg_tab);
            sfMusic_stop(rpg_tab->m->menu_music);
            sfSound_play(rpg_tab->u->link_start->sound);
            sfSound_setVolume(rpg_tab->u->link_start->sound,
            rpg_tab->m->p_butt->button[1]->sprite_rect.width);
            sfMusic_setVolume(rpg_tab->g->game_music,
            rpg_tab->m->p_butt->button[1]->sprite_rect.width);
        } call_back_buttons_two(rpg_tab);
    }
}