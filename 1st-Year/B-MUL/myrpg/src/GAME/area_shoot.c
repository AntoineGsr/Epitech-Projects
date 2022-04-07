/*
** EPITECH PROJECT, 2021
** area_shoot.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void shoot_refr_one(rpg_t *rpg_tab)
{
    rpg_tab->g->perso->shoot_area->north[0] = (sfFloatRect){rpg_tab->g->
    perso->guy->sprite_pos.x - 910, rpg_tab->g->perso->guy->
    sprite_pos.y - 490, 357, 126};
    rpg_tab->g->perso->shoot_area->north[1] = (sfFloatRect){rpg_tab->g->perso->
    guy->sprite_pos.x + 653, rpg_tab->g->perso->guy->sprite_pos.y - 490, 357,
    126};
    rpg_tab->g->perso->shoot_area->north[2] = (sfFloatRect){rpg_tab->g->
    perso->guy->sprite_pos.x - 553, rpg_tab->g->perso->guy->
    sprite_pos.y - 490, 553, 443};
    rpg_tab->g->perso->shoot_area->north[3] = (sfFloatRect){rpg_tab->g->
    perso->guy->sprite_pos.x + 100, rpg_tab->g->perso->guy->
    sprite_pos.y - 490, 553, 443};
    rpg_tab->g->perso->shoot_area->north[4] = (sfFloatRect){rpg_tab->g->
    perso->guy->sprite_pos.x, rpg_tab->g->perso->guy->sprite_pos.y - 490,
    100, 490};
}

void shoot_refr_two(rpg_t *rpg_tab)
{
    rpg_tab->g->perso->shoot_area->south[0] = (sfFloatRect){rpg_tab->g->perso->
    guy->sprite_pos.x - 910, rpg_tab->g->perso->guy->sprite_pos.y + 464, 357,
    126};
    rpg_tab->g->perso->shoot_area->south[1] = (sfFloatRect){rpg_tab->g->perso->
    guy->sprite_pos.x + 653, rpg_tab->g->perso->guy->sprite_pos.y + 464, 357,
    126};
    rpg_tab->g->perso->shoot_area->south[2] = (sfFloatRect){rpg_tab->g->perso->
    guy->sprite_pos.x - 553, rpg_tab->g->perso->guy->sprite_pos.y + 147, 553,
    443};
    rpg_tab->g->perso->shoot_area->south[3] = (sfFloatRect){rpg_tab->g->perso->
    guy->sprite_pos.x + 100, rpg_tab->g->perso->guy->sprite_pos.y + 147, 553,
    443};
    rpg_tab->g->perso->shoot_area->south[4] = (sfFloatRect){rpg_tab->g->perso->
    guy->sprite_pos.x, rpg_tab->g->perso->guy->sprite_pos.y + 100, 100, 490};
    rpg_tab->g->perso->shoot_area->west[0] = (sfFloatRect){rpg_tab->g->perso->
    guy->sprite_pos.x - 910, rpg_tab->g->perso->guy->sprite_pos.y - 364, 357,
    317};
    rpg_tab->g->perso->shoot_area->west[1] = (sfFloatRect){rpg_tab->g->perso->
    guy->sprite_pos.x - 910, rpg_tab->g->perso->guy->sprite_pos.y + 147, 357,
    317};
}

void shoot_refr_three(rpg_t *rpg_tab)
{
    rpg_tab->g->perso->shoot_area->west[2] = (sfFloatRect){rpg_tab->g->perso->
    guy->sprite_pos.x - 910, rpg_tab->g->perso->guy->sprite_pos.y - 47, 910,
    47};
    rpg_tab->g->perso->shoot_area->west[3] = (sfFloatRect){rpg_tab->g->perso->
    guy->sprite_pos.x - 910, rpg_tab->g->perso->guy->sprite_pos.y + 100, 910,
    47};
    rpg_tab->g->perso->shoot_area->west[4] = (sfFloatRect){rpg_tab->g->perso->
    guy->sprite_pos.x - 910, rpg_tab->g->perso->guy->sprite_pos.y, 960, 100};
    rpg_tab->g->perso->shoot_area->east[0] = (sfFloatRect){rpg_tab->g->perso->
    guy->sprite_pos.x + 653, rpg_tab->g->perso->guy->sprite_pos.y - 364, 357,
    317};
    rpg_tab->g->perso->shoot_area->east[1] = (sfFloatRect){rpg_tab->g->perso->
    guy->sprite_pos.x + 653, rpg_tab->g->perso->guy->sprite_pos.y + 147, 357,
    317};
    rpg_tab->g->perso->shoot_area->east[2] = (sfFloatRect){rpg_tab->g->perso->
    guy->sprite_pos.x + 100, rpg_tab->g->perso->guy->sprite_pos.y - 47, 910,
    47};
}

void game_stat_refresh_shoot_area(rpg_t *rpg_tab)
{
    shoot_refr_one(rpg_tab);
    shoot_refr_two(rpg_tab);
    shoot_refr_three(rpg_tab);
    rpg_tab->g->perso->shoot_area->east[3] = (sfFloatRect){rpg_tab->g->perso->
    guy->sprite_pos.x + 100, rpg_tab->g->perso->guy->sprite_pos.y + 100, 910,
    47};
    rpg_tab->g->perso->shoot_area->east[4] = (sfFloatRect){rpg_tab->g->perso->
    guy->sprite_pos.x + 50, rpg_tab->g->perso->guy->sprite_pos.y, 960, 100};
}