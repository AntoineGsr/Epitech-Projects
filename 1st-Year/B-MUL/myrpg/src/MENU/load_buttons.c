/*
** EPITECH PROJECT, 2021
** load_buttons.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void load_move_verif_click(rpg_t *rpg_tab, int i)
{
    if (rpg_tab->mouse_left_click == 0)
        rpg_tab->m->l_butt->button[i]->sprite_rect.left =
        rpg_tab->m->l_butt->button[i]->sprite_rect.width;
}

void load_move(rpg_t *rpg_tab)
{
    int i = 0;
    rpg_tab->m->l_butt->button_state = LOAD_BASE;
    for (int i = 0; i < 4; i++) {
        if (sfFloatRect_intersects(
            &(rpg_tab->m->l_butt->button[i]->sprite_frect),
            &(rpg_tab->u->c_box), NULL) == sfTrue) {
            load_move_verif_click(rpg_tab, i);
            rpg_tab->m->l_butt->button_state = i + 1;
        } else
            rpg_tab->m->l_butt->button[i]->sprite_rect.left = 0;
    }
    for (; i < rpg_tab->m->l_butt->save_max; i++,
    rpg_tab->m->l_butt->node = rpg_tab->m->l_butt->node->next);
    load_move_ex(rpg_tab, i);
}

void load_buttons_click(rpg_t *rpg_tab)
{
    if (rpg_tab->m->l_butt->button_state == LOAD_CHARGE)
        rpg_tab->m->l_butt->button[0]->sprite_rect.left =
        2 * rpg_tab->m->l_butt->button[0]->sprite_rect.width;
    if (rpg_tab->m->l_butt->button_state == LOAD_BACK)
        rpg_tab->m->l_butt->button[1]->sprite_rect.left =
        2 * rpg_tab->m->l_butt->button[1]->sprite_rect.width;
    if (rpg_tab->m->l_butt->button_state == LOAD_PREV) {
        rpg_tab->m->l_butt->button[2]->sprite_rect.left =
        2 * rpg_tab->m->l_butt->button[2]->sprite_rect.width;
        if (rpg_tab->m->l_butt->save_max > 0)
            rpg_tab->m->l_butt->save_max -= 5;
    }
    if (rpg_tab->m->l_butt->button_state == LOAD_NEXT) {
        rpg_tab->m->l_butt->button[3]->sprite_rect.left =
        2 * rpg_tab->m->l_butt->button[3]->sprite_rect.width;
        if (rpg_tab->m->l_butt->save_max <
            rpg_tab->m->l_butt->list->nb_node - 5)
            rpg_tab->m->l_butt->save_max += 5;
    }
    rpg_tab->mouse_left_click = 1;
}

void load_buttons_released_two(rpg_t *rpg_tab)
{
    int state = (int)rpg_tab->m->l_butt->button_state - 1;

    if (rpg_tab->m->l_butt->button_state >= LOAD_CHARGE
        && rpg_tab->m->l_butt->button_state < LOAD_SAVE) {
        sfClock_restart(rpg_tab->m->l_butt->button[state]->anim_clock);
        if (rpg_tab->m->l_butt->button_state == LOAD_BACK
            || (rpg_tab->m->l_butt->button_state == LOAD_CHARGE
            && rpg_tab->m->l_butt->save_click != -1)) {
            start_transition(rpg_tab);
        } else {
            rpg_tab->load_game = 1;
        }
        rpg_tab->m->l_butt->button[state]->sprite_rect.left
        += rpg_tab->m->l_butt->button[state]->sprite_rect.width;
        rpg_tab->m->l_butt->button_state += 5;
    }
}

void load_buttons_released(rpg_t *rpg_tab)
{
    rpg_tab->mouse_left_click = 0;
    if (rpg_tab->m->l_butt->button_state == LOAD_SAVE) {
        for (int i = 0; i < rpg_tab->m->l_butt->list->nb_node; i++,
            rpg_tab->m->l_butt->node = rpg_tab->m->l_butt->node->next) {
            rpg_tab->m->l_butt->node->button->sprite_rect.left = 0;
        }
        rpg_tab->m->l_butt->node = rpg_tab->m->l_butt->list->first;
        for (int i = 0; i < rpg_tab->m->l_butt->save_move; i++,
            rpg_tab->m->l_butt->node = rpg_tab->m->l_butt->node->next) {
            rpg_tab->m->l_butt->node->button->sprite_rect.left = 0;
        }
        rpg_tab->m->l_butt->save_click = rpg_tab->m->l_butt->save_move;
        rpg_tab->m->l_butt->node->button->sprite_rect.left =
        rpg_tab->m->l_butt->node->button->sprite_rect.width;
        rpg_tab->m->l_butt->node = rpg_tab->m->l_butt->list->first;
    }
    load_buttons_released_two(rpg_tab);
}