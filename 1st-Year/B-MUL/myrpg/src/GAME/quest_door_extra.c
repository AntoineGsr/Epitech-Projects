/*
** EPITECH PROJECT, 2021
** quest_door_extra.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void quest_door_hit_card(rpg_t *rpg_tab)
{
    if (sfFloatRect_intersects(&rpg_tab->u->c_box,
    &rpg_tab->g->card->click_hitbox_big_card, NULL)
    == sfTrue) {
        rpg_tab->g->card->big_card->sprite_pos.x +=
        rpg_tab->u->c_box.left - rpg_tab->u->c_box_previous.left;
        rpg_tab->g->card->big_card->sprite_pos.y +=
        rpg_tab->u->c_box.top - rpg_tab->u->c_box_previous.top;
    }
}

void quest_door_anim(rpg_t *rpg_tab, float seconds)
{
    if (rpg_tab->g->left_click == false)
        rpg_tab->g->card->access_card_mission = true;
    if (seconds > 0.6 && rpg_tab->g->card->access_card_mission == true) {
        sfClock_restart(rpg_tab->g->card->scanner->anim_clock);
        rpg_tab->g->card->scanner->sprite_rect.left +=
        rpg_tab->g->card->scanner->sprite_rect.width;
        if (rpg_tab->g->card->scanner->sprite_rect.left >=
        rpg_tab->g->card->scanner->sprite_rect.width * 3) {
            rpg_tab->g->card->scanner->sprite_rect.left =
            rpg_tab->g->card->scanner->sprite_rect.width * 2;
            rpg_tab->g->card->door_one = true;
            rpg_tab->g->open_door = false;
        }
    }
}

void quest_door_one(rpg_t *rpg_tab)
{
    float seconds = sfClock_getElapsedTime(
    rpg_tab->g->card->scanner->anim_clock).microseconds / 1000000.0;

    if (rpg_tab->g->card->door_one == true)
        return;
    if (rpg_tab->g->card->access_card_mission == true)
        rpg_tab->g->left_click = false;
    if (rpg_tab->g->card->access_card_mission == false
    && rpg_tab->g->left_click == true) {
        quest_door_hit_card(rpg_tab);
    }
    if (sfFloatRect_intersects(&rpg_tab->g->card->scanner->sprite_frect,
    &rpg_tab->g->card->big_card->sprite_frect, NULL) == sfTrue) {
        quest_door_anim(rpg_tab, seconds);
    }
}