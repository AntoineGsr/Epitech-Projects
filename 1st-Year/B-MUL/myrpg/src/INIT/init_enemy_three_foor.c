/*
** EPITECH PROJECT, 2021
** init_enemy_three_foor.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

int init_enemy_three_rect(rpg_t *rpg_tab, int i)
{
    rpg_tab->g->enemy[i]->blop->sprite_frect = (sfFloatRect)
    {0, 0, 200, 200};
    rpg_tab->g->enemy[i]->explosion = (sfFloatRect)
    {0, 0, 500, 500};
    rpg_tab->g->enemy[i]->blop_hitbox = (sfFloatRect) {rpg_tab->g->enemy[i]
    ->blop->sprite_pos.x + 30, rpg_tab->g->enemy[i]->blop->sprite_pos.y +
    50, 45, 35};
    for (int j = 0; j < i; j++) {
        if (sfFloatRect_intersects(&(rpg_tab->g->enemy[i]->blop_hitbox),
        &(rpg_tab->g->enemy[j]->blop_hitbox), NULL) == sfTrue) {
            free(rpg_tab->g->enemy[i]->blop);
            free(rpg_tab->g->enemy[i]);
            i -= 1;
            break;
        }
    }
    return (i);
}

void init_enemy_three(rpg_t *rpg_tab)
{
    for (int i = 24; i < 28; i++) {
        rpg_tab->g->enemy[i] = malloc(sizeof(enemy_t));
        rpg_tab->g->enemy[i]->blop = get_my_sprite(rpg_tab, ENEMY_SKIN,
        spawn_blop(rpg_tab, i, rpg_tab->g->spawn_area_solo, 4),
        (sfIntRect){0, 0, 100, 100});
        rpg_tab->g->enemy[i]->detected = false;
        rpg_tab->g->enemy[i]->speed = 200;
        rpg_tab->g->enemy[i]->mv_up = rand() % 2;
        rpg_tab->g->enemy[i]->mv_down = rand() % 2;
        rpg_tab->g->enemy[i]->mv_right = rand() % 2;
        rpg_tab->g->enemy[i]->mv_left = rand() % 2;
        rpg_tab->g->enemy[i]->previous_clock = 0;
        rpg_tab->g->enemy[i]->clock_move = 0;
        rpg_tab->g->enemy[i]->hit = 0;
        rpg_tab->g->enemy[i]->nb_pressed = 0;
        rpg_tab->g->enemy[i]->area = i % 4;
        rpg_tab->g->enemy[i]->hp = 15;
        i = init_enemy_three_rect(rpg_tab, i);
    }
}

int init_enemy_foor_rect(rpg_t *rpg_tab, int i)
{
    rpg_tab->g->enemy[i]->area = i % 1;
    rpg_tab->g->enemy[i]->hp = 15;
    rpg_tab->g->enemy[i]->blop->sprite_frect = (sfFloatRect)
    {0, 0, 200, 200};
    rpg_tab->g->enemy[i]->explosion = (sfFloatRect)
    {0, 0, 500, 500};
    rpg_tab->g->enemy[i]->blop_hitbox = (sfFloatRect) {rpg_tab->g->enemy[i]
    ->blop->sprite_pos.x + 30, rpg_tab->g->enemy[i]->blop->sprite_pos.y +
    50, 45, 35};
    for (int j = 0; j < i; j++) {
        if (sfFloatRect_intersects(&(rpg_tab->g->enemy[i]->blop_hitbox),
        &(rpg_tab->g->enemy[j]->blop_hitbox), NULL) == sfTrue) {
            free(rpg_tab->g->enemy[i]->blop);
            free(rpg_tab->g->enemy[i]);
            i -= 1;
            break;
        }
    }
    return (i);
}

void init_enemy_foor(rpg_t *rpg_tab)
{
    for (int i = 28; i < 38; i++) {
        rpg_tab->g->enemy[i] = malloc(sizeof(enemy_t));
        rpg_tab->g->enemy[i]->blop = get_my_sprite(rpg_tab, ENEMY_SKIN,
        spawn_blop(rpg_tab, 1, rpg_tab->g->spawn_area_end, 1),
        (sfIntRect){0, 0, 100, 100});
        rpg_tab->g->enemy[i]->detected = false;
        rpg_tab->g->enemy[i]->speed = 200;
        rpg_tab->g->enemy[i]->mv_up = rand() % 2;
        rpg_tab->g->enemy[i]->mv_down = rand() % 2;
        rpg_tab->g->enemy[i]->mv_right = rand() % 2;
        rpg_tab->g->enemy[i]->mv_left = rand() % 2;
        rpg_tab->g->enemy[i]->previous_clock = 0;
        rpg_tab->g->enemy[i]->clock_move = 0;
        rpg_tab->g->enemy[i]->hit = 0;
        rpg_tab->g->enemy[i]->nb_pressed = 0;
        i = init_enemy_foor_rect(rpg_tab, i);
    }
    sfSprite_scale(rpg_tab->g->enemy[37]->blop->sprite, (sfVector2f){2, 2});
    rpg_tab->g->enemy[37]->hp = 30;
}
