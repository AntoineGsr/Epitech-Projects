/*
** EPITECH PROJECT, 2021
** input_log_nd.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void valid_field_three(rpg_t *rpg_tab)
{
    sfSprite_scale(rpg_tab->g->inventory->skin->sprite, (sfVector2f){4, 4});
    sfSprite_setTexture(rpg_tab->g->perso->guy->sprite,
    rpg_tab->g->perso->guy->texture, sfTrue);
    sfSprite_setTextureRect(rpg_tab->g->perso->guy->sprite,
    rpg_tab->g->perso->guy->sprite_rect);
    rpg_tab->g->start_msg[2]->ctrl = my_strcat(rpg_tab->g->start_msg[2]->
    ctrl, rpg_tab->g->log_wind->name->ctrl);
    rpg_tab->g->start_msg[2]->ctrl = my_strcat(rpg_tab->g->start_msg[2]->
    ctrl, " !");
}

void valid_field_nd(rpg_t *rpg_tab)
{
    rpg_tab->g->link_start_state = LOG_DONE;
    sfMusic_play(rpg_tab->g->game_music);
    sfTexture_destroy(rpg_tab->g->perso->guy->texture);
    rpg_tab->g->perso->guy->texture = sfTexture_createFromFile
    (rpg_tab->g->var->skin, NULL);
    sfTexture_destroy(rpg_tab->g->inventory->skin->texture);
    rpg_tab->g->inventory->skin->texture = sfTexture_createFromFile
    (rpg_tab->g->var->skin, NULL);
    sfSprite_setTexture(rpg_tab->g->inventory->skin->sprite,
    rpg_tab->g->inventory->skin->texture, sfTrue);
    sfSprite_setTextureRect(rpg_tab->g->inventory->skin->sprite,
    rpg_tab->g->inventory->skin->sprite_rect);
}