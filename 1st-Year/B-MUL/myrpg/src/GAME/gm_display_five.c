/*
** EPITECH PROJECT, 2021
** gm_display_three.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void gd_six(rpg_t *rpg_tab)
{
    sfSprite_setTextureRect(rpg_tab->g->stats->hp_bar->sprite,
    rpg_tab->g->stats->hp_bar->sprite_rect);
    sfSprite_setPosition(rpg_tab->g->stats->hp_bar->sprite,
    rpg_tab->g->stats->hp_bar->sprite_pos);
    sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->g->stats->
    hp_bar->sprite, NULL);
    sfSprite_setTextureRect(rpg_tab->g->stats->xp_bar->sprite,
    rpg_tab->g->stats->xp_bar->sprite_rect);
    sfSprite_setPosition(rpg_tab->g->stats->xp_bar->sprite, rpg_tab->
    g->stats->xp_bar->sprite_pos);
    sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->g->stats->
    xp_bar->sprite, NULL);
    sfSprite_setTextureRect(rpg_tab->g->stats->hp_color->sprite,
    rpg_tab->g->stats->hp_color->sprite_rect);
    sfSprite_setPosition(rpg_tab->g->stats->hp_color->sprite, rpg_tab->
    g->stats->hp_color->sprite_pos);
    sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->g->stats->
    hp_color->sprite, NULL);
}

void gd_sv(rpg_t *rpg_tab)
{
    sfSprite_setTextureRect(rpg_tab->g->stats->xp_color->sprite, rpg_tab->
    g->stats->xp_color->sprite_rect);
    sfSprite_setPosition(rpg_tab->g->stats->xp_color->sprite, rpg_tab->g->
    stats->xp_color->sprite_pos);
    sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->g->stats->
    xp_color->sprite, NULL);
    sfText_setString(rpg_tab->g->stats->xp_txt->text,
    rpg_tab->g->stats->xp_txt->ctrl);
    sfRenderWindow_drawText(rpg_tab->window, rpg_tab->g->stats->xp_txt->
    text, NULL);
    sfSprite_setTextureRect(rpg_tab->g->stats->hp_color->sprite, rpg_tab->
    g->stats->hp_color->sprite_rect);
    sfSprite_setPosition(rpg_tab->g->stats->hp_color->sprite, rpg_tab->g->
    stats->hp_color->sprite_pos);
    sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->g->stats->
    hp_color->sprite, NULL);
}

void gd_eight(rpg_t *rpg_tab)
{
    if (rpg_tab->g->var->hp <= 35) {
        animate_text(rpg_tab, rpg_tab->g->stats->hp_txt, 15,
        (int [3]){127, 25, 35});
    } else
        sfText_setColor(rpg_tab->g->stats->hp_txt->text, sfWhite);
    sfText_setString(rpg_tab->g->stats->hp_txt->text,
    rpg_tab->g->stats->hp_txt->ctrl);
    sfRenderWindow_drawText(rpg_tab->window, rpg_tab->g->stats->hp_txt->text,
    NULL);
    if (rpg_tab->g->var->space_bag < 7)
        sfText_setColor(rpg_tab->g->player_info->bag_space->text, sfWhite);
    if (rpg_tab->g->var->space_bag >= 7)
        sfText_setColor(rpg_tab->g->player_info->bag_space->text, sfYellow);
    if (rpg_tab->g->var->space_bag == 9)
        sfText_setColor(rpg_tab->g->player_info->bag_space->text, sfRed);
    if (rpg_tab->g->nb_bullet > 3)
        sfText_setColor(rpg_tab->g->player_info->bullet_charger->text, sfWhite);
    if (rpg_tab->g->nb_bullet <= 3)
        sfText_setColor(rpg_tab->g->player_info->bullet_charger->text,
        sfYellow);
}

void gd_nine(rpg_t *rpg_tab)
{
    if (rpg_tab->g->nb_bullet == 0)
        sfText_setColor(rpg_tab->g->player_info->bullet_charger->text, sfRed);
    sfSprite_setPosition(rpg_tab->g->player_info->bag_icon->sprite,
    rpg_tab->g->player_info->bag_icon->sprite_pos);
    sfText_setPosition(rpg_tab->g->player_info->bag_space->text,
    rpg_tab->g->player_info->bag_space->text_pos);
    sfText_setString(rpg_tab->g->player_info->bag_space->text,
    rpg_tab->g->player_info->bag_space->ctrl);
    sfRenderWindow_drawText(rpg_tab->window, rpg_tab->g->player_info->
    bag_space->text, NULL);
    sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->g->player_info->
    bag_icon->sprite, NULL);
    sfSprite_setPosition(rpg_tab->g->player_info->gun_icon->sprite,
    rpg_tab->g->player_info->gun_icon->sprite_pos);
    sfText_setPosition(rpg_tab->g->player_info->bullet_charger->text,
    rpg_tab->g->player_info->bullet_charger->text_pos);
    sfText_setString(rpg_tab->g->player_info->bullet_charger->text,
    rpg_tab->g->player_info->bullet_charger->ctrl);
    sfRenderWindow_drawText(rpg_tab->window, rpg_tab->g->player_info->
    bullet_charger->text, NULL);
}