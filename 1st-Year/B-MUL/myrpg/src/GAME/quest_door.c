/*
** EPITECH PROJECT, 2021
** quest.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void quest_door_rd(rpg_t *rpg_tab, int i)
{
    if (rpg_tab->g->left_click == true) {
        if (i == 1) {
            rpg_tab->g->card->code_door_two->ctrl =
            my_strcat(rpg_tab->g->card->code_door_two->ctrl, my_getstr(0));
        } else {
            rpg_tab->g->card->code_door_two->ctrl =
            my_strcat(rpg_tab->g->card->code_door_two->ctrl, my_getstr(i + 1));
        }
        rpg_tab->g->left_click = false;
    }
}

void quest_door_two(rpg_t *rpg_tab)
{
    for (int i = 0; i < 9; i++) {
        if (sfFloatRect_intersects(&rpg_tab->u->c_box,
        &rpg_tab->g->card->digit_number[i]->sprite_frect, NULL)
        == sfTrue) {
            quest_door_rd(rpg_tab, i);
            rpg_tab->g->card->digit_number[i]->sprite_rect.left =
            rpg_tab->g->card->digit_number[i]->sprite_rect.width;
        } else
            rpg_tab->g->card->digit_number[i]->sprite_rect.left = 0;
    }
    if (my_strlen(rpg_tab->g->card->code_door_two->ctrl) >= 3) {
        if (my_getnbr(rpg_tab->g->card->code_door_two->ctrl) == 103) {
            rpg_tab->g->card->door_two = true;
            rpg_tab->g->open_door = false;
        } else {
            for (int i = 0; i < 4; i++)
                rpg_tab->g->card->code_door_two->ctrl[i] = '\0';
        }
    }
}

void gestion_door_quest(rpg_t *rpg_tab)
{
    if (rpg_tab->g->can_open_door == 8081)
        quest_door_one(rpg_tab);
    if (rpg_tab->g->can_open_door == 6990)
        quest_door_two(rpg_tab);
}