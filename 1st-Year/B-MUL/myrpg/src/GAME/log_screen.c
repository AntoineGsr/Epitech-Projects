/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void game_display_call_two(rpg_t *rpg_tab, float seconds)
{
    gd_twelve(rpg_tab, seconds);
    gd_thirt(rpg_tab, seconds);
    gd_fort(rpg_tab, seconds);
}

void game_display_call(rpg_t *rpg_tab)
{
    gm_eg(rpg_tab);
    gm_nince(rpg_tab);
    gm_ten(rpg_tab);
    gm_el(rpg_tab);
    if (rpg_tab->g->inventory->inventory == true)
        gm_twelve(rpg_tab);
    if (rpg_tab->g->open_door == true)
        gd_three(rpg_tab);
    if (rpg_tab->g->water_grab == true)
        gd_five(rpg_tab);
    gd_six(rpg_tab);
    gd_sv(rpg_tab);
    gd_eight(rpg_tab);
    gd_nine(rpg_tab);
    gd_eleven(rpg_tab);
}

void game_display(rpg_t *rpg_tab)
{
    float seconds = sfClock_getElapsedTime
    (rpg_tab->g->clock_msg).microseconds / 1000000.0;

    if (rpg_tab->g->link_start_state >= LOG_NAME
        && rpg_tab->g->link_start_state <= LOG_PSWD) {
        game_one(rpg_tab);
        game_two(rpg_tab);
    }
    if (rpg_tab->g->link_start_state == LOG_DONE
    && seconds < 6.2 && rpg_tab->g->load == false
    && rpg_tab->g->skip == false) {
        game_five(rpg_tab, seconds);
    } else if (rpg_tab->g->link_start_state == LOG_DONE) {
        game_display_call(rpg_tab);
        if (rpg_tab->g->load == true || rpg_tab->g->skip == true)
            return;
        game_display_call_two(rpg_tab, seconds);
    }
}