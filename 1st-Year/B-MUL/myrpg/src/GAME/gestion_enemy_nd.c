/*
** EPITECH PROJECT, 2021
** gestion_enemy_nd.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void mob_verif_action(rpg_t *rpg_tab, int i, sfVector2f movement_mob)
{
    if (movement_mob.x > 0)
        rpg_tab->g->enemy[i]->blop->sprite_rect.top = 0;
    if (movement_mob.x < 0)
        rpg_tab->g->enemy[i]->blop->sprite_rect.top = 100;
    if (movement_mob.y < 0)
        rpg_tab->g->enemy[i]->blop->sprite_rect.top = 200;
    if (movement_mob.y > 0)
        rpg_tab->g->enemy[i]->blop->sprite_rect.top = 300;
    if (movement_mob.x == 0 && movement_mob.y == 0
    && rpg_tab->g->enemy[i]->detected == false)
        rpg_tab->g->enemy[i]->blop->sprite_rect.left = 0;
    if (rpg_tab->g->enemy[i]->hp <= 0) {
        rpg_tab->g->enemy[i]->blop->sprite_pos = (sfVector2f){-1000, -1000};
        rpg_tab->g->enemy[i]->blop_hitbox = (sfFloatRect){-1000, -1000, 0, 0};
        rpg_tab->g->enemy[i]->blop->sprite_frect =
        (sfFloatRect){-1000, -1000, 0, 0};
        rpg_tab->g->enemy[i]->explosion = (sfFloatRect){-1000, -1000, 0, 0};
    }
}

int mob_gestion_call(rpg_t *rpg_tab, int i, int restart_clock)
{
    sfVector2f previous_pos = (sfVector2f) {0, 0};
    sfVector2f movement_mob = (sfVector2f) {0, 0};
    sfTime time_move = sfClock_getElapsedTime(rpg_tab->gbl_clock);
    float seconds_move = time_move.microseconds / 1000000.0;
    float speed = speed_coeff(seconds_move - rpg_tab->g->enemy[0]->
    clock_move, rpg_tab->g->enemy[0]->speed);

    rpg_tab->g->enemy[i]->hit = 0;
    restart_clock = mob_rd_move(rpg_tab, seconds_move, restart_clock, i);
    previous_pos = rpg_tab->g->enemy[i]->blop->sprite_pos;
    movement_mob = mob_speed(rpg_tab, speed, i, movement_mob);
    movement_mob = mob_speed_nd(rpg_tab, speed, i, movement_mob);
    sfSprite_setPosition(rpg_tab->g->enemy[i]->blop->sprite,
    rpg_tab->g->enemy[i]->blop->sprite_pos);
    game_stat_refresh_mob(rpg_tab);
    mob_hit(rpg_tab, i, previous_pos);
    animate_mob_blop(rpg_tab, i);
    mob_verif_action(rpg_tab, i, movement_mob);
    return (restart_clock);
}