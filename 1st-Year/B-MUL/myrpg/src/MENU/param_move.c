/*
** EPITECH PROJECT, 2021
** param_buttons.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void param_move_verif_click(rpg_t *rpg_tab, int i)
{
    if (rpg_tab->mouse_left_click == 0 && i > 1) {
        if (i >= 2 && i <= 4 && rpg_tab->m->p_butt->button[i]->sprite_rect.left
            == rpg_tab->m->p_butt->button[i]->sprite_rect.width * 3) {
            return;
        }
        rpg_tab->m->p_butt->button[i]->sprite_rect.left =
        rpg_tab->m->p_butt->button[i]->sprite_rect.width;
    }
    if (i <= 1 && rpg_tab->mouse_left_click == 1
        && rpg_tab->m->p_butt->button_state <= PARAM_MUSIC) {
        rpg_tab->m->p_butt->button[i]->sprite_rect.width = rpg_tab->event.
        mouseMove.x - (rpg_tab->m->p_butt->button[i]->sprite_pos.x / 1920)
        * sfRenderWindow_getSize(rpg_tab->window).x;
        if (rpg_tab->m->p_butt->button[i]->sprite_rect.width < 0)
            rpg_tab->m->p_butt->button[i]->sprite_rect.width = 0;
        if (rpg_tab->m->p_butt->button[i]->sprite_rect.width
            > rpg_tab->m->p_butt->offset[i])
            rpg_tab->m->p_butt->button[i]->sprite_rect.width
            = rpg_tab->m->p_butt->offset[i];
    }
}

void param_move(rpg_t *rpg_tab)
{
    rpg_tab->m->p_butt->button_state = PARAM_BASE;
    for (int i = 0; i < 15; i++) {
        if (i >= 6 && rpg_tab->m->p_butt->button[i]->sprite_rect.left ==
            3 * rpg_tab->m->p_butt->button[i]->sprite_rect.width
            && rpg_tab->mouse_left_click == 0) {
            continue;
        }
        if (sfFloatRect_intersects(
        &(rpg_tab->m->p_butt->button[i]->sprite_frect),
        &(rpg_tab->u->c_box), NULL) == sfTrue) {
            rpg_tab->m->p_butt->button_state = i + 1;
            param_move_verif_click(rpg_tab, i);
        } else if (i > 1) {
            if (i <= 4 && rpg_tab->m->p_butt->button[i]->sprite_rect.left
                == rpg_tab->m->p_butt->button[i]->sprite_rect.width * 3) {
                continue;
            }
            rpg_tab->m->p_butt->button[i]->sprite_rect.left = 0;
        }
    }
}