/*
** EPITECH PROJECT, 2021
** parse_save.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void update_var_game_zero(rpg_t *rpg_tab, sfVector2f pos_item)
{
    update_var_game_two(rpg_tab);
    update_var_game_three(rpg_tab);
    for (int i = 0; i < 9; i++) {
        update_var_game_four(rpg_tab, i, &pos_item);
        update_var_game_five(rpg_tab, i, &pos_item);
    } update_var_game_six(rpg_tab);
    for (int i = 0, z = 20; i < 10; i++, z += 3) {
        update_var_game_seven(rpg_tab, i, z);
        update_var_game_eight(rpg_tab, i);
    } for (int i = 10, z = 60; i <
    rpg_tab->g->nb_mob;i++, z += 3) {
        update_var_game_nine(rpg_tab, i, z);
        update_var_game_ten(rpg_tab, i, z);
    }
    update_var_game_eleven(rpg_tab);
    update_var_game_twelve(rpg_tab);
}

void update_var_game_twelve(rpg_t *rpg_tab)
{
    rpg_tab->g->stats->hp_txt->ctrl = my_strcpy
    (rpg_tab->g->stats->hp_txt->ctrl, my_getstr(rpg_tab->g->var->hp));
    rpg_tab->g->stats->hp_txt->ctrl = my_strcat
    (rpg_tab->g->stats->hp_txt->ctrl, "HP");
    sfText_setString(rpg_tab->g->stats->hp_txt->text,
    rpg_tab->g->stats->hp_txt->ctrl);
}

void update_var_game_eleven(rpg_t *rpg_tab)
{
    rpg_tab->g->var->cut_dmg = my_getnbr(rpg_tab->m->l_butt->parsing[144]);
    rpg_tab->g->perso->speed = my_getnbr(rpg_tab->m->l_butt->parsing[145]);
    rpg_tab->g->mehdik_quest_done = my_getnbr(rpg_tab->m->l_butt->parsing[146]);
    sfText_setPosition(rpg_tab->g->stats->xp_txt->text,
    (sfVector2f) {rpg_tab->g->stats->xp_bar->sprite_pos.x
    + (rpg_tab->g->stats->xp_bar->sprite_rect.width / 3) + 2,
    rpg_tab->g->stats->xp_bar->sprite_pos.y - 2});
    free(rpg_tab->g->stats->xp_txt->ctrl);
    rpg_tab->g->stats->xp_txt->ctrl = my_memset_char(my_strlen
    (my_getstr(rpg_tab->g->var->xp)) + 5);
    rpg_tab->g->stats->xp_txt->ctrl = my_strcpy
    (rpg_tab->g->stats->xp_txt->ctrl, "LVL.");
    rpg_tab->g->stats->xp_txt->ctrl = my_strcat
    (rpg_tab->g->stats->xp_txt->ctrl, my_getstr(rpg_tab->g->var->xp / 100));
    sfText_setString(rpg_tab->g->stats->xp_txt->text,
    rpg_tab->g->stats->xp_txt->ctrl);
    free(rpg_tab->g->stats->hp_txt->ctrl);
    rpg_tab->g->stats->hp_txt->ctrl = my_memset_char(my_strlen
    (my_getstr(rpg_tab->g->var->hp)) + 6);
}