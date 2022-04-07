/*
** EPITECH PROJECT, 2021
** gestion_event_game_nd.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void swh_two(rpg_t *rpg_tab)
{
    if (rpg_tab->event.mouseButton.button == sfMouseLeft) {
        rpg_tab->g->perso->shooting = true;
        rpg_tab->g->left_click = true;
    }
    if (rpg_tab->event.mouseButton.button == sfMouseRight) {
        rpg_tab->g->perso->target = true;
        rpg_tab->g->right_click = true;
    }
}

void swh_three(rpg_t *rpg_tab)
{
    if (rpg_tab->event.mouseButton.button == sfMouseRight) {
        rpg_tab->g->perso->target = false;
        rpg_tab->g->right_click = false;
    }
    if (rpg_tab->event.mouseButton.button == sfMouseLeft)
        rpg_tab->g->left_click = false;
}

void swh_foor(rpg_t *rpg_tab)
{
    if (rpg_tab->event.key.code == rpg_tab->keys->right) {
        rpg_tab->keys->mv_right = true;
    } else if (rpg_tab->event.key.code == rpg_tab->keys->left)
        rpg_tab->keys->mv_left = true;
    if (rpg_tab->event.key.code == rpg_tab->keys->up) {
        rpg_tab->keys->mv_up = true;
    } else if (rpg_tab->event.key.code == rpg_tab->keys->down)
        rpg_tab->keys->mv_down = true;
    if (rpg_tab->event.key.code == rpg_tab->keys->switch_weapon)
        rpg_tab->g->perso->weapon =
        (rpg_tab->g->perso->weapon + 1) % 3;
}

void swh_five(rpg_t *rpg_tab)
{
    if (rpg_tab->event.key.code == rpg_tab->keys->inventory)
        rpg_tab->g->inventory->inventory =
        (rpg_tab->g->inventory->inventory + 1) % 2;
    if (rpg_tab->event.key.code == rpg_tab->keys->interaction) {
        rpg_tab->g->grab_drop = true;
        rpg_tab->g->open_door = (rpg_tab->g->open_door + 1) % 2;
        rpg_tab->g->water_grab =
        (rpg_tab->g->water_grab + 1) % 2;
        rpg_tab->g->talk_mehdik = true;
        rpg_tab->g->click_end_game = true;
    }
    if (rpg_tab->event.key.code == rpg_tab->keys->reload)
        rpg_tab->g->reloading = true;
    if (rpg_tab->event.key.code == rpg_tab->keys->game_menu)
        rpg_tab->step = GAME_PARAM;
}

void swh_six(rpg_t *rpg_tab)
{
    if (rpg_tab->event.key.code == rpg_tab->keys->right) {
        rpg_tab->keys->mv_right = false;
    } else if (rpg_tab->event.key.code == rpg_tab->keys->left)
        rpg_tab->keys->mv_left = false;
    if (rpg_tab->event.key.code == rpg_tab->keys->up) {
        rpg_tab->keys->mv_up = false;
    } else if (rpg_tab->event.key.code == rpg_tab->keys->down)
        rpg_tab->keys->mv_down = false;
    if (rpg_tab->event.key.code == rpg_tab->keys->interaction)
        rpg_tab->g->grab_drop = false;
    if (rpg_tab->event.key.code == rpg_tab->keys->reload)
        rpg_tab->g->reloading = false;
}