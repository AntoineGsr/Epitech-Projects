/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include "../../include/my.h"

int check_guy_hit_mob_four(rpg_t *rpg_tab, sfVector2f previous_pos)
{
    for (int i = 0; i < rpg_tab->g->nb_mob; i++) {
        if (sfFloatRect_intersects(&(rpg_tab->g->enemy[i]->blop_hitbox),
        &(rpg_tab->g->perso->guy_hitbox), NULL) == sfTrue
        && rpg_tab->g->enemy[i]->hp > 0) {
            rpg_tab->g->perso->guy->sprite_pos.x = previous_pos.x;
            rpg_tab->g->perso->guy->sprite_pos.y = previous_pos.y;
            sfSprite_setPosition(rpg_tab->g->perso->guy->sprite,
            rpg_tab->g->perso->guy->sprite_pos);
            rpg_tab->g->perso->hit = 1;
            rpg_tab->g->enemy[i]->hit = 0;
            rpg_tab->g->var->hp -= 1;
            return (1);
        }
        rpg_tab->g->enemy[i]->hit = 0;
    } return (0);
}

void check_guy_hit_mob_ex(rpg_t *rpg_tab, int i)
{
    sfTexture_destroy(rpg_tab->g->inventory->case_inv[i]->
    inv_case->texture);
    sfSprite_destroy(rpg_tab->g->inventory->case_inv[i]->
    inv_case->sprite);
    free(rpg_tab->g->inventory->case_inv[i]->inv_case);
    rpg_tab->g->var->xp += 100;
    rpg_tab->g->inventory->case_inv[i]->inventory = false;
    rpg_tab->g->var->space_bag -= 1;
}

int check_guy_hit_mob_three(rpg_t *rpg_tab, sfVector2f previous_pos)
{
    rpg_tab->g->can_talk_mehdik = true;
    if (rpg_tab->g->talk_mehdik == true) {
        rpg_tab->g->talking_mehdik = true;
        sfClock_restart(rpg_tab->g->clock_medhik);
    }
    if (rpg_tab->g->talk_mehdik == true
    && rpg_tab->g->var->water_bidon == true) {
        rpg_tab->g->mehdik_quest_done = true;
    }
    for (int i = 0; i < 9
    && rpg_tab->g->mehdik_quest_done == true; i++) {
        if (rpg_tab->g->inventory->case_inv[i]->inventory == 4) {
            check_guy_hit_mob_ex(rpg_tab, i);
            return (1);
        }
    }
    return (0);
}

int check_guy_hit_mob_two(rpg_t *rpg_tab, sfVector2f previous_pos)
{
    if (sfFloatRect_intersects(&(rpg_tab->g->captain->sprite_frect),
    &(rpg_tab->g->perso->guy_hitbox), NULL) == sfTrue) {
        rpg_tab->g->perso->guy->sprite_pos.x = previous_pos.x;
        rpg_tab->g->perso->guy->sprite_pos.y = previous_pos.y;
        sfSprite_setPosition(rpg_tab->g->perso->guy->sprite,
        rpg_tab->g->perso->guy->sprite_pos);
        rpg_tab->g->perso->hit = 1;
        return (1);
    } return (0);
}

void check_guy_hit_mob(rpg_t *rpg_tab, sfVector2f previous_pos)
{
    game_stat_refresh(rpg_tab);
    if (check_guy_hit_mob_two(rpg_tab, previous_pos) == 1) return;
    if (sfFloatRect_intersects(&rpg_tab->g->mehdik_quest,
    &rpg_tab->g->perso->guy_hitbox, NULL) == sfTrue
    && rpg_tab->g->mehdik_quest_done == false) {
        if (check_guy_hit_mob_three(rpg_tab, previous_pos) == 1) return;
    } else
        rpg_tab->g->can_talk_mehdik = false;
    if (sfFloatRect_intersects(&(rpg_tab->g->mehdik->sprite_frect),
    &(rpg_tab->g->perso->guy_hitbox), NULL) == sfTrue) {
        rpg_tab->g->perso->guy->sprite_pos.x = previous_pos.x;
        rpg_tab->g->perso->guy->sprite_pos.y = previous_pos.y;
        sfSprite_setPosition(rpg_tab->g->perso->guy->sprite,
        rpg_tab->g->perso->guy->sprite_pos);
        rpg_tab->g->perso->hit = 1;
        return;
    }
    if (check_guy_hit_mob_four(rpg_tab, previous_pos) == 1) return;
}