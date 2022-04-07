/*
** EPITECH PROJECT, 2021
** gm_display_three.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void gm_el(rpg_t *rpg_tab)
{
    if (rpg_tab->g->can_grab == false && rpg_tab->g->can_open_door == false
    && rpg_tab->g->nb_bullet <= 0 && rpg_tab->g->perso->weapon == 2) {
        animate_text(rpg_tab, rpg_tab->g->reload_msg, 15,
        (int [3]){127, 25, 35});
        sfText_setPosition(rpg_tab->g->reload_msg->text,
        sfRenderWindow_mapPixelToCoords
        (rpg_tab->window, (sfVector2i)
        {coeff_window(rpg_tab->window_size.x, 835, 1920),
        coeff_window(rpg_tab->window_size.y, 950, 1080)}, rpg_tab->view));
        sfText_setString(rpg_tab->g->reload_msg->text,
        rpg_tab->g->reload_msg->ctrl);
        sfRenderWindow_drawText(rpg_tab->window,
        rpg_tab->g->reload_msg->text, NULL);
    }
    display_min_map(rpg_tab);
}

void gd_one(rpg_t *rpg_tab)
{
    sfSprite_setTextureRect(rpg_tab->g->inventory->inv_wind->sprite,
    rpg_tab->g->inventory->inv_wind->sprite_rect);
    sfSprite_setPosition(rpg_tab->g->inventory->inv_wind->sprite,
    rpg_tab->g->inventory->inv_wind->sprite_pos);
    sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->g->inventory->
    inv_wind->sprite, NULL);
    sfSprite_setTextureRect(rpg_tab->g->inventory->skin->sprite, rpg_tab->
    g->inventory->skin->sprite_rect);
    sfSprite_setPosition(rpg_tab->g->inventory->skin->sprite, rpg_tab->g->
    inventory->skin->sprite_pos);
    sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->g->inventory->skin->
    sprite, NULL);
    sfSprite_setTextureRect(rpg_tab->g->inventory->stats->hp_bar->sprite,
    rpg_tab->g->inventory->stats->hp_bar->sprite_rect);
    sfSprite_setPosition(rpg_tab->g->inventory->stats->hp_bar->sprite,
    rpg_tab->g->inventory->stats->hp_bar->sprite_pos);
    sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->g->inventory->stats->
    hp_bar->sprite, NULL);
}

void gd_foor(rpg_t *rpg_tab)
{
    sfSprite_setPosition(rpg_tab->g->card->display_digit->sprite,
    rpg_tab->g->card->display_digit->sprite_pos);
    sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->g->card->
    display_digit->sprite, NULL);
    sfText_setString(rpg_tab->g->card->code_door_two->text, rpg_tab->
    g->card->code_door_two->ctrl);
    sfText_setPosition(rpg_tab->g->card->code_door_two->text, rpg_tab->
    g->card->code_door_two->text_pos);
    sfRenderWindow_drawText(rpg_tab->window, rpg_tab->g->card->
    code_door_two->text, NULL);
    for (int i = 0; i < 9; i++) {
        sfSprite_setPosition(rpg_tab->g->card->digit_number[i]->
        sprite, rpg_tab->g->card->digit_number[i]->sprite_pos);
        sfSprite_setTextureRect(rpg_tab->g->card->digit_number[i]->
        sprite, rpg_tab->g->card->digit_number[i]->sprite_rect);
        sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->g->card->
        digit_number[i]->sprite, NULL);
    }
}

void gd_three(rpg_t *rpg_tab)
{
    if (rpg_tab->g->can_open_door == 8081) {
        sfSprite_setTextureRect(rpg_tab->g->card->scanner->sprite,
        rpg_tab->g->card->scanner->sprite_rect);
        sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->g->card->
        scanner->sprite, NULL);
        sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->g->card->
        big_card->sprite, NULL);
    }
    if (rpg_tab->g->can_open_door == 6990) {
        gd_foor(rpg_tab);
    }
}

void gd_two(rpg_t *rpg_tab)
{
    sfSprite_setTextureRect(rpg_tab->g->inventory->stats->xp_bar->sprite,
    rpg_tab->g->inventory->stats->xp_bar->sprite_rect);
    sfSprite_setPosition(rpg_tab->g->inventory->stats->xp_bar->sprite,
    rpg_tab->g->inventory->stats->xp_bar->sprite_pos);
    sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->g->inventory->stats->
    xp_bar->sprite, NULL);
    if (rpg_tab->g->var->hp <= 35) {
        animate_text(rpg_tab, rpg_tab->g->inventory->stats->hp_txt,
        15, (int [3]){127, 25, 35});
    } else {
        sfText_setColor(rpg_tab->g->inventory->stats->hp_txt->text, sfWhite);
    }
    sfText_setString(rpg_tab->g->inventory->stats->xp_txt->text,
    rpg_tab->g->inventory->stats->xp_txt->ctrl);
    sfText_setString(rpg_tab->g->inventory->stats->hp_txt->text,
    rpg_tab->g->inventory->stats->hp_txt->ctrl);
}