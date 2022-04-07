/*
** EPITECH PROJECT, 2021
** entity_gestion.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void verif_multiple_input(rpg_t *rpg_tab)
{
    if (rpg_tab->keys->mv_right == true)
        rpg_tab->keys->nb_pressed += 1;
    if (rpg_tab->keys->mv_left == true)
        rpg_tab->keys->nb_pressed += 1;
    if (rpg_tab->keys->mv_up == true)
        rpg_tab->keys->nb_pressed += 1;
    if (rpg_tab->keys->mv_down == true)
        rpg_tab->keys->nb_pressed += 1;
}

void gestion_enemy_blop(rpg_t *rpg_tab)
{
    int restart_clock = 0;

    for (int i = 0; i < rpg_tab->g->nb_mob; i++) {
        if ((rpg_tab->g->perso->guy->sprite_pos.x - 1920
        > rpg_tab->g->enemy[i]->blop->sprite_pos.x)
        || (rpg_tab->g->perso->guy->sprite_pos.x + 1920
        < rpg_tab->g->enemy[i]->blop->sprite_pos.x))
            continue;
        restart_clock = mob_gestion_call(rpg_tab, i, restart_clock);
    }
    if (restart_clock == 1)
        rpg_tab->g->enemy[0]->previous_clock =
        previous_time(sfClock_getElapsedTime(rpg_tab->gbl_clock));
    rpg_tab->g->enemy[0]->clock_move =
    previous_time(sfClock_getElapsedTime(rpg_tab->gbl_clock));
}

void previous_var_update(rpg_t *rpg_tab)
{
    rpg_tab->g->var->previous_xp = rpg_tab->g->var->xp;
    rpg_tab->g->var->previous_hp = rpg_tab->g->var->hp;
    rpg_tab->g->var->previous_space_bag = rpg_tab->g->var->space_bag;
    rpg_tab->g->var->previous_gun_charger = rpg_tab->g->nb_bullet;
    if (rpg_tab->g->can_grab_water == false)
        rpg_tab->g->water_grab = false;
    if (rpg_tab->g->can_open_door == false)
        rpg_tab->g->open_door = false;
    if (rpg_tab->g->can_open_door != 6990 || rpg_tab->g->open_door == false) {
        for (int i = 0; i < 4; i++)
            rpg_tab->g->card->code_door_two->ctrl[i] = '\0';
    }
}

void gestion_entity(rpg_t *rpg_tab)
{
    previous_var_update(rpg_tab);
    if (rpg_tab->g->perso->weapon == 2 && rpg_tab->g->reloading == true
    && rpg_tab->g->nb_bullet < 9) {
        reaload_gun(rpg_tab);
    }
    gestion_guy(rpg_tab);
    gestion_enemy_blop(rpg_tab);
    gestion_bullet(rpg_tab);
    gestion_door(rpg_tab);
    gestion_damage_floor(rpg_tab);
    if (rpg_tab->g->inventory->inventory == true
    && (rpg_tab->g->left_click == true
    || rpg_tab->g->right_click == true))
        gestion_hitbox_inventary(rpg_tab);
}