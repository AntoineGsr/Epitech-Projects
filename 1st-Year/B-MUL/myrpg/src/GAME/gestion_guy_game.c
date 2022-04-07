/*
** EPITECH PROJECT, 2021
** gestion_guy_game.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void guy_mult_input(rpg_t *rpg_tab)
{
    if ((rpg_tab->g->open_door == true
    && rpg_tab->g->can_open_door != false)
    || rpg_tab->g->water_grab == true) {
        rpg_tab->keys->mv_up = false;
        rpg_tab->keys->mv_down = false;
        rpg_tab->keys->mv_left = false;
        rpg_tab->keys->mv_right = false;
    }
}

void gestion_guy(rpg_t *rpg_tab)
{
    sfVector2f previous_pos = rpg_tab->g->perso->guy->sprite_pos;

    guy_mult_input(rpg_tab);
    verif_multiple_input(rpg_tab);
    if (rpg_tab->keys->mv_right == true)
        move_guy(rpg_tab, 1, 0, 0);
    if (rpg_tab->keys->mv_left == true)
        move_guy(rpg_tab, -1, 100, 0);
    if (rpg_tab->keys->mv_up == true)
        move_guy(rpg_tab, -1, 200, 1);
    if (rpg_tab->keys->mv_down == true)
        move_guy(rpg_tab, 1, 300, 1);
    animate_guy(rpg_tab);
    check_guy_hit_wall(rpg_tab, previous_pos);
    check_guy_hit_mob(rpg_tab, previous_pos);
    check_guy_drop(rpg_tab);
    gestion_end_game(rpg_tab);
    rpg_tab->g->perso->previous_clock =
    previous_time(sfClock_getElapsedTime(rpg_tab->gbl_clock));
    rpg_tab->keys->nb_pressed = 0;
}