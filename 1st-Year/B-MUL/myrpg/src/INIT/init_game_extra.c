/*
** EPITECH PROJECT, 2021
** init_game_extra.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void init_log_wind(rpg_t *rpg_tab)
{
    rpg_tab->g->log_wind->wind = get_my_sprite(rpg_tab,
    "assets/png/game/log_wind.png", (sfVector2f) {675, 432},
    (sfIntRect) {0, 0, 570, 217});
    rpg_tab->g->log_wind->name = get_my_text("", (sfVector2f){
    rpg_tab->g->log_wind->wind->sprite_pos.x + 301,
    rpg_tab->g->log_wind->wind->sprite_pos.y + 79}, sfBlack, 25);
    rpg_tab->g->log_wind->password = get_my_text("", (sfVector2f){
    rpg_tab->g->log_wind->wind->sprite_pos.x + 301,
    rpg_tab->g->log_wind->wind->sprite_pos.y + 155}, sfBlack, 25);
    rpg_tab->g->log_wind->nocrypt_password = my_memset_char(26);
}

void init_game_variables_two(rpg_t *rpg_tab)
{
    rpg_tab->g->var->helmet = my_memset_char(5);
    rpg_tab->g->var->body = my_memset_char(5);
    rpg_tab->g->var->pant = my_memset_char(5);
    rpg_tab->g->var->weapon = 0;
    rpg_tab->g->var->nb_mob = rpg_tab->g->nb_mob;
    rpg_tab->g->var->space_bag = 0;
    rpg_tab->g->var->previous_space_bag = 0;
    rpg_tab->g->var->access_card = false;
    rpg_tab->g->var->water_bidon = false;
    rpg_tab->g->var->gun_dmg = 5;
    rpg_tab->g->var->cut_dmg = 8;
}

void init_game_variables(rpg_t *rpg_tab)
{
    rpg_tab->g->perso->floor_damage_clock = sfClock_create();
    rpg_tab->g->var->skin = my_memset_char(my_strlen(BLUE_SKIN) + 1);
    rpg_tab->g->var->skin = my_strcpy(rpg_tab->g->var->skin, BLUE_SKIN);
    rpg_tab->g->var->quest = 0;
    rpg_tab->g->var->xp = 0;
    rpg_tab->g->var->previous_xp = 0;
    rpg_tab->g->var->hp = 100;
    rpg_tab->g->var->previous_hp = 100;
    rpg_tab->g->var->bandage = 0;
    rpg_tab->g->var->gun_charger = 0;
    rpg_tab->g->var->previous_gun_charger = 0;
    rpg_tab->g->var->katana_dmg = 0;
    init_game_variables_two(rpg_tab);
}