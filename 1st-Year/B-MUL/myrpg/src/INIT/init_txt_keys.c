/*
** EPITECH PROJECT, 2021
** init_txt_keys.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void init_txt_keys(rpg_t *rpg_tab)
{
    rpg_tab->m->p_butt->key[0]->ctrl = my_strcpy(rpg_tab->m->p_butt->key[0]->
    ctrl, "Esc");
    rpg_tab->m->p_butt->key[1]->ctrl = my_strcpy(rpg_tab->m->p_butt->key[1]->
    ctrl, "i");
    rpg_tab->m->p_butt->key[2]->ctrl = my_strcpy(rpg_tab->m->p_butt->key[2]->
    ctrl, "e");
    rpg_tab->m->p_butt->key[3]->ctrl = my_strcpy(rpg_tab->m->p_butt->key[3]->
    ctrl, "f");
    rpg_tab->m->p_butt->key[4]->ctrl = my_strcpy(rpg_tab->m->p_butt->key[4]->
    ctrl, "r");
    rpg_tab->m->p_butt->key[5]->ctrl = my_strcpy(rpg_tab->m->p_butt->key[5]->
    ctrl, "z");
    rpg_tab->m->p_butt->key[6]->ctrl = my_strcpy(rpg_tab->m->p_butt->key[6]->
    ctrl, "s");
    rpg_tab->m->p_butt->key[7]->ctrl = my_strcpy(rpg_tab->m->p_butt->key[7]->
    ctrl, "d");
    rpg_tab->m->p_butt->key[8]->ctrl = my_strcpy(rpg_tab->m->p_butt->key[8]->
    ctrl, "q");
}