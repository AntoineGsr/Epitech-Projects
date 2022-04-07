/*
** EPITECH PROJECT, 2021
** load_button_extra.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void load_move_ex(rpg_t *rpg_tab, int i)
{
    for (int j = 0; j < 5 && i < rpg_tab->m->l_butt->list->nb_node; j++, i++,
        rpg_tab->m->l_butt->node = rpg_tab->m->l_butt->node->next) {
        if (sfFloatRect_intersects(&(rpg_tab->m->l_butt->node->button->
        sprite_frect), &(rpg_tab->u->c_box), NULL) == sfTrue) {
            rpg_tab->m->l_butt->button_state = LOAD_SAVE;
            rpg_tab->m->l_butt->save_move = i;
        }
    }
    rpg_tab->m->l_butt->node = rpg_tab->m->l_butt->list->first;
}