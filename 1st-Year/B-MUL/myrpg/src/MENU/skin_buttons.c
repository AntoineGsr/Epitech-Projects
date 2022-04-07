/*
** EPITECH PROJECT, 2021
** skin_buttons.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void skin_move_verif_click(rpg_t *rpg_tab, int i)
{
    if (rpg_tab->mouse_left_click == 0) {
        if (rpg_tab->m->s_butt->button[i]->sprite_rect.left
            == rpg_tab->m->s_butt->button[i]->sprite_rect.width * 3) {
            return;
        }
        rpg_tab->m->s_butt->button[i]->sprite_rect.left =
        rpg_tab->m->s_butt->button[i]->sprite_rect.width;
    }
}

void skin_move(rpg_t *rpg_tab)
{
    rpg_tab->m->s_butt->button_state = SKIN_BASE;
    for (int i = 0; i < 7; i++) {
        if (sfFloatRect_intersects(
        &(rpg_tab->m->s_butt->button[i]->sprite_frect),
        &(rpg_tab->u->c_box), NULL) == sfTrue) {
            rpg_tab->m->s_butt->button_state = i + 1;
            skin_move_verif_click(rpg_tab, i);
        } else if (rpg_tab->m->s_butt->button[i]->sprite_rect.left
            == rpg_tab->m->s_butt->button[i]->sprite_rect.width * 3) {
            continue;
        } else
            rpg_tab->m->s_butt->button[i]->sprite_rect.left = 0;
    }
}

void skin_buttons_click(rpg_t *rpg_tab)
{
    if (rpg_tab->m->s_butt->button_state == SKIN_BLUE) {
        rpg_tab->m->s_butt->color_button = 0;
        sfTexture_destroy(rpg_tab->m->s_butt->skin_rotate->texture);
        rpg_tab->m->s_butt->skin_rotate->texture = sfTexture_createFromFile
        (BLUE_SKIN_MENU, NULL);
        sfSprite_setTexture(rpg_tab->m->s_butt->skin_rotate->sprite,
        rpg_tab->m->s_butt->skin_rotate->texture, sfTrue);
        rpg_tab->m->s_butt->button[1]->sprite_rect.left = 0;
        rpg_tab->m->s_butt->button[2]->sprite_rect.left = 0;
        rpg_tab->m->s_butt->button[0]->sprite_rect.left =
        2 * rpg_tab->m->s_butt->button[0]->sprite_rect.width;
    }
    if (rpg_tab->m->s_butt->button_state == SKIN_YELLOW) {
        rpg_tab->m->s_butt->color_button = 1;
        sfTexture_destroy(rpg_tab->m->s_butt->skin_rotate->texture);
        rpg_tab->m->s_butt->skin_rotate->texture = sfTexture_createFromFile
        (YELLOW_SKIN_MENU, NULL);
        sfSprite_setTexture(rpg_tab->m->s_butt->skin_rotate->sprite,
        rpg_tab->m->s_butt->skin_rotate->texture, sfTrue);
        rpg_tab->m->s_butt->button[0]->sprite_rect.left = 0;
        rpg_tab->m->s_butt->button[2]->sprite_rect.left = 0;
        rpg_tab->m->s_butt->button[1]->sprite_rect.left =
        2 * rpg_tab->m->s_butt->button[1]->sprite_rect.width;
    }
    if (rpg_tab->m->s_butt->button_state == SKIN_RED) {
        rpg_tab->m->s_butt->color_button = 2;
        sfTexture_destroy(rpg_tab->m->s_butt->skin_rotate->texture);
        rpg_tab->m->s_butt->skin_rotate->texture = sfTexture_createFromFile
        (RED_SKIN_MENU, NULL);
        sfSprite_setTexture(rpg_tab->m->s_butt->skin_rotate->sprite,
        rpg_tab->m->s_butt->skin_rotate->texture, sfTrue);
        rpg_tab->m->s_butt->button[0]->sprite_rect.left = 0;
        rpg_tab->m->s_butt->button[1]->sprite_rect.left = 0;
        rpg_tab->m->s_butt->button[2]->sprite_rect.left =
        2 * rpg_tab->m->s_butt->button[2]->sprite_rect.width;
    }
    if (rpg_tab->m->s_butt->button_state == SKIN_TRANS) {
        rpg_tab->m->s_butt->button[4]->sprite_rect.left = 0;
        rpg_tab->m->s_butt->button[5]->sprite_rect.left = 0;
        rpg_tab->m->s_butt->button[3]->sprite_rect.left =
        2 * rpg_tab->m->s_butt->button[3]->sprite_rect.width;
    }
    if (rpg_tab->m->s_butt->button_state == SKIN_GAY) {
        rpg_tab->m->s_butt->button[3]->sprite_rect.left = 0;
        rpg_tab->m->s_butt->button[5]->sprite_rect.left = 0;
        rpg_tab->m->s_butt->button[4]->sprite_rect.left =
        2 * rpg_tab->m->s_butt->button[4]->sprite_rect.width;
    }
    if (rpg_tab->m->s_butt->button_state == SKIN_BIN) {
        rpg_tab->m->s_butt->button[3]->sprite_rect.left = 0;
        rpg_tab->m->s_butt->button[4]->sprite_rect.left = 0;
        rpg_tab->m->s_butt->button[5]->sprite_rect.left =
        2 * rpg_tab->m->s_butt->button[5]->sprite_rect.width;
    }
    if (rpg_tab->m->s_butt->button_state == SKIN_BACK)
        rpg_tab->m->s_butt->button[6]->sprite_rect.left =
        2 * rpg_tab->m->s_butt->button[6]->sprite_rect.width;
    rpg_tab->mouse_left_click = 1;
}

void skin_buttons_released(rpg_t *rpg_tab)
{
    int state = (int)rpg_tab->m->s_butt->button_state - 1;

    rpg_tab->mouse_left_click = 0;
    if (rpg_tab->m->s_butt->button_state > SKIN_BASE
        && rpg_tab->m->s_butt->button_state < CB_BLUE) {
        sfClock_restart(rpg_tab->m->s_butt->button[state]->anim_clock);
        if (rpg_tab->m->s_butt->button_state == SKIN_BACK)
            start_transition(rpg_tab);
        rpg_tab->m->s_butt->button[state]->sprite_rect.left
        += rpg_tab->m->s_butt->button[state]->sprite_rect.width;
        rpg_tab->m->s_butt->button_state += 7;
    }
}