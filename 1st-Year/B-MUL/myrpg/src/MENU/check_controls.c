/*
** EPITECH PROJECT, 2021
** param.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void check_controls_mod_two(rpg_t *rpg_tab)
{
    for (int i = 6; i < 15; i++) {
        if (rpg_tab->m->p_butt->button[i]->sprite_rect.left ==
            3 * rpg_tab->m->p_butt->button[i]->sprite_rect.width) {
            check_controls_mod_two_ex(rpg_tab, i);
            return;
        }
    }
}

void check_controls_mod(rpg_t *rpg_tab)
{
    if (rpg_tab->event.key.code > sfKeyEscape
        && rpg_tab->event.key.code != sfKeySpace
        && rpg_tab->event.key.code != sfKeyTab) {
        return;
    }
    if (rpg_tab->event.key.code == rpg_tab->keys->game_menu
        || rpg_tab->event.key.code == rpg_tab->keys->inventory
        || rpg_tab->event.key.code == rpg_tab->keys->interaction
        || rpg_tab->event.key.code == rpg_tab->keys->switch_weapon
        || rpg_tab->event.key.code == rpg_tab->keys->reload
        || rpg_tab->event.key.code == rpg_tab->keys->up
        || rpg_tab->event.key.code == rpg_tab->keys->down
        || rpg_tab->event.key.code == rpg_tab->keys->right
        || rpg_tab->event.key.code == rpg_tab->keys->left)
        return;
    check_controls_mod_two(rpg_tab);
}

void check_controls_txt_three(rpg_t *rpg_tab, int i)
{
    rpg_tab->m->p_butt->key[i - 6]->ctrl = my_memset_char(4);
    if (rpg_tab->event.text.unicode == 9)
        rpg_tab->m->p_butt->key[i - 6]->ctrl = my_strcpy(rpg_tab->
        m->p_butt->key[i - 6]->ctrl, "Tab");
    if (rpg_tab->event.text.unicode == 27)
        rpg_tab->m->p_butt->key[i - 6]->ctrl = my_strcpy(rpg_tab->
        m->p_butt->key[i - 6]->ctrl, "Esc");
    if (rpg_tab->event.text.unicode == 32)
        rpg_tab->m->p_butt->key[i - 6]->ctrl = my_strcpy(rpg_tab->
        m->p_butt->key[i - 6]->ctrl, "Spa");
    rpg_tab->m->p_butt->key[i - 6]->text_pos.x =
    rpg_tab->m->p_butt->button[i]->sprite_pos.x + 15 + i - 6;
}

void check_controls_txt_two(rpg_t *rpg_tab)
{
    for (int i = 6; i < 15; i++) {
        if (rpg_tab->m->p_butt->button[i]->sprite_rect.left ==
            3 * rpg_tab->m->p_butt->button[i]->sprite_rect.width) {
            check_controls_txt_two_ex(rpg_tab, i);
            return;
        }
    }
}

void check_controls_txt(rpg_t *rpg_tab)
{
    char *comp = my_memset_char(2);
    comp[0] = rpg_tab->event.text.unicode;
    if (rpg_tab->event.text.unicode == 13) {
        free(comp);
        return;
    }
    for (int i = 6; i < 15; i++) {
        if (my_strcmp(comp, rpg_tab->m->p_butt->key[i - 6]->ctrl) == 0
            || (rpg_tab->event.text.unicode == 27
            && my_strcmp("Esc", rpg_tab->m->p_butt->key[i - 6]->ctrl) == 0)
            || (rpg_tab->event.text.unicode == 9
            && my_strcmp("Tab", rpg_tab->m->p_butt->key[i - 6]->ctrl) == 0)
            || (rpg_tab->event.text.unicode == 32
            && my_strcmp("Spa", rpg_tab->m->p_butt->key[i - 6]->ctrl) == 0)) {
            free(comp);
            return;
        }
    } free(comp);
    check_controls_txt_two(rpg_tab);
}