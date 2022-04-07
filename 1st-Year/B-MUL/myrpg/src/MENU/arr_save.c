/*
** EPITECH PROJECT, 2021
** parse_save.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

char *create_arr_save_four(rpg_t *rpg_tab, char *buff)
{
    buff = my_strcat(buff, "\nbody:");
    buff = my_strcat(buff, rpg_tab->g->var->body);
    buff = my_strcat(buff, "\npant:");
    buff = my_strcat(buff, rpg_tab->g->var->pant);
    buff = my_strcat(buff, "\nweapon:");
    buff = my_strcat(buff, my_getstr(rpg_tab->g->perso->weapon));
    buff = my_strcat(buff, "\nnb_mob:");
    buff = my_strcat(buff, my_getstr(rpg_tab->g->nb_mob));
    for (int i = 0; i < 10; i++) {
        buff = my_strcat(buff, "\nx:");
        buff = my_strcat(buff, my_getstr((int)rpg_tab->g->enemy[i]->blop
        ->sprite_pos.x));
        buff = my_strcat(buff, "\ny:");
        buff = my_strcat(buff, my_getstr((int)rpg_tab->g->enemy[i]->blop
        ->sprite_pos.y));
        buff = my_strcat(buff, "\npv:");
        buff = my_strcat(buff, my_getstr((int)rpg_tab->g->enemy[i]->hp));
    }
    buff = my_strcat(buff, "\nx_guy:");
    return (buff);
}

char *create_arr_save_three(rpg_t *rpg_tab, char *buff)
{
    buff = my_strcat(buff, my_getstr(rpg_tab->g->inventory->case_inv[0]
    ->inventory));
    buff = my_strcat(buff, "\nslot_two:");
    buff = my_strcat(buff, my_getstr(rpg_tab->g->inventory->case_inv[1]
    ->inventory));
    buff = my_strcat(buff, "\nslot_three:");
    buff = my_strcat(buff, my_getstr(rpg_tab->g->inventory->case_inv[2]
    ->inventory));
    buff = my_strcat(buff, "\nslot_for:");
    buff = my_strcat(buff, my_getstr(rpg_tab->g->inventory->case_inv[3]
    ->inventory));
    buff = my_strcat(buff, "\nslot_five:");
    buff = my_strcat(buff, my_getstr(rpg_tab->g->inventory->case_inv[4]
    ->inventory));
    buff = my_strcat(buff, "\nslot_six:");
    buff = my_strcat(buff, my_getstr(rpg_tab->g->inventory->case_inv[5]
    ->inventory));
    buff = my_strcat(buff, "\nhelmet:");
    buff = my_strcat(buff, rpg_tab->g->var->helmet);
    return (buff);
}

char *create_arr_save_two(rpg_t *rpg_tab, char *buff)
{
    buff = my_strcpy(buff, "password:");
    buff = my_strcat(buff, rpg_tab->g->log_wind->nocrypt_password);
    buff = my_strcat(buff, "\nskin:");
    buff = my_strcat(buff, rpg_tab->g->var->skin + 26);
    buff = my_strcat(buff, "\nquest:");
    buff = my_strcat(buff, my_getstr(rpg_tab->g->var->quest));
    buff = my_strcat(buff, "\nxp:");
    buff = my_strcat(buff, my_getstr(rpg_tab->g->var->xp));
    buff = my_strcat(buff, "\nhp:");
    buff = my_strcat(buff, my_getstr(rpg_tab->g->var->hp));
    buff = my_strcat(buff, "\nbandage:");
    buff = my_strcat(buff, my_getstr(rpg_tab->g->var->bandage));
    buff = my_strcat(buff, "\ngun_charger:");
    buff = my_strcat(buff, my_getstr(rpg_tab->g->var->gun_charger));
    buff = my_strcat(buff, "\nkatana_dmg:");
    buff = my_strcat(buff, my_getstr(rpg_tab->g->var->katana_dmg));
    buff = my_strcat(buff, "\ngun_dmg:");
    buff = my_strcat(buff, my_getstr(rpg_tab->g->var->gun_dmg));
    buff = my_strcat(buff, "\nslot_one:");
    return (buff);
}

char *create_arr_save(rpg_t *rpg_tab)
{
    char *buff = my_memset_char(50);
    buff = create_arr_save_two(rpg_tab, buff);
    buff = create_arr_save_three(rpg_tab, buff);
    buff = create_arr_save_four(rpg_tab, buff);
    buff = create_arr_save_five(rpg_tab, buff);
    buff = create_arr_save_six(rpg_tab, buff);
    buff = my_strcat(buff, "\nmehdik_qest:");
    buff = my_strcat(buff, my_getstr(rpg_tab->g->mehdik_quest_done));
    return (buff);
}