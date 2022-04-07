/*
** EPITECH PROJECT, 2021
** quest_door.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void game_stat_refresh_water(rpg_t *rpg_tab)
{
    for (int i = 0; i < 3; i++) {
        rpg_tab->g->bidon->bidon_layer[i]->sprite_pos =
        sfRenderWindow_mapPixelToCoords(rpg_tab->window,
        (sfVector2i){coeff_window(rpg_tab->window_size.x, 815, 1920),
        coeff_window(rpg_tab->window_size.y, 440, 1080)}, rpg_tab->view);
    }
    rpg_tab->g->bidon->bidon_layer[1]->sprite_pos.y =
    rpg_tab->g->bidon->bidon_layer[0]->sprite_pos.y
    + rpg_tab->g->bidon->bidon_layer[1]->sprite_rect.top;
    rpg_tab->g->bidon->button->sprite_pos =
    sfRenderWindow_mapPixelToCoords(rpg_tab->window,
    (sfVector2i){coeff_window(rpg_tab->window_size.x, 858, 1920),
    coeff_window(rpg_tab->window_size.y, 250, 1080)}, rpg_tab->view);
    rpg_tab->g->bidon->button->sprite_frect = (sfFloatRect)
    {rpg_tab->g->bidon->button->sprite_pos.x,
    rpg_tab->g->bidon->button->sprite_pos.y,
    rpg_tab->g->bidon->button->sprite_rect.width,
    rpg_tab->g->bidon->button->sprite_rect.height};
}

void gestion_water_quest_extra(rpg_t *rpg_tab, float seconds_move, float speed)
{
    if (seconds_move > 0.06) {
        rpg_tab->g->bidon->bidon_layer[1]->sprite_rect.top -= (int) speed;
        rpg_tab->g->bidon->bidon_layer[1]->
        sprite_rect.height += (int) speed;
        sfClock_restart(rpg_tab->g->bidon->button->anim_clock);
    }
    if (rpg_tab->g->bidon->bidon_layer[1]->sprite_rect.top <= 0) {
        rpg_tab->g->bidon->bidon_layer[1]->sprite_rect.top = 0;
        rpg_tab->g->bidon->bidon_layer[1]->sprite_rect.height = 401;
        rpg_tab->g->water_done = true;
        rpg_tab->g->water_grab = false;
    }
}

void gestion_water_quest(rpg_t *rpg_tab)
{
    float seconds_move = sfClock_getElapsedTime(rpg_tab->g->bidon->
    button->anim_clock).microseconds / 1000000.0;
    float speed = speed_coeff(seconds_move - rpg_tab->g->bidon->seconds, 600);

    if (sfFloatRect_intersects(&rpg_tab->g->bidon->button->sprite_frect,
    &rpg_tab->u->c_box, NULL) == sfTrue && rpg_tab->g->left_click == true) {
        rpg_tab->g->bidon->button->sprite_rect.left =
        rpg_tab->g->bidon->button->sprite_rect.width;
        gestion_water_quest_extra(rpg_tab, seconds_move, speed);
    } else {
        rpg_tab->g->bidon->button->sprite_rect.left = 0;
    }
    rpg_tab->g->bidon->seconds = seconds_move;
}