/*
** EPITECH PROJECT, 2021
** gestion_event_game.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void extra_event_game(rpg_t *rpg_tab)
{
    if (rpg_tab->event.key.code == sfKeySpace) {
        display_tile_hitboxes(rpg_tab);
        rpg_tab->g->skip = true;
    } if (rpg_tab->event.key.code == sfKeyK) {
        rpg_tab->step = END_GAME;
    }
    if (rpg_tab->event.type == sfEvtClosed)
        sfRenderWindow_close(rpg_tab->window);
}

void swh_one(rpg_t *rpg_tab)
{
    if (rpg_tab->event.mouseWheelScroll.delta < 0)
        rpg_tab->g->perso->weapon =
        (rpg_tab->g->perso->weapon + 1) % 3;
    if (rpg_tab->event.mouseWheelScroll.delta > 0)
        rpg_tab->g->perso->weapon =
        (rpg_tab->g->perso->weapon - 1) % 3;
    if (rpg_tab->g->perso->weapon < 0)
        rpg_tab->g->perso->weapon += 3;
}

int swh_cs(rpg_t *rpg_tab)
{
    switch (rpg_tab->event.type) {
        case sfEvtMouseWheelScrolled:
            swh_one(rpg_tab);
            return (1);
        case sfEvtMouseButtonPressed:
            swh_two(rpg_tab);
            return (1);
        case sfEvtMouseButtonReleased:
            swh_three(rpg_tab);
            return (1);
        case sfEvtKeyPressed:
            swh_foor(rpg_tab);
            swh_five(rpg_tab);
            return (1);
        case sfEvtKeyReleased:
            swh_six(rpg_tab);
            return (1);
        default:
            return (1);
    }
    return (0);
}

void gestion_event_game(rpg_t *rpg_tab)
{
    if (rpg_tab->g->link_start_state != LOG_DONE) {
        events_log(rpg_tab);
    } else {
        extra_event_game(rpg_tab);
        swh_cs(rpg_tab);
    }
}