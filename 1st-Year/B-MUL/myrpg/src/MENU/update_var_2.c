/*
** EPITECH PROJECT, 2021
** parse_save.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void update_var_game_ten(rpg_t *rpg_tab, int i, int z)
{
    rpg_tab->g->enemy[i]->hit = 0;
    rpg_tab->g->enemy[i]->nb_pressed = 0;
    rpg_tab->g->enemy[i]->area = i % 7;
    if (rpg_tab->g->enemy[i]->hp > 0) {
        rpg_tab->g->enemy[i]->blop_hitbox =
        (sfFloatRect) {rpg_tab->g->enemy[i]
        ->blop->sprite_pos.x + 30,
        rpg_tab->g->enemy[i]->blop->sprite_pos.y +
        50, 45, 35};
    } else {
        rpg_tab->g->enemy[i]->blop_hitbox = (sfFloatRect){0, 0, 0, 0};
    }
}

void update_var_game_nine(rpg_t *rpg_tab, int i, int z)
{
    rpg_tab->g->enemy[i] = malloc(sizeof(enemy_t));
    rpg_tab->g->enemy[i]->blop = get_my_sprite(rpg_tab, ENEMY_SKIN,
    (sfVector2f){(float)my_getnbr(rpg_tab->m->l_butt->parsing[z]),
    (float)my_getnbr(rpg_tab->m->l_butt->parsing[z + 1])},
    (sfIntRect){0, 0, 100, 100});
    rpg_tab->g->enemy[i]->blop->sprite_frect = (sfFloatRect)
    {0, 0, 200, 200};
    rpg_tab->g->enemy[i]->explosion = (sfFloatRect)
    {0, 0, 500, 500};
    rpg_tab->g->enemy[i]->detected = false;
    rpg_tab->g->enemy[i]->speed = 200;
    rpg_tab->g->enemy[i]->hp =
    my_getnbr(rpg_tab->m->l_butt->parsing[z + 2]);
    rpg_tab->g->enemy[i]->speed = 200;
    rpg_tab->g->enemy[i]->mv_up = rand() % 2;
    rpg_tab->g->enemy[i]->mv_down = rand() % 2;
    rpg_tab->g->enemy[i]->mv_right = rand() % 2;
    rpg_tab->g->enemy[i]->mv_left = rand() % 2;
    rpg_tab->g->enemy[i]->previous_clock = 0;
    rpg_tab->g->enemy[i]->clock_move = 0;
}

void update_var_game_eight(rpg_t *rpg_tab, int i)
{
    rpg_tab->g->enemy[i]->hit = 0;
    rpg_tab->g->enemy[i]->nb_pressed = 0;
    rpg_tab->g->enemy[i]->area = i % 7;
    if (rpg_tab->g->enemy[i]->hp > 0) {
        rpg_tab->g->enemy[i]->blop_hitbox = (sfFloatRect)
        {rpg_tab->g->enemy[i]->blop->sprite_pos.x + 30,
        rpg_tab->g->enemy[i]->blop->sprite_pos.y +
        50, 45, 35};
    } else {
        rpg_tab->g->enemy[i]->blop_hitbox = (sfFloatRect){0, 0, 0, 0};
    }
}

void update_var_game_seven(rpg_t *rpg_tab, int i, int z)
{
    rpg_tab->g->enemy[i] = malloc(sizeof(enemy_t));
    rpg_tab->g->enemy[i]->blop = get_my_sprite(rpg_tab, ENEMY_SKIN,
    (sfVector2f){(float)my_getnbr(rpg_tab->m->l_butt->parsing[z]),
    (float)my_getnbr(rpg_tab->m->l_butt->parsing[z + 1])},
    (sfIntRect){0, 0, 100, 100});
    rpg_tab->g->enemy[i]->blop->sprite_frect = (sfFloatRect)
    {0, 0, 200, 200};
    rpg_tab->g->enemy[i]->explosion = (sfFloatRect)
    {0, 0, 500, 500};
    rpg_tab->g->enemy[i]->detected = false;
    rpg_tab->g->enemy[i]->speed = 200;
    rpg_tab->g->enemy[i]->hp = my_getnbr(rpg_tab->m->l_butt->
    parsing[z + 2]);
    rpg_tab->g->enemy[i]->speed = 200;
    rpg_tab->g->enemy[i]->mv_up = rand() % 2;
    rpg_tab->g->enemy[i]->mv_down = rand() % 2;
    rpg_tab->g->enemy[i]->mv_right = rand() % 2;
    rpg_tab->g->enemy[i]->mv_left = rand() % 2;
    rpg_tab->g->enemy[i]->previous_clock = 0;
    rpg_tab->g->enemy[i]->clock_move = 0;
}

void update_var_game_six(rpg_t *rpg_tab)
{
    rpg_tab->g->var->helmet = rpg_tab->m->l_butt->parsing[15];
    rpg_tab->g->var->body = rpg_tab->m->l_butt->parsing[16];
    rpg_tab->g->var->pant = rpg_tab->m->l_butt->parsing[17];
    rpg_tab->g->var->weapon = my_getnbr(rpg_tab->m->l_butt->parsing[18]);
    rpg_tab->g->perso->weapon = my_getnbr(rpg_tab->m->l_butt->parsing[18]);
    rpg_tab->g->var->nb_mob = my_getnbr(rpg_tab->m->l_butt->parsing[19]);
    rpg_tab->g->nb_mob = rpg_tab->g->var->nb_mob;
    rpg_tab->g->perso->guy->sprite_pos.x = (float) my_getnbr(rpg_tab->m->
    l_butt->parsing[50]);
    rpg_tab->g->perso->guy->sprite_pos.y = (float) my_getnbr(rpg_tab->m->
    l_butt->parsing[51]);
    rpg_tab->g->card->door_one = my_getnbr(rpg_tab->m->l_butt->parsing[56]);
    rpg_tab->g->card->door_two = my_getnbr(rpg_tab->m->l_butt->parsing[57]);
    for (int i = 0; i < 10; i++) {
        free(rpg_tab->g->enemy[i]->blop);
        free(rpg_tab->g->enemy[i]);
    }
    free(rpg_tab->g->enemy);
    rpg_tab->g->enemy = malloc(sizeof(enemy_t) * rpg_tab->g->var->nb_mob);
}