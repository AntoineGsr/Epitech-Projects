/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void update_skin_button_color_two(rpg_t *rpg_tab)
{
    if (rpg_tab->m->s_butt->color_button == 2) {
        sfTexture_destroy(rpg_tab->m->m_butt->button[5]->texture);
        rpg_tab->m->m_butt->button[5]->texture = sfTexture_createFromFile
        (BUTTON_SKIN_RED, NULL);
        sfSprite_setTexture(rpg_tab->m->m_butt->button[5]->sprite,
        rpg_tab->m->m_butt->button[5]->texture, sfTrue);
        rpg_tab->g->var->skin = my_memset_char(my_strlen(RED_SKIN) + 1);
        rpg_tab->g->var->skin = my_strcpy(rpg_tab->g->var->skin, RED_SKIN);
    }
}

void update_skin_button_color(rpg_t *rpg_tab)
{
    if (rpg_tab->m->s_butt->color_button == 0) {
        sfTexture_destroy(rpg_tab->m->m_butt->button[5]->texture);
        rpg_tab->m->m_butt->button[5]->texture = sfTexture_createFromFile
        (BUTTON_SKIN_BLUE, NULL);
        sfSprite_setTexture(rpg_tab->m->m_butt->button[5]->sprite,
        rpg_tab->m->m_butt->button[5]->texture, sfTrue);
        rpg_tab->g->var->skin = my_memset_char(my_strlen(BLUE_SKIN) + 1);
        rpg_tab->g->var->skin = my_strcpy(rpg_tab->g->var->skin, BLUE_SKIN);
    } if (rpg_tab->m->s_butt->color_button == 1) {
        sfTexture_destroy(rpg_tab->m->m_butt->button[5]->texture);
        rpg_tab->m->m_butt->button[5]->texture = sfTexture_createFromFile
        (BUTTON_SKIN_YELLOW, NULL);
        sfSprite_setTexture(rpg_tab->m->m_butt->button[5]->sprite,
        rpg_tab->m->m_butt->button[5]->texture, sfTrue);
        rpg_tab->g->var->skin = my_memset_char(my_strlen(YELLOW_SKIN) + 1);
        rpg_tab->g->var->skin = my_strcpy(rpg_tab->g->var->skin, YELLOW_SKIN);
    } update_skin_button_color_two(rpg_tab);
}