/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include "../../include/my.h"

void gestion_end_game_two(rpg_t *rpg_tab)
{
    if (rpg_tab->g->var->hp <= 0) {
        rpg_tab->g->var->hp = 50;
        rpg_tab->g->perso->guy->sprite_pos = (sfVector2f){221, 1382};
        sfSprite_setPosition(rpg_tab->g->perso->guy->sprite,
        rpg_tab->g->perso->guy->sprite_pos);
    }
}

void gestion_end_game_ex(rpg_t *rpg_tab, int i)
{
    if (rpg_tab->g->click_end_game == true && i == 0)
        rpg_tab->step = END_GAME;
    if (rpg_tab->g->click_end_game == true && i == 1) {
        rpg_tab->g->click_end_game = false;
        rpg_tab->g->tp_end = true;
        rpg_tab->g->perso->guy->sprite_pos = (sfVector2f){15101, 1399};
        sfSprite_setPosition(rpg_tab->g->perso->guy->sprite,
        rpg_tab->g->perso->guy->sprite_pos);
    }
}

void gestion_end_game(rpg_t *rpg_tab)
{
    int hit = false;

    for (int i = 0; i < 2; i++) {
        if (sfFloatRect_intersects(&(rpg_tab->g->perso->guy_hitbox),
        &(rpg_tab->g->end_hitbox[i]), NULL) == sfTrue) {
            rpg_tab->g->can_end_game = true;
            hit = true;
            gestion_end_game_ex(rpg_tab, i);
            return;
        }
    }
    if (hit == false) {
        rpg_tab->g->click_end_game = false;
        rpg_tab->g->can_end_game = false;
    }
    gestion_end_game_two(rpg_tab);
}