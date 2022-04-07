/*
** EPITECH PROJECT, 2021
** gestion_enemy.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void mob_hit_guy_tile(rpg_t *rpg_tab, int i, sfVector2f previous_pos)
{
    if (sfFloatRect_intersects(&(rpg_tab->g->enemy[i]->blop_hitbox),
    &(rpg_tab->g->perso->guy_hitbox), NULL) == sfTrue) {
        rpg_tab->g->enemy[i]->blop->sprite_pos.x = previous_pos.x;
        rpg_tab->g->enemy[i]->blop->sprite_pos.y = previous_pos.y;
        sfSprite_setPosition(rpg_tab->g->enemy[i]->blop->sprite,
        rpg_tab->g->enemy[i]->blop->sprite_pos);
        rpg_tab->g->enemy[i]->hit = 1;
    }
    for (int j = 0; rpg_tab->g->hitbox_tile[j] != NULL; j++) {
        if (sfFloatRect_intersects(&(rpg_tab->g->enemy[i]->blop_hitbox),
        &(rpg_tab->g->hitbox_tile[j]->hitbox), NULL) == sfTrue) {
            rpg_tab->g->enemy[i]->blop->sprite_pos.x = previous_pos.x;
            rpg_tab->g->enemy[i]->blop->sprite_pos.y = previous_pos.y;
            sfSprite_setPosition(rpg_tab->g->enemy[i]->blop->sprite,
            rpg_tab->g->enemy[i]->blop->sprite_pos);
            rpg_tab->g->enemy[i]->hit = 1;
            break;
        }
    }
}

void mob_hit(rpg_t *rpg_tab, int i, sfVector2f previous_pos)
{
    mob_hit_guy_tile(rpg_tab, i, previous_pos);
    for (int z = 0; z < rpg_tab->g->nb_mob; z++) {
        if (i == z)
            continue;
        if (sfFloatRect_intersects(&(rpg_tab->g->enemy[i]->blop_hitbox),
        &(rpg_tab->g->enemy[z]->blop_hitbox), NULL) == sfTrue) {
            rpg_tab->g->enemy[i]->blop->sprite_pos.x = previous_pos.x;
            rpg_tab->g->enemy[i]->blop->sprite_pos.y = previous_pos.y;
            sfSprite_setPosition(rpg_tab->g->enemy[i]->blop->sprite,
            rpg_tab->g->enemy[i]->blop->sprite_pos);
            rpg_tab->g->enemy[i]->hit = 1;
            break;
        }
    }
}

sfVector2f mob_speed_nd(rpg_t *rpg_tab, int speed, int i,
sfVector2f movement_mob)
{
    if (rpg_tab->g->enemy[i]->mv_up == true) {
        if (rpg_tab->g->enemy[i]->mv_right == true
        || rpg_tab->g->enemy[i]->mv_left == true) {
            rpg_tab->g->enemy[i]->blop->sprite_pos.y -= speed / 1.5;
        } else {
            rpg_tab->g->enemy[i]->blop->sprite_pos.y -= speed;
        }
        movement_mob.y -= 1;
    }
    if (rpg_tab->g->enemy[i]->mv_down == true) {
        if (rpg_tab->g->enemy[i]->mv_right == true
        || rpg_tab->g->enemy[i]->mv_left == true) {
            rpg_tab->g->enemy[i]->blop->sprite_pos.y += speed / 1.5;
        } else {
            rpg_tab->g->enemy[i]->blop->sprite_pos.y += speed;
        }
        movement_mob.y += 1;
    }
    return (movement_mob);
}

sfVector2f mob_speed(rpg_t *rpg_tab, int speed, int i, sfVector2f movement_mob)
{
    if (rpg_tab->g->enemy[i]->mv_right == true) {
        if (rpg_tab->g->enemy[i]->mv_up == true
        || rpg_tab->g->enemy[i]->mv_down == true) {
            rpg_tab->g->enemy[i]->blop->sprite_pos.x += speed / 1.5;
        } else {
            rpg_tab->g->enemy[i]->blop->sprite_pos.x += speed;
        }
        movement_mob.x += 1;
    }
    if (rpg_tab->g->enemy[i]->mv_left == true) {
        if (rpg_tab->g->enemy[i]->mv_up == true
        || rpg_tab->g->enemy[i]->mv_down == true) {
            rpg_tab->g->enemy[i]->blop->sprite_pos.x -= speed / 1.5;
        } else {
            rpg_tab->g->enemy[i]->blop->sprite_pos.x -= speed;
        }
        movement_mob.x -= 1;
    }
    return (movement_mob);
}

int mob_rd_move(rpg_t *rpg_tab, float seconds_move, int restart_clock,
int i)
{
    if (seconds_move - rpg_tab->g->enemy[0]->previous_clock > 3) {
        rpg_tab->g->enemy[i]->nb_pressed = 0;
        rpg_tab->g->enemy[i]->mv_right = rand() % 2;
        rpg_tab->g->enemy[i]->mv_left = rand() % 2;
        rpg_tab->g->enemy[i]->mv_up = rand() % 2;
        rpg_tab->g->enemy[i]->mv_down = rand() % 2;
        restart_clock = 1;
    }
    if (sfFloatRect_intersects(&rpg_tab->g->perso->guy_hitbox,
    &rpg_tab->g->enemy[i]->blop->sprite_frect, NULL) == sfTrue) {
        rpg_tab->g->enemy[i]->mv_right = false;
        rpg_tab->g->enemy[i]->mv_left = false;
        rpg_tab->g->enemy[i]->mv_up = false;
        rpg_tab->g->enemy[i]->mv_down = false;
        if (rpg_tab->g->enemy[i]->detected == false)
            rpg_tab->g->enemy[i]->blop->sprite_rect.left = 0;
        rpg_tab->g->enemy[i]->detected = true;
    }
    return (restart_clock);
}