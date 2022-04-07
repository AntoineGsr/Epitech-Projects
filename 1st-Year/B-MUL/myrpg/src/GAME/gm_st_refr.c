/*
** EPITECH PROJECT, 2021
** gm_st_refr.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void gm_st_one(rpg_t *rpg_tab)
{
    rpg_tab->g->captain->sprite_frect = (sfFloatRect)
    {363 + 30, 1322 + 50, 45, 35};
    rpg_tab->g->mehdik->sprite_frect = (sfFloatRect)
    {2272 + 30, 1408 + 50, 45, 35};
    rpg_tab->g->mehdik_quest = (sfFloatRect)
    {2247, 1383, 150, 150};
    rpg_tab->g->perso->guy_center = (sfVector2f) {sfSprite_getPosition(rpg_tab
    ->g->perso->guy->sprite).x + 50, sfSprite_getPosition(rpg_tab->g->perso->
    guy->sprite).y + 50};
    rpg_tab->g->perso->guy_hitbox = (sfFloatRect) {rpg_tab->g->perso->guy->
    sprite_pos.x + 30, rpg_tab->g->perso->guy->sprite_pos.y + 50, 45, 35};
    view_stat_handling(rpg_tab);
    rpg_tab->g->stats->hp_bar->sprite_pos = sfRenderWindow_mapPixelToCoords
    (rpg_tab->window, (sfVector2i)
    {coeff_window(rpg_tab->window_size.x, 1625, 1920),
    coeff_window(rpg_tab->window_size.y, 235, 1080)}, rpg_tab->view);
    rpg_tab->g->stats->xp_bar->sprite_pos = (sfVector2f)
    {rpg_tab->g->stats->hp_bar->sprite_pos.x,
    rpg_tab->g->stats->hp_bar->sprite_pos.y + 45};
}

void gm_st_two(rpg_t *rpg_tab)
{
    rpg_tab->g->stats->hp_color->sprite_pos = (sfVector2f)
    {rpg_tab->g->stats->hp_bar->sprite_pos.x + 10,
    rpg_tab->g->stats->hp_bar->sprite_pos.y};
    rpg_tab->g->stats->xp_color->sprite_pos = (sfVector2f)
    {rpg_tab->g->stats->xp_bar->sprite_pos.x + 10,
    rpg_tab->g->stats->xp_bar->sprite_pos.y};
    rpg_tab->g->stats->xp_color->sprite_rect.width =
    ((float) (rpg_tab->g->var->xp % 100) / 100.0) * 223;
    sfText_setPosition(rpg_tab->g->stats->xp_txt->text,
    (sfVector2f) {rpg_tab->g->stats->xp_bar->sprite_pos.x
    + (rpg_tab->g->stats->xp_bar->sprite_rect.width / 3) + 2,
    rpg_tab->g->stats->xp_bar->sprite_pos.y - 2});
    if (rpg_tab->g->var->hp < 0)
        rpg_tab->g->var->hp = 0;
}

void gm_st_three(rpg_t *rpg_tab)
{
    rpg_tab->g->stats->hp_color->sprite_rect.width =
    ((float) (rpg_tab->g->var->hp) / 100.0) * 223;
    sfText_setPosition(rpg_tab->g->stats->hp_txt->text,
    (sfVector2f) {rpg_tab->g->stats->hp_bar->sprite_pos.x
    + (rpg_tab->g->stats->hp_bar->sprite_rect.width / 3) + 2,
    rpg_tab->g->stats->hp_bar->sprite_pos.y - 2});
    if (rpg_tab->g->var->xp / 100 > rpg_tab->g->var->previous_xp / 100) {
        free(rpg_tab->g->stats->xp_txt->ctrl);
        rpg_tab->g->stats->xp_txt->ctrl = my_memset_char(my_strlen
        (my_getstr(rpg_tab->g->var->xp)) + 5);
        rpg_tab->g->stats->xp_txt->ctrl = my_strcpy
        (rpg_tab->g->stats->xp_txt->ctrl, "LVL.");
        rpg_tab->g->stats->xp_txt->ctrl = my_strcat
        (rpg_tab->g->stats->xp_txt->ctrl,
        my_getstr(rpg_tab->g->var->xp / 100));
        rpg_tab->g->var->gun_dmg += 2;
        rpg_tab->g->var->cut_dmg += 4;
        rpg_tab->g->perso->speed += 30;
    }
}

void gm_st_foor(rpg_t *rpg_tab)
{
    if (rpg_tab->g->var->hp != rpg_tab->g->var->previous_hp) {
        free(rpg_tab->g->stats->hp_txt->ctrl);
        rpg_tab->g->stats->hp_txt->ctrl = my_memset_char(my_strlen
        (my_getstr(rpg_tab->g->var->hp)) + 6);
        rpg_tab->g->stats->hp_txt->ctrl = my_strcpy
        (rpg_tab->g->stats->hp_txt->ctrl, my_getstr(rpg_tab->g->var->hp));
        rpg_tab->g->stats->hp_txt->ctrl = my_strcat
        (rpg_tab->g->stats->hp_txt->ctrl, "HP");
    }
    rpg_tab->g->player_info->bag_icon->sprite_pos =
    sfRenderWindow_mapPixelToCoords(rpg_tab->window,
    (sfVector2i){coeff_window(rpg_tab->window_size.x, 1740, 1920),
    coeff_window(rpg_tab->window_size.y, 320, 1080)}, rpg_tab->view);
    rpg_tab->g->player_info->bag_space->text_pos = (sfVector2f){rpg_tab->g->
    player_info->bag_icon->sprite_pos.x + coeff_window(rpg_tab->window_size.x,
    55, 1920), rpg_tab->g->player_info->bag_icon->sprite_pos.y};
}

void game_stat_refresh(rpg_t *rpg_tab)
{
    gm_st_one(rpg_tab);
    gm_st_two(rpg_tab);
    gm_st_three(rpg_tab);
    gm_st_foor(rpg_tab);
    if (rpg_tab->g->var->space_bag != rpg_tab->g->var->previous_space_bag) {
        rpg_tab->g->player_info->bag_space->ctrl[0] = rpg_tab->g->var->
        space_bag + '0';
    }
    rpg_tab->g->player_info->gun_icon->sprite_pos =
    sfRenderWindow_mapPixelToCoords(rpg_tab->window,
    (sfVector2i){coeff_window(rpg_tab->window_size.x, 1740, 1920),
    coeff_window(rpg_tab->window_size.y, 360, 1080)}, rpg_tab->view);
    rpg_tab->g->player_info->bullet_charger->text_pos =
    (sfVector2f){rpg_tab->g->player_info->gun_icon->sprite_pos.x +
    coeff_window(rpg_tab->window_size.x, 55, 1920), rpg_tab->g->
    player_info->gun_icon->sprite_pos.y};
    if (rpg_tab->g->nb_bullet != rpg_tab->g->var->previous_gun_charger) {
        rpg_tab->g->player_info->bullet_charger->ctrl[0] =
        rpg_tab->g->nb_bullet + '0';
    }
}