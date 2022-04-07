/*
** EPITECH PROJECT, 2021
** init_start_txt.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void init_start_txt_two(rpg_t *rpg_tab)
{
    rpg_tab->g->captain = get_my_sprite(rpg_tab, BLUE_SKIN, (sfVector2f){0, 0},
    (sfIntRect){400, 800, 100, 100});
    rpg_tab->g->captain->sprite_frect = (sfFloatRect)
    {0, 0, 45, 35};
    rpg_tab->g->mehdik = get_my_sprite(rpg_tab, BLUE_SKIN, (sfVector2f){0, 0},
    (sfIntRect){500, 800, 100, 100});
    rpg_tab->g->mehdik->sprite_frect = (sfFloatRect)
    {0, 0, 45, 35};
}

void init_start_txt(rpg_t *rpg_tab)
{
    rpg_tab->g->start_msg[0] = get_my_text(ST_MSG,
    (sfVector2f){0, 0}, sfWhite, 40);
    rpg_tab->g->start_msg[1] = get_my_text(ND_MSG,
    (sfVector2f){0, 0}, sfWhite, 40);
    rpg_tab->g->start_msg[2] = get_my_text(RD_MSG,
    (sfVector2f){0, 0}, sfWhite, 40);
    rpg_tab->g->start_msg[3] = get_my_text(FR_MSG,
    (sfVector2f){0, 0}, sfWhite, 40);
    rpg_tab->g->start_msg[4] = get_my_text(FV_MSG,
    (sfVector2f){0, 0}, sfWhite, 40);
    rpg_tab->g->start_msg[5] = get_my_text(SX_MSG,
    (sfVector2f){0, 0}, sfWhite, 40);
    rpg_tab->g->start_msg[6] = get_my_text(SV_MSG,
    (sfVector2f){0, 0}, sfWhite, 40);
    rpg_tab->g->start_msg[7] = get_my_text(EG_MSG,
    (sfVector2f){0, 0}, sfWhite, 40);
    rpg_tab->g->start_msg[8] = get_my_text(NI_MSG,
    (sfVector2f){0, 0}, sfWhite, 40);
    init_start_txt_two(rpg_tab);
}