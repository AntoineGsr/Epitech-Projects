/*
** EPITECH PROJECT, 2021
** parse_save.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

char *create_arr_save_six(rpg_t *rpg_tab, char *buff)
{
    buff = my_strcat(buff, my_getstr(rpg_tab->g->card->door_two));
    buff = my_strcat(buff, "\nwater_bidon:");
    buff = my_strcat(buff, my_getstr(rpg_tab->g->var->water_bidon));
    buff = my_strcat(buff, "\nwater_bidon_done:");
    buff = my_strcat(buff, my_getstr(rpg_tab->g->water_done));
    for (int i = 10, z = 0; i < rpg_tab->g->nb_mob; i++, z++) {
        buff = my_strcat(buff, "\nx:");
        buff = my_strcat(buff, my_getstr((int)rpg_tab->g->enemy[i]
        ->blop->sprite_pos.x));
        buff = my_strcat(buff, "\ny:");
        buff = my_strcat(buff, my_getstr((int)rpg_tab->g->enemy[i]
        ->blop->sprite_pos.y));
        buff = my_strcat(buff, "\npv:");
        buff = my_strcat(buff, my_getstr((int)rpg_tab->g->enemy[i]
        ->hp));
    } buff = my_strcat(buff, "\ncut_dmg:");
    buff = my_strcat(buff, my_getstr(rpg_tab->g->var->cut_dmg));
    buff = my_strcat(buff, "\nspeed_guy:");
    buff = my_strcat(buff, my_getstr(rpg_tab->g->perso->speed));
    return (buff);
}

char *create_arr_save_five(rpg_t *rpg_tab, char *buff)
{
    buff = my_strcat(buff, my_getstr((int)rpg_tab->g->perso->guy
    ->sprite_pos.x));
    buff = my_strcat(buff, "\ny_guy:");
    buff = my_strcat(buff, my_getstr((int)rpg_tab->g->perso->guy
    ->sprite_pos.y));
    buff = my_strcat(buff, "\nslot_seven:");
    buff = my_strcat(buff, my_getstr(rpg_tab->g->inventory->case_inv[6]
    ->inventory));
    buff = my_strcat(buff, "\nslot_eight:");
    buff = my_strcat(buff, my_getstr(rpg_tab->g->inventory->case_inv[7]
    ->inventory));
    buff = my_strcat(buff, "\nslot_nine:");
    buff = my_strcat(buff, my_getstr(rpg_tab->g->inventory->case_inv[8]
    ->inventory));
    buff = my_strcat(buff, "\naccess_card:");
    buff = my_strcat(buff, my_getstr(rpg_tab->g->var->access_card));
    buff = my_strcat(buff, "\ndoor_one:");
    buff = my_strcat(buff, my_getstr(rpg_tab->g->card->door_one));
    buff = my_strcat(buff, "\ndoor_two:");
    return (buff);
}